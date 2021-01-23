// 04.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "mqoa.dll" no_namespace

int DisplayUsage()
{
	::MessageBox(NULL, 
		_T("Usage:\n"
		   "QueueTest.exe -s to send a message\n"
		   "QueueTest.exe -r to receive a message"), NULL, MB_OK);
	return 1;
}

void SendMessage();
void ReceiveMessage();

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	if (__argc != 2) {
		return DisplayUsage();
	}

	bool bSend;
	if (!_tcsicmp(__argv[1], "-s")) {
		bSend = true;
	}else
	if (!_tcsicmp(__argv[1], "-r")) {
		bSend = false;
	}else {
		return DisplayUsage();
	}

 	CCPLComInitializer comInit;

	try {
		if (true == bSend) {
			SendMessage();
		}else {
			ReceiveMessage();
		}
	}catch(_com_error& e) {
		::MessageBoxW(NULL, CPLGetError(e), L"Error", MB_OK);
	}

	return 0;
}

#define MY_QUEUE_PATHNAME "ROS84157LAP\\MyPubQueue"
#define MY_RESPONSE_QUEUE_PATHNAME ".\\Private$\\MyResponseQueue"

void SendMessage()
{
	// Step 1: Set properties on queue-information object
	IMSMQQueueInfoPtr spQInfo("MSMQ.MSMQQueueInfo");
	spQInfo->PathName = MY_QUEUE_PATHNAME;
	spQInfo->Refresh();
	::MessageBox(NULL, spQInfo->FormatName, _T("Format Name"), MB_OK);

	// Step 2: Open the queue for send operation
	IMSMQQueuePtr spQSend = spQInfo->Open(MQ_SEND_ACCESS, MQ_DENY_NONE);

	// Step 3: Set response queue information
	IMSMQQueueInfoPtr spResponseQInfo("MSMQ.MSMQQueueInfo");
	spResponseQInfo->PathName = MY_RESPONSE_QUEUE_PATHNAME;

	// Step 4: Set message-information properties
	IMSMQMessagePtr spQMsg("MSMQ.MSMQMessage");
	spQMsg->Label = "Need product of two numbers";
	spQMsg->Body = "2 5";
	spQMsg->Delivery = MQMSG_DELIVERY_RECOVERABLE;
	spQMsg->ResponseQueueInfo = spResponseQInfo;

	// Step 5: Send the message on the queue
	spQMsg->Send(spQSend);

	// Step 6: Close the queue
	spQSend->Close();

	::MessageBox(NULL, _T("Message Sent"), _T("Test Send Message"), MB_OK);
}

void ReceiveMessage()
{
	// Step 1: Set properties on queue-information object
	IMSMQQueueInfoPtr spQInfo("MSMQ.MSMQQueueInfo");
	spQInfo->PathName = MY_QUEUE_PATHNAME;

	// Step 2: Open the queue for receive operation
	IMSMQQueuePtr spQRec = spQInfo->Open(MQ_RECEIVE_ACCESS, MQ_DENY_NONE);

	// Step 3: Attempt to receive a message for one second
	_variant_t vtReceiveTimeout = 1000L;
	IMSMQMessagePtr spRMsg = spQRec->Receive(&vtMissing, &vtMissing, &vtMissing, &vtReceiveTimeout);

	if (NULL == spRMsg) {
		::MessageBox(NULL, _T("No messages found"), _T("Test Receive Message"), MB_OK);
		return;
	}

	// Step 4: Process the message body
	_bstr_t bsBody = spRMsg->Body;
	int nVal1, nVal2;
	_stscanf(bsBody, _T("%d %d"), &nVal1, &nVal2);
	int nProduct = nVal1 * nVal2;

	// Step 5: Prepare a new message
	IMSMQMessagePtr spResponseMsg("MSMQ.MSMQMessage");
	spResponseMsg->Label = "Returned value";
	spResponseMsg->Body = (long) nProduct;
	spResponseMsg->CorrelationId = spRMsg->Id;

	// Step 5: Open the response queue
	IMSMQQueuePtr spResponseQ = 
		spRMsg->ResponseQueueInfo->Open(MQ_SEND_ACCESS, MQ_DENY_NONE);

	// Step 6: Send the response
	spResponseMsg->Send(spResponseQ);

	::MessageBox(NULL, _T("Response Sent"), _T("Response Message"), MB_OK);
}

