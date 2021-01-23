// StockMgr.cpp : Implementation of CStockExchangeApp and DLL registration.

#include "stdafx.h"
#include "StockExchange.h"
#include "StockMgr.h"

/////////////////////////////////////////////////////////////////////////////
//

CStockMgr::CStockMgr()
{
}

CStockMgr::~CStockMgr()
{
}

STDMETHODIMP CStockMgr::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IStockMgr,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

ADOConnectionPtr CStockMgr::OpenStocksDB()
{
	ADOConnectionPtr spConn;
	HRESULT hr = spConn.CreateInstance(__uuidof(ADODB::Connection));
	CHECKHR(hr);

	_bstr_t bsDSN = "provider=sqloledb;database=StocksDB";
	_bstr_t bsUser = "sa";
	hr = spConn->Open (bsDSN, bsUser, (LPCTSTR) NULL, NULL);
	CHECKHR(hr);
	return spConn;
}

void CStockMgr::GetStockInfo(ADOConnectionPtr spConn, BSTR bsSymbol,
		long& lAvailableShares, long& lMarketPrice)
{
	ADORecordsetPtr spRS;
	HRESULT hr = spRS.CreateInstance(__uuidof(ADODB::Recordset));
	CHECKHR(hr);

	TCHAR buf[256];
	_stprintf(buf, _T("SELECT * FROM Stocks WHERE [Symbol] = '%S'"), 
		(LPCWSTR) bsSymbol);

	_variant_t vConn = static_cast<IDispatch*>(spConn);
	hr = spRS->Open(buf, vConn, ADODB::adOpenKeyset, 
		ADODB::adLockPessimistic, ADODB::adCmdText);
	CHECKHR(hr);

	lAvailableShares = spRS->Fields->Item["Shares"]->Value;
	lMarketPrice = spRS->Fields->Item["MarketPrice"]->Value;
}

void CStockMgr::UpdateAvailableShares(ADOConnectionPtr spConn, 
									  BSTR bsSymbol, long lShares)
{
	TCHAR buf[256];
	_stprintf(buf, _T("UPDATE Stocks SET Shares = %ld WHERE [Symbol] = '%S'"), 
		lShares, (LPCWSTR) bsSymbol);

	_variant_t vRecordCount;
	spConn->Execute(buf, &vRecordCount,-1);
}

STDMETHODIMP CStockMgr::BuyStock(BSTR bsSymbol, long lRequestedShares, long *plValue)
{
	try {
		ADOConnectionPtr spConn = OpenStocksDB();

		long lAvailableShares, lMarketPrice;
		GetStockInfo(spConn, bsSymbol, lAvailableShares, lMarketPrice);
		if( lAvailableShares < lRequestedShares) {
			return Error(_T("Not enough shares"), GUID_NULL, E_FAIL);
		}
		// Reduce the available number of shares
		lAvailableShares -= lRequestedShares;
		UpdateAvailableShares(spConn, bsSymbol, lAvailableShares);
		*plValue = lRequestedShares * lMarketPrice;
	}
	catch(_com_error& e) {
		return Error(static_cast<LPCTSTR>(e.Description()), GUID_NULL, E_FAIL);
	}

	return S_OK;
}
