// StockMgr.h: Definition of the CStockMgr class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STOCKMGR_H__016AFCE6_15E5_4BB6_8111_0C4FE9731565__INCLUDED_)
#define AFX_STOCKMGR_H__016AFCE6_15E5_4BB6_8111_0C4FE9731565__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStockMgr

class CStockMgr : 
	public IDispatchImpl<IStockMgr, &IID_IStockMgr, &LIBID_STOCKEXCHANGELib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CStockMgr,&CLSID_StockMgr>
{
public:
	CStockMgr();
	~CStockMgr();

BEGIN_COM_MAP(CStockMgr)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IStockMgr)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CStockMgr) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_StockMgr)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IStockMgr
public:
	STDMETHOD(BuyStock)(/*[in]*/ BSTR bsSymbol, /*[in]*/ long lShares, /*[out, retval]*/ long* plValue);

private:
	ADOConnectionPtr OpenStocksDB();
	void GetStockInfo(ADOConnectionPtr spConn, BSTR bsSymbol,
		long& lAvailableShares, long& lMarketPrice);
	void UpdateAvailableShares(ADOConnectionPtr spConn, 
		BSTR bsSymbol, long lShares);

};

#endif // !defined(AFX_STOCKMGR_H__016AFCE6_15E5_4BB6_8111_0C4FE9731565__INCLUDED_)
