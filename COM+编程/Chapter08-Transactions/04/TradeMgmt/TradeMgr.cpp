// TradeMgr.cpp : Implementation of CTradeMgmtApp and DLL registration.

#include "stdafx.h"
#include "TradeMgmt.h"
#include "TradeMgr.h"
#include <comsvcs.h>

#import "..\StockExchange\StockExchange.tlb"
using namespace STOCKEXCHANGELib;

#import "..\AccountMgmt\AccountMgmt.tlb"
using namespace ACCOUNTMGMTLib;

#define CHECKHR(hr) \
   { if (FAILED(hr)) _com_issue_error(hr ); }

/////////////////////////////////////////////////////////////////////////////
//
CTradeMgr::CTradeMgr()
{
}

CTradeMgr::~CTradeMgr()
{
}

STDMETHODIMP CTradeMgr::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ITradeMgr,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT
CpCreateRemoteInstance(
   LPCOLESTR pwszMach,
   const CLSID& clsId,
   IUnknown** ppOut
   )
{
	*ppOut = NULL;

	COSERVERINFO serverInfo;
	serverInfo.dwReserved1 = 0;
	serverInfo.pwszName = const_cast<LPOLESTR>(pwszMach);
	serverInfo.pAuthInfo = NULL;
	serverInfo.dwReserved2 = 0;

	MULTI_QI mqiEntry;
	mqiEntry.pIID = &IID_IUnknown;
	mqiEntry.pItf = NULL;
	mqiEntry.hr = 0;

	HRESULT hr = CoCreateInstanceEx(clsId,
		NULL,
		CLSCTX_REMOTE_SERVER,
		&serverInfo,
		1,
		&mqiEntry);

	if (FAILED(hr)) {
	   return hr;
	}

	_ASSERT (NULL != mqiEntry.pItf);
	*ppOut = mqiEntry.pItf;
	
	return hr;
}

STDMETHODIMP CTradeMgr::BuyStocks(BSTR bsClient, BSTR bsSymbol, long lShares)
{
	CComPtr<IContextState> spState;
	HRESULT hr = ::CoGetObjectContext(__uuidof(IContextState), (void**) &spState);
	if (FAILED(hr)) {
		return hr;
	}
	hr = spState->SetDeactivateOnReturn(VARIANT_TRUE);
	_ASSERT (SUCCEEDED(hr));

	try {
		//
		// First operation - Obtain the stocks.
		//
		IStockMgrPtr spStockMgr(__uuidof(StockMgr));
		long lAmount = spStockMgr->BuyStock(bsSymbol, lShares);
		
		//
		// Second operation - Debit the clien't account balance
		//
		IAccountMgrPtr spAccountMgr(__uuidof(AccountMgr));
		spAccountMgr->Debit(bsClient, lAmount);
	}catch(_com_error& e) {
		spState->SetMyTransactionVote(TxAbort);
		return Error(static_cast<LPCTSTR>(e.Description()), GUID_NULL, e.Error());
	}

	spState->SetMyTransactionVote(TxCommit);
	return S_OK;
}
