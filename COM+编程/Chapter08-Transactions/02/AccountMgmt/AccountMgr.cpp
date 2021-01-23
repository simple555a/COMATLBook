// AccountMgr.cpp : Implementation of CAccountMgmtApp and DLL registration.

#include "StdAfx.h"
#include "AccountMgmt.h"
#include "AccountMgr.h"
#include <ComSvcs.h>

CAccountMgr::CAccountMgr()
{

}

CAccountMgr::~CAccountMgr()
{

}

STDMETHODIMP CAccountMgr::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IAccountMgr,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

ADOConnectionPtr CAccountMgr::OpenAccountsDB()
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

long CAccountMgr::GetBalance(ADOConnectionPtr spConn, BSTR bsClient)
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

void CAccountMgr::UpdateBalance(ADOConnectionPtr spConn, BSTR bsClient, long lBalance)
{
	TCHAR buf[256];
	_stprintf(buf, _T("UPDATE Accounts SET Balance = %ld WHERE [client] = '%S'"), 
		lBalance, (LPCWSTR) bsClient);

	_variant_t vRecordCount;
	spConn->Execute(buf, &vRecordCount,-1);
}

STDMETHODIMP CAccountMgr::Debit(BSTR bsClient, long lAmount)
{
	CComPtr<IContextState> spState;
	HRESULT hr = ::CoGetObjectContext(__uuidof(IContextState), (void**) &spState);
	if (FAILED(hr)) {
		return hr;
	}

	try {
		ADOConnectionPtr spConn = OpenAccountsDB();
		long lCurrentBalance = GetBalance(spConn, bsClient);
		if (lCurrentBalance < lAmount) {
			spState->SetMyTransactionVote(TxAbort);
			return Error(_T("Not enough balance"), GUID_NULL, E_FAIL);
		}
		long lNewBalance = lCurrentBalance - lAmount;
		UpdateBalance(spConn, bsClient, lNewBalance);
	}
	catch(_com_error& e) {
		spState->SetMyTransactionVote(TxAbort);
		return Error(static_cast<LPCTSTR>(e.Description()), GUID_NULL, e.Error());
	}

	spState->SetMyTransactionVote(TxCommit);
	return S_OK;
}

