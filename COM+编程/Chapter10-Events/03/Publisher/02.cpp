// 02.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "mqoa.dll" no_namespace

int DisplayUsage()
{
	::MessageBox(NULL, 
		_T("Sending message:\n"
		   "QueueTest.exe msgtext"), NULL, MB_OK);
	return 1;
}

void SendMessage(LPCTSTR pszMsg);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	if (__argc != 2) {
		return DisplayUsage();
	}

 	CCPLComInitializer comInit;

	try {
		SendMessage(__argv[1]);
	}catch(_com_error& e) {
		::MessageBoxW(NULL, CPLGetError(e), L"Error", MB_OK);
	}

	return 0;
}

#define MY_QUEUE_PATHNAME ".\\MyPubQueue"

void SendMessage(LPCTSTR pszMsg)
{
	// Step 1: Set properties on queue-information object
	IMSMQQueueInfoPtr spQInfo("MSMQ.MSMQQueueInfo");
	spQInfo->PathName = MY_QUEUE_PATHNAME;

	// Step 2: Open the queue for send operation
	IMSMQQueuePtr spQSend = spQInfo->Open(MQ_SEND_ACCESS, MQ_DENY_NONE);

	// Step 3: Set message-information properties
	IMSMQMessagePtr spQMsg("MSMQ.MSMQMessage");
	spQMsg->Label = "Test Message";
	spQMsg->Body = pszMsg;

	// Step 4: Send the message on the queue
	spQMsg->Send(spQSend);

	// Step 5: Close the queue
	spQSend->Close();

	::MessageBox(NULL, pszMsg, _T("Message Sent"), MB_OK);
}
