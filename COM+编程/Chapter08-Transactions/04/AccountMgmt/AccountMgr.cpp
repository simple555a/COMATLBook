// AccountMgr.cpp : Implementation of CAccountMgmtApp and DLL registration.

#include "StdAfx.h"
#include "AccountMgmt.h"
#include "AccountMgr.h"
#import "../TextFileDB/TextFileDB.tlb" no_namespace

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

STDMETHODIMP CAccountMgr::Debit(BSTR bsClient, long lAmount)
{
	CComPtr<IContextState> spState;
	HRESULT hr = ::CoGetObjectContext(__uuidof(IContextState), (void**) &spState);
	if (FAILED(hr)) {
		return hr;
	}

	try {
		IMyFileDBPtr spConn(__uuidof(MyFileDB));
		spConn->Open("W:/Dev/Chapter08-Transactions/04/TextFileDB/Test/Accounts.txt");
		long lCurrentBalance = spConn->GetBalance(bsClient);
		if (lCurrentBalance < lAmount) {
			spState->SetMyTransactionVote(TxAbort);
			return Error(_T("Not enough balance"), GUID_NULL, E_FAIL);
		}
		long lNewBalance = lCurrentBalance - lAmount;
		spConn->UpdateBalance(bsClient, lNewBalance);
	}
	catch(_com_error& e) {
		spState->SetMyTransactionVote(TxAbort);
		return Error(static_cast<LPCTSTR>(e.Description()), GUID_NULL, e.Error());
	}

	spState->SetMyTransactionVote(TxCommit);
	return S_OK;
}

