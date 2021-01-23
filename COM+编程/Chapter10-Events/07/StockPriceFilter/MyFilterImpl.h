// MyFilterImpl.h: Definition of the CMyFilterImpl class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFILTERIMPL_H__AE8B8C77_3844_42B9_997F_C6DF85109023__INCLUDED_)
#define AFX_MYFILTERIMPL_H__AE8B8C77_3844_42B9_997F_C6DF85109023__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyFilterImpl

class CMyFilterImpl : 
	public IMyFilterImpl,
	public IMultiInterfacePublisherFilter,
	public IDispatchImpl<IMyStockPriceEvent, &IID_IMyStockPriceEvent, &LIBID_STOCKPRICELib>, 
	public CComObjectRoot,
	public CComCoClass<CMyFilterImpl,&CLSID_MyFilterImpl>
{
public:
	CMyFilterImpl();
	~CMyFilterImpl();

BEGIN_COM_MAP(CMyFilterImpl)
	COM_INTERFACE_ENTRY(IMyFilterImpl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyStockPriceEvent)
	COM_INTERFACE_ENTRY(IMultiInterfacePublisherFilter)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyFilterImpl) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyFilterImpl)

// IMyFilterImpl
public:

// IMyStockPriceEvent
public:
	STDMETHOD(NewQuote)(/*[in]*/ BSTR bsSymbol, /*[in]*/ double dValue);

// IMultiInterfacePublisherFilter methods
public:
	STDMETHOD(Initialize)(IMultiInterfaceEventControl *pMIEC);
	STDMETHOD(PrepareToFire)(REFIID riid, BSTR methodname, IFiringControl* pFC);

private:
	CComPtr<IEventObjectCollection> m_spColl;
	CComPtr<IFiringControl> m_spFC;

};

#endif // !defined(AFX_MYFILTERIMPL_H__AE8B8C77_3844_42B9_997F_C6DF85109023__INCLUDED_)
