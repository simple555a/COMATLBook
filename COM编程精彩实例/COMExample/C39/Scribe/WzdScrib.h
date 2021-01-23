// WzdSubscribe.h : Declaration of the CWzdSubscribe

#ifndef __WZDSUBSCRIBE_H_
#define __WZDSUBSCRIBE_H_

#include "resource.h"       // main symbols
#include <mtx.h>

/////////////////////////////////////////////////////////////////////////////
// CWzdSubscribe
class ATL_NO_VTABLE CWzdSubscribe : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWzdSubscribe, &CLSID_WzdSubscribe>,
	public IDispatchImpl<IWzdSubscribe, &IID_IWzdSubscribe, &LIBID_SUBSCRIBERLib>
{
public:
	CWzdSubscribe()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WZDSUBSCRIBE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

DECLARE_NOT_AGGREGATABLE(CWzdSubscribe)

BEGIN_COM_MAP(CWzdSubscribe)
	COM_INTERFACE_ENTRY(IWzdSubscribe)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWzdSubscribe
public:
	STDMETHOD(WzdEvent)(/*[in]*/ long lArg);
};

#endif //__WZDSUBSCRIBE_H_
