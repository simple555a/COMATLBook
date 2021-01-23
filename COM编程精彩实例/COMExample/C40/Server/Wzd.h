// Wzd.h : Declaration of the CWzd

#ifndef __WZD_H_
#define __WZD_H_

#include "resource.h"       // main symbols
#include <mtx.h>

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

DECLARE_NOT_AGGREGATABLE(CWzd)

BEGIN_COM_MAP(CWzd)
	COM_INTERFACE_ENTRY(IWzd)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWzd
public:
	STDMETHOD(Method1)(/*[in]*/ long lArg);
};

#endif //__WZD_H_
