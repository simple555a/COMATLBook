// 03.cpp : Defines the entry point for the application.
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
void SendMessage()
{
	// Step 1: Set properties on queue-information object
	IMSMQQueueInfoPtr spQInfo("MSMQ.MSMQQueueInfo");
	spQInfo->PathName = MY_QUEUE_PATHNAME;
	spQInfo->Refresh();
	::MessageBox(NULL, spQInfo->FormatName, _T("Format Name"), MB_OK);

	// Step 2: Open the queue for send operation
	IMSMQQueuePtr spQSend = spQInfo->Open(MQ_SEND_ACCESS, MQ_DENY_NONE);

	// Step 3: Set message-information properties
	IMSMQMessagePtr spQMsg("MSMQ.MSMQMessage");
	spQMsg->Label = "Test Message";
	spQMsg->Body = "This is my test message";
	spQMsg->Delivery = MQMSG_DELIVERY_RECOVERABLE;

	// Step 4: Send the message on the queue
	spQMsg->Send(spQSend);

	// Step 5: Close the queue
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

	// Step 4: Retrieve the message body and label
	if (NULL != spRMsg) {
		_bstr_t bsBody = spRMsg->Body;
		_bstr_t bsLabel = spRMsg->Label;
		::MessageBox(NULL, bsBody, bsLabel, MB_OK);
	}else {
		::MessageBox(NULL, _T("No messages found"), _T("Test Receive Message"), MB_OK);
	}

	// Step 5: Close the queue
	spQRec->Close();
}

