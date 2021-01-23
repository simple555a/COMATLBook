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
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WZD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzd)
	COM_INTERFACE_ENTRY(IWzd)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWzd
public:
	STDMETHOD(Simple1)(BYTE byArg, short sArg, long lArg);
	STDMETHOD(Simple2)(float fArg, double dArg);
	STDMETHOD(Simple3)(long lArg1,long* lArg2,long* lArg3);
	STDMETHOD(Array1)(long lFirst, long lLast, long lSize, long *aArg);
	STDMETHOD(Array2)(long lFirst, long lLength, long lSize, long *aArg);
	STDMETHOD(VBVars1)(BSTR bstr, BSTR* pBSTR);
	STDMETHOD(VBVars2)(SAFEARRAY** pSA);
	STDMETHOD(VBVars3)(VARIANT* pVAR1,VARIANT* pVAR2,VARIANT* pVAR3);
	STDMETHOD(VBVars4)(long *pVal);
};
#endif //__WZD_H_
