	
// MyTestD.h : Declaration of the CMyTestD

#ifndef __MYTESTD_H_
#define __MYTESTD_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyTestD
class ATL_NO_VTABLE CMyTestD : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CMyTestD, &CLSID_MyTestD>,
	public IDispatchImpl<IMyTestD, &IID_IMyTestD, &LIBID_TESTDLib>
{
public:
	CMyTestD()
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MYTESTD)
DECLARE_GET_CONTROLLING_UNKNOWN()

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CMyTestD)
	COM_INTERFACE_ENTRY(IMyTestD)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

	// COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)

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

// IMyTestD
public:
	STDMETHOD(DoIt)();
};

#endif //__MYTESTD_H_
