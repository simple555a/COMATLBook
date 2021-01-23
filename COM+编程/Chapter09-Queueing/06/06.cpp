// 06.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "mqoa.dll" no_namespace
#import "msxml.dll"

// #define MSMQ_BUG_FIXED

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


MSXML::IXMLDOMDocumentPtr CreateXMLDOcument()
{
	MSXML::IXMLDOMDocumentPtr spDoc(__uuidof(MSXML::DOMDocument));
	spDoc->load("MyInput.xml");
	return spDoc;
}

#define MY_TRANS_QUEUE_PATHNAME ".\\Private$\\MyTransSendQueue"
#define MY_TRANS_RESPONSE_QUEUE_PATHNAME ".\\Private$\\MyTransResponseQueue"

void SendMessage()
{
	// Step 1: Set properties on queue-information object
	IMSMQQueueInfoPtr spQInfo("MSMQ.MSMQQueueInfo");
	spQInfo->PathName = MY_TRANS_QUEUE_PATHNAME;

	// Step 2: Open the queue for send operation
	IMSMQQueuePtr spQSend = spQInfo->Open(MQ_SEND_ACCESS, MQ_DENY_NONE);

	// Step 3: Set response queue information
	IMSMQQueueInfoPtr spResponseQInfo("MSMQ.MSMQQueueInfo");
	spResponseQInfo->PathName = MY_TRANS_RESPONSE_QUEUE_PATHNAME;

	// Step 4: Set message-information properties
	IMSMQMessagePtr spQMsg("MSMQ.MSMQMessage");
	spQMsg->Label = "Need product of two numbers";
	spQMsg->Body = _variant_t(static_cast<IUnknown*>(CreateXMLDOcument()));
	spQMsg->ResponseQueueInfo = spResponseQInfo;

	// Step 5: Send the message on the queue
	_variant_t vtTransaction = (long) MQ_SINGLE_MESSAGE;
	spQMsg->Send(spQSend, &vtTransaction);

	// Step 6: Close the queue
	spQSend->Close();

	::MessageBox(NULL, _T("Message Sent"), _T("Test Send Message"), MB_OK);
}
#ifdef MSMQ_BUG_FIXED
int ComputeProduct(MSXML::IXMLDOMDocumentPtr spDoc)
{
#else
int ComputeProduct()
{
	MSXML::IXMLDOMDocumentPtr spDoc(__uuidof(MSXML::DOMDocument));
	spDoc->load("MyInput.xml");
#endif

	MSXML::IXMLDOMElementPtr spRoot = spDoc->firstChild;

	MSXML::IXMLDOMElementPtr spFirstChild = spRoot->selectSingleNode("First");
	long nVal1 = spFirstChild->nodeTypedValue;

	MSXML::IXMLDOMElementPtr spSecondChild = spRoot->selectSingleNode("Second");
	long nVal2 = spSecondChild->nodeTypedValue;

	return nVal1 * nVal2;
}

void ReceiveMessage()
{
	// Step 1: Set properties on queue-information object
	IMSMQQueueInfoPtr spQInfo("MSMQ.MSMQQueueInfo");
	spQInfo->PathName = MY_TRANS_QUEUE_PATHNAME;

	// Step 2: Open the queue for receive operation
	IMSMQQueuePtr spQRec = spQInfo->Open(MQ_RECEIVE_ACCESS, MQ_DENY_NONE);

	// Step 3: Start the transaction
	IMSMQTransactionDispenserPtr spTD("MSMQ.MSMQTransactionDispenser");
	IMSMQTransactionPtr spTransaction = spTD->BeginTransaction();
	// _variant_t vtTransaction = static_cast<IUnknown*>(spTransaction); // DO NOT USE IUNKNOWN - MSMQ BUG
	_variant_t vtTransaction = static_cast<IDispatch*>(spTransaction);
	
	// Step 4: Attempt to receive a message for one second
	_variant_t vtReceiveTimeout = 1000L;
	IMSMQMessagePtr spRMsg = spQRec->Receive(&vtTransaction, &vtMissing, &vtMissing, &vtReceiveTimeout);

	if (NULL == spRMsg) {
		::MessageBox(NULL, _T("No messages found"), _T("Test Receive Message"), MB_OK);
		return;
	}

	// Step 5: Process the message body
#ifdef MSMQ_BUG_FIXED
	int nProduct = ComputeProduct(spRMsg->Body);
#else
	int nProduct = ComputeProduct();
#endif
	// Step 6: Prepare two response messages
	IMSMQMessagePtr spResponseMsg1("MSMQ.MSMQMessage");
	spResponseMsg1->Label = "Returned value 1";
	spResponseMsg1->Body = (long) nProduct;
	spResponseMsg1->CorrelationId = spRMsg->Id;

	IMSMQMessagePtr spResponseMsg2("MSMQ.MSMQMessage");
	spResponseMsg2->Label = "Returned value 2";
	spResponseMsg2->Body = (long) nProduct;
	spResponseMsg2->CorrelationId = spRMsg->Id;

	// Step 7: Open the response queue
	IMSMQQueuePtr spResponseQ = 
		spRMsg->ResponseQueueInfo->Open(MQ_SEND_ACCESS, MQ_DENY_NONE);

	// Step 8: Send the responses
	spResponseMsg1->Send(spResponseQ, &vtTransaction);
	spResponseMsg2->Send(spResponseQ, &vtTransaction);

	// Step 9: Commit the transaction
	spTransaction->Commit();

	::MessageBox(NULL, _T("Response Sent"), _T("Response Message"), MB_OK);
}

