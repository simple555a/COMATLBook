// Wzd.h : Declaration of the CWzd

#ifndef __WZD_H_
#define __WZD_H_

#include "resource.h"       // main symbols
#include "ServerCP.h"

/////////////////////////////////////////////////////////////////////////////
// CWzd
class ATL_NO_VTABLE CWzd : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWzd, &CLSID_Wzd>,
	public IConnectionPointContainerImpl<CWzd>,
	public IDispatchImpl<IWzd, &IID_IWzd, &LIBID_SERVERLib>,
	public IProvideClassInfo2Impl<&CLSID_Wzd,&DIID__IWzdEvents,&LIBID_SERVERLib>,
	public CProxy_IWzdEvents< CWzd >
{
public:
	CWzd()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WZD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzd)
	COM_INTERFACE_ENTRY(IWzd)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CWzd)
	CONNECTION_POINT_ENTRY(DIID__IWzdEvents)
END_CONNECTION_POINT_MAP()


// IWzd
public:
	STDMETHOD(Method1)(/*[in]*/ long lArg);
};

#endif //__WZD_H_
