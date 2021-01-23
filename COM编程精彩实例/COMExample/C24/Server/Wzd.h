// Wzd.h : Declaration of the CWzd

#ifndef __WZD_H_
#define __WZD_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWzdTear
class CWzd;
class ATL_NO_VTABLE CWzdTear : 
	public IDispatchImpl<IWzdTear, &IID_IWzdTear, &LIBID_SERVERLib>,
	public CComTearOffObjectBase<CWzd>
{
public:
	CWzdTear()
	{
	}

//DECLARE_REGISTRY_RESOURCEID(IDR_WZD)

//DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzdTear)
	COM_INTERFACE_ENTRY(IWzdTear)
//	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWzd
public:
	STDMETHOD(Method2)(long lArg);
};

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
	COM_INTERFACE_ENTRY_TEAR_OFF(IID_IWzdTear, CWzdTear)
END_COM_MAP()

// IWzd
public:
	STDMETHOD(Method1)(long lArg);
};
#endif //__WZD_H_
