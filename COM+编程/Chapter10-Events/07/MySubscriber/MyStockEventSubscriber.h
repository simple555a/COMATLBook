// MyStockEventSubscriber.h: Definition of the CMyStockEventSubscriber class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSTOCKEVENTSUBSCRIBER_H__4BE641E3_0689_44C7_AF9F_211E5AFA3604__INCLUDED_)
#define AFX_MYSTOCKEVENTSUBSCRIBER_H__4BE641E3_0689_44C7_AF9F_211E5AFA3604__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../StockPrice/StockPrice.h"
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyStockEventSubscriber

class CMyStockEventSubscriber : 
	public IDispatchImpl<IMyStockPriceEvent, &IID_IMyStockPriceEvent, &LIBID_STOCKPRICELib>, 
	public IMyStockEventSubscriber,
	public CComObjectRoot,
	public CComCoClass<CMyStockEventSubscriber,&CLSID_MyStockEventSubscriber>
{
public:
	CMyStockEventSubscriber() {}
BEGIN_COM_MAP(CMyStockEventSubscriber)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyStockPriceEvent)
	COM_INTERFACE_ENTRY(IMyStockEventSubscriber)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyStockEventSubscriber) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyStockEventSubscriber)

// IMyStockPriceEvent
public:
	STDMETHOD(NewQuote)(/*[in]*/ BSTR bsSymbol, /*[in]*/ double dValue);

// IMyStockEventSubscriber
public:
};

#endif // !defined(AFX_MYSTOCKEVENTSUBSCRIBER_H__4BE641E3_0689_44C7_AF9F_211E5AFA3604__INCLUDED_)
