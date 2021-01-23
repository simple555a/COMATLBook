// WzdAgSvr.h : Declaration of the CWzdAgSvr

#ifndef __WZDAGGSVR_H_
#define __WZDAGGSVR_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWzdAgSvr
class ATL_NO_VTABLE CWzdAgSvr : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWzdAgSvr, &CLSID_WzdAgSvr>,
	public IDispatchImpl<IWzdAgSvr, &IID_IWzdAgSvr, &LIBID_AGGSVRLib>
{
public:
	CWzdAgSvr()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WZDAGGSVR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzdAgSvr)
	COM_INTERFACE_ENTRY(IWzdAgSvr)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWzdAgSvr
public:
	STDMETHOD(Method1)(/*[in]*/ long lArg, /*[out]*/ long *plArg);
};

#endif //__WZDAGGSVR_H_
