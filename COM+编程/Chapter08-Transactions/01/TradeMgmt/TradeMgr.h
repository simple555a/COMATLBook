// TradeMgr.h: Definition of the CTradeMgr class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRADEMGR_H__4BB39BE4_28A2_4A04_AC00_33A06C4A007E__INCLUDED_)
#define AFX_TRADEMGR_H__4BB39BE4_28A2_4A04_AC00_33A06C4A007E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTradeMgr

class CTradeMgr : 
	public IDispatchImpl<ITradeMgr, &IID_ITradeMgr, &LIBID_TRADEMGMTLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CTradeMgr,&CLSID_TradeMgr>
{
public:
	CTradeMgr();
	~CTradeMgr();

BEGIN_COM_MAP(CTradeMgr)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ITradeMgr)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CTradeMgr) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_TradeMgr)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ITradeMgr
public:
	STDMETHOD(BuyStocks)(/*[in]*/ BSTR bsClient, /*[in]*/ BSTR bsSymbol, /*[in]*/ long lShares);
};

#endif // !defined(AFX_TRADEMGR_H__4BB39BE4_28A2_4A04_AC00_33A06C4A007E__INCLUDED_)
