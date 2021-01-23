// MyListener.cpp : Implementation of CListenerApp and DLL registration.

#include "stdafx.h"
#include "Listener.h"
#include "MyListener.h"
#import "mqoa.dll" no_namespace
#import "msxml.dll"

#define MY_TRANS_QUEUE_PATHNAME "DIRECT=OS:.\\Private$\\MyTransPrivQueue"
#define MY_TRANS_RESPONSE_QUEUE_PATHNAME ".\\Private$\\MyTransResponseQueue"

#define MSMQ_BUG_FIXED

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyListener::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyListener,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

ADOConnectionPtr OpenAccountsDB()
{
	ADOConnectionPtr spConn;
	HRESULT hr = spConn.CreateInstance(__uuidof(ADODB::Connection));
	CHECKHR(hr);

	_bstr_t bsDSN = "provider=sqloledb;database=AccountsDB";
	_bstr_t bsUser = "sa";
	hr = spConn->Open (bsDSN, bsUser, (LPCTSTR) NULL, NULL);
	CHECKHR(hr);
	return spConn;
}

long GetBalance(ADOConnectionPtr spConn, BSTR bsClient)
{
	ADORecordsetPtr spRS;
	HRESULT hr = spRS.CreateInstance(__uuidof(ADODB::Recordset));
	CHECKHR(hr);

	TCHAR buf[256];
	_stprintf(buf, _T("SELECT * FROM Accounts WHERE [client] = '%S'"), 
		(LPCWSTR) bsClient);

	_variant_t vConn = static_cast<IDispatch*>(spConn);
	hr = spRS->Open(buf, vConn, ADODB::adOpenKeyset, 
		ADODB::adLockPessimistic, ADODB::adCmdText);
	CHECKHR(hr);

	return spRS->Fields->Item["Balance"]->Value;
}

void UpdateBalance(ADOConnectionPtr spConn, BSTR bsClient, long lBalance)
{
	TCHAR buf[256];
	_stprintf(buf, _T("UPDATE Accounts SET Balance = %ld WHERE [client] = '%S'"), 
		lBalance, (LPCWSTR) bsClient);

	_variant_t vRecordCount;
	spConn->Execute(buf, &vRecordCount,-1);
}

#ifdef MSMQ_BUG_FIXED
void ParseXMLInput(MSXML::IXMLDOMDocumentPtr spDoc, _bstr_t& bsUser, long& lAmount)
{
#else
void ParseXMLInput(_bstr_t& bsUser, long& lAmount)
{
	MSXML::IXMLDOMDocumentPtr spDoc(__uuidof(MSXML::DOMDocument));
	spDoc->load("MyAccount.xml");
#endif

	MSXML::IXMLDOMElementPtr spRoot = spDoc->firstChild;

	MSXML::IXMLDOMElementPtr spUserNode = spRoot->selectSingleNode("User");
	bsUser = spUserNode->nodeTypedValue;

	MSXML::IXMLDOMElementPtr spAmountChild = spRoot->selectSingleNode("Amount");
	lAmount = spAmountChild->nodeTypedValue;
}

STDMETHODIMP CMyListener::Listen()
{
	// Get the context state
	CComPtr<IContextState> spState;
	HRESULT hr = ::CoGetObjectContext(__uuidof(IContextState), (void**) &spState);
	if (FAILED(hr)) {
		return hr;
	}

	// Listen/retrive a message
	try {
		hr = ListenEx();
		if (FAILED(hr)) {
			spState->SetMyTransactionVote(TxAbort);
			return hr;
		}
	}catch(_com_error& e) {
		spState->SetMyTransactionVote(TxAbort);
		return Error((LPWSTR) e.Description(), __uuidof(IMyListener), e.Error());
	}

	// Commit the transaction
	spState->SetMyTransactionVote(TxCommit);
	return S_OK;
}


HRESULT CMyListener::ListenEx()
{
	// Step 2: Set properties on queue-information object
	IMSMQQueueInfoPtr spQInfo(__uuidof(MSMQQueueInfo));
	spQInfo->FormatName = MY_TRANS_QUEUE_PATHNAME;

	// Step 3: Open the queue for receive operation
	IMSMQQueuePtr spQRec = spQInfo->Open(MQ_RECEIVE_ACCESS, MQ_DENY_NONE);

	// Step 4: Attempt to receive a message for one second
	_variant_t vtTransaction = (long) MQ_MTS_TRANSACTION;
	_variant_t vtReceiveTimeout = 1000L;
	IMSMQMessagePtr spRMsg = spQRec->Receive(&vtTransaction, &vtMissing, &vtMissing, &vtReceiveTimeout);

	if (NULL == spRMsg) {
		return Error(OLESTR("No messages found"), __uuidof(IMyListener), E_FAIL);
	}

	// Step 5: Process the message body
	_bstr_t bsClient;
	long lAmount;
#ifdef MSMQ_BUG_FIXED
	ParseXMLInput(spRMsg->Body, bsClient, lAmount);
#else
	ParseXMLInput(bsClient, lAmount);
#endif

	// Step 6: Open and update the database
	ADOConnectionPtr spConn = OpenAccountsDB();
	long lCurrentBalance = GetBalance(spConn, bsClient);
	if (lCurrentBalance < lAmount) {
		return Error(_T("Not enough balance"), __uuidof(IMyListener), E_FAIL);
	}
	long lNewBalance = lCurrentBalance - lAmount;
	UpdateBalance(spConn, bsClient, lNewBalance);

	// Step 7: Prepare a response message
	IMSMQMessagePtr spResponseMsg(__uuidof(MSMQMessage));
	spResponseMsg->Label = "Updated the database";
	spResponseMsg->Body = VARIANT_TRUE;
	spResponseMsg->CorrelationId = spRMsg->Id;

	// Step 8: Open the response queue
	IMSMQQueuePtr spResponseQ = 
		spRMsg->ResponseQueueInfo->Open(MQ_SEND_ACCESS, MQ_DENY_NONE);

	// Step 8: Send the response
	spResponseMsg->Send(spResponseQ, &vtTransaction);

	return S_OK;
}

MSXML::IXMLDOMDocumentPtr CreateXMLDOcument()
{
	MSXML::IXMLDOMDocumentPtr spDoc(__uuidof(MSXML::DOMDocument));
	spDoc->load("MyAccount.xml");
	return spDoc;
}

void SendMessage()
{
	// Step 1: Set properties on queue-information object
	IMSMQQueueInfoPtr spQInfo(__uuidof(MSMQQueueInfo));
	spQInfo->FormatName = MY_TRANS_QUEUE_PATHNAME;

	// Step 2: Open the queue for send operation
	IMSMQQueuePtr spQSend = spQInfo->Open(MQ_SEND_ACCESS, MQ_DENY_NONE);

	// Step 3: Set response queue information
	IMSMQQueueInfoPtr spResponseQInfo(__uuidof(MSMQQueueInfo));
	spResponseQInfo->PathName = MY_TRANS_RESPONSE_QUEUE_PATHNAME;

	// Step 4: Set message-information properties
	IMSMQMessagePtr spQMsg(__uuidof(MSMQMessage));
	spQMsg->Label = "Debit client's account";
	spQMsg->Body = _variant_t(static_cast<IUnknown*>(CreateXMLDOcument()));
	spQMsg->ResponseQueueInfo = spResponseQInfo;

	// Step 5: Send the message on the queue
	_variant_t vtTransaction = (long) MQ_SINGLE_MESSAGE;
	spQMsg->Send(spQSend, &vtTransaction);

	// Step 6: Close the queue
	spQSend->Close();
}

STDMETHODIMP CMyListener::Send()
{
	try {
		SendMessage();
	}catch(_com_error& e) {
		return Error((LPWSTR) e.Description(), __uuidof(IMyListener), e.Error());
	}
	return S_OK;
}
