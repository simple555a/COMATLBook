// MyStockPriceEvent.h: Definition of the CMyStockPriceEvent class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSTOCKPRICEEVENT_H__24D7F132_1AAF_4461_914C_AB326B74B93B__INCLUDED_)
#define AFX_MYSTOCKPRICEEVENT_H__24D7F132_1AAF_4461_914C_AB326B74B93B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyStockPriceEvent

class CMyStockPriceEvent : 
	public IDispatchImpl<IMyStockPriceEvent, &IID_IMyStockPriceEvent, &LIBID_STOCKPRICELib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyStockPriceEvent,&CLSID_MyStockPriceEvent>
{
public:
	CMyStockPriceEvent() {}
BEGIN_COM_MAP(CMyStockPriceEvent)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyStockPriceEvent)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyStockPriceEvent) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyStockPriceEvent)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyStockPriceEvent
public:
	STDMETHOD(NewQuote)(/*[in]*/ BSTR bsSymbol, /*[in]*/ double dValue);
};

#endif // !defined(AFX_MYSTOCKPRICEEVENT_H__24D7F132_1AAF_4461_914C_AB326B74B93B__INCLUDED_)
