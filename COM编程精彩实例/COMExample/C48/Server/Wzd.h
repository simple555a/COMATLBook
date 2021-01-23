	
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
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WZD)
DECLARE_GET_CONTROLLING_UNKNOWN()

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzd)
	COM_INTERFACE_ENTRY(IWzd)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}

	CComPtr<IUnknown> m_pUnkMarshaler;

// IWzd
public:
	STDMETHOD(Method1)(/*[in]*/ long lArg);
};

#endif //__WZD_H_
