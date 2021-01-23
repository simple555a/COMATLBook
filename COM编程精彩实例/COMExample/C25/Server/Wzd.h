// Wzd.h : Declaration of the CWzd

#ifndef __WZD_H_
#define __WZD_H_

#include "resource.h"       // main symbols
#include "..\ISinkSrv\IWzdSink.h"
EXTERN_C const IID IID_IWzdSink;

/////////////////////////////////////////////////////////////////////////////
template <class T>
class CProxyIWzdSinkEvents : public IConnectionPointImpl<T, &IID_IWzdSink, CComDynamicUnkArray>
{
public:
	HRESULT Fire_WzdSink( long lArg )
	{
		T* pT = (T*)this;
		pT->Lock();
		HRESULT ret;
		IUnknown** pp = m_vec.begin();
		while (pp < m_vec.end())
		{
			if (*pp != NULL)
			{
				IWzdSink *pWzdSinks = reinterpret_cast<IWzdSink*>(*pp);
				ret = pWzdSinks->Callback( lArg );
			}
			pp++;
		}
		pT->Unlock();
		return ret;
	}
};


/////////////////////////////////////////////////////////////////////////////
// CWzd
class ATL_NO_VTABLE CWzd : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWzd, &CLSID_Wzd>,
	public IConnectionPointContainerImpl<CWzd>,
	public IDispatchImpl<IWzd, &IID_IWzd, &LIBID_SERVERLib>,
	public CProxyIWzdSinkEvents<CWzd>
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
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CWzd)
	CONNECTION_POINT_ENTRY(IID_IWzdSink)
END_CONNECTION_POINT_MAP()


// IWzd
public:
	STDMETHOD(Method1)(/*[in]*/ long lArg);
};

#endif //__WZD_H_
