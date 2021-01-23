// WzdColl.h : Declaration of the CWzdCollection

#ifndef __WZDCOLLECTION_H_
#define __WZDCOLLECTION_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWzdCollection
class ATL_NO_VTABLE CWzdCollection : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWzdCollection, &CLSID_WzdCollection>,
	public IDispatchImpl<IWzdCollection, &IID_IWzdCollection, &LIBID_COLLECTSRVLib>
{
public:
	CWzdCollection()
	{
	}
	void FinalRelease();

DECLARE_REGISTRY_RESOURCEID(IDR_WZDCOLLECTION)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzdCollection)
	COM_INTERFACE_ENTRY(IWzdCollection)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWzdCollection
public:
	STDMETHOD(Init)(/*[in]*/long numObjs);
	STDMETHOD(Item)(/*[in]*/ VARIANT Index, /*[out, retval]*/ LPVARIANT pItem);
	STDMETHOD(get__NewEnum)(/*[out, retval]*/ LPUNKNOWN* pVal);
	STDMETHOD(get_Count)(/*[out, retval]*/ long *pVal);
	STDMETHOD(Add)(/*[in]*/SAFEARRAY **ppNewObj);
private:
	int m_inx;
	int m_numObjs;
	VARIANT *m_var;
};

#endif //__WZDCOLLECTION_H_
