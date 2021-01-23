// Wzd.h : Declaration of the CWzd

#ifndef __WZD_H_
#define __WZD_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWzd
class ATL_NO_VTABLE CWzdBase : 
	public CComObjectRootEx<CComSingleThreadModel>,
//	public CComCoClass<CWzd, &CLSID_Wzd>, //moved down
	public IDispatchImpl<IWzd, &IID_IWzd, &LIBID_SERVERLib>
{
public:
	CWzdBase()
	{
	}

//DECLARE_REGISTRY_RESOURCEID(IDR_WZD)	//moved down

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzdBase)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IWzd)
END_COM_MAP()

// IWzd
public:
	STDMETHOD(Method1)(/*[in]*/ long lArg);
};

// new class
class CWzd :
	public CWzdBase,
	public CComCoClass<CWzd, &CLSID_Wzd>
{
public:

DECLARE_REGISTRY_RESOURCEID(IDR_WZD)
};


#endif //__WZD_H_
