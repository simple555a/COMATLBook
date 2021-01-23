// WzdEx.h : Declaration of the CWzdEx

#ifndef __WZDEX_H_
#define __WZDEX_H_

#include "resource.h"       // main symbols
#include "Wzd.h"
/////////////////////////////////////////////////////////////////////////////
// CWzdEx
class ATL_NO_VTABLE CWzdEx :
	public CWzdBase, 
//	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWzdEx, &CLSID_WzdEx>,
	public IDispatchImpl<IWzdEx, &IID_IWzdEx, &LIBID_SERVERLib>
{
public:
	CWzdEx()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WZDEX)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzdEx)
	COM_INTERFACE_ENTRY2(IDispatch, IWzdEx)
	COM_INTERFACE_ENTRY(IWzdEx)
	COM_INTERFACE_ENTRY_CHAIN(CWzdBase)
END_COM_MAP()

// IWzdEx
public:
	STDMETHOD(Method2)(/*[in]*/long lArg);
};
#endif //__WZDEX_H_
