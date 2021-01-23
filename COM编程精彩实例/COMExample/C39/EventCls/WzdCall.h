// WzdCall.h : Declaration of the CWzdCall

#ifndef __WZDCALL_H_
#define __WZDCALL_H_

#include "resource.h"       // main symbols
#include <mtx.h>

/////////////////////////////////////////////////////////////////////////////
// CWzdCall
class ATL_NO_VTABLE CWzdCall : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWzdCall, &CLSID_WzdCall>,
	public IDispatchImpl<IWzdCall, &IID_IWzdCall, &LIBID_EVENTCLSLib>
{
public:
	CWzdCall()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WZDCALL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

DECLARE_NOT_AGGREGATABLE(CWzdCall)

BEGIN_COM_MAP(CWzdCall)
	COM_INTERFACE_ENTRY(IWzdCall)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWzdCall
public:
	STDMETHOD(WzdEvent)(/*[in]*/ long lArg);
};

#endif //__WZDCALL_H_
