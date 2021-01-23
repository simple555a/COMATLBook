// WzdSrv.h : Declaration of the CWzdSrv

#ifndef __WZDSRV_H_
#define __WZDSRV_H_

#include "resource.h"       // main symbols

#include "guids.h"
/////////////////////////////////////////////////////////////////////////////
// CWzdSrv
class ATL_NO_VTABLE CWzdSrv : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWzdSrv, &CLSID_WzdSrv>,
	public IDispatchImpl<IWzdSrv, &IID_IWzdSrv, &LIBID_SERVERLib>
{
public:
	CWzdSrv()
	{
		m_pUnknown=NULL;
	}

	HRESULT FinalConstruct( )
	{
		HRESULT hr=::CoCreateInstance(CLSID_WzdAgSvr, 
					GetControllingUnknown(), CLSCTX_ALL,
					IID_IUnknown, (LPVOID*)&m_pUnknown);
		return hr;
	}

	void FinalRelease()
	{
		m_pUnknown->Release();
	}
	
DECLARE_GET_CONTROLLING_UNKNOWN()
   
DECLARE_REGISTRY_RESOURCEID(IDR_WZDSRV)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzdSrv)
	COM_INTERFACE_ENTRY(IWzdSrv)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IWzdAgSvr,m_pUnknown)
END_COM_MAP()

// IWzdSrv
public:
	STDMETHOD(Method2)(/*[in]*/ long lArg, /*[in]*/ unsigned long ulArg);

private:
	LPUNKNOWN m_pUnknown;
};

#endif //__WZDSRV_H_
