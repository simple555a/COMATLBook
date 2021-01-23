// Wzd.h : Declaration of the CWzd

#ifndef __WZD_H_
#define __WZD_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWzd
class ATL_NO_VTABLE CWzd : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWzd, &CLSID_Wzd>,
	public IDispatchImpl<IWzd, &IID_IWzd, &LIBID_SERVERLib>
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
END_COM_MAP()

// IWzd
public:
	STDMETHOD(GetCollection)(LPUNKNOWN *pCollection);
};
#endif //__WZD_H_
