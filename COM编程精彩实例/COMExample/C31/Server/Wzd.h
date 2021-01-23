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
	STDMETHOD(Simple1)(unsigned char cArg, short sArg, unsigned short usArg, workday enumArg);
	STDMETHOD(Simple2)(long lArg, unsigned long ulArg );
	STDMETHOD(Simple3)(float fArg, double dArg);
	STDMETHOD(Simple4)(boolean bArg, byte byArg, hyper yArg, unsigned hyper uyArg);
	STDMETHOD(Simple5)(long lArg1,long* lArg2,long* lArg3);
	STDMETHOD(Array1)(long aArg[25]);
	STDMETHOD(Array2)(long lSize, long aArg[][5]);
	STDMETHOD(Array3)(long lFirst, long lLast, long lSize, long *aArg);
	STDMETHOD(Array4)(long lFirst, long lLength, long lSize, long *aArg);
	STDMETHOD(Structs1)(MYSTRUCT myStruct, IUnknown *myClass);
	STDMETHOD(EUnions1)(long lType, MYEUNION myEUnion);
	STDMETHOD(MemPtr1)(MYSTRUCT *pPtr);
	STDMETHOD(MemPtr2)(MYSTRUCT **pPtr);
	STDMETHOD(MemPtr3)(MYSTRUCT **pPtr1,MYSTRUCT **pPtr2);
	STDMETHOD(MemPtr4)(MYSTRUCT **pPtr1,MYSTRUCT **pPtr2);
	STDMETHOD(VBVars1)(BSTR bstr,BSTR* pBSTR);
	STDMETHOD(VBVars2)(SAFEARRAY** pSA);
	STDMETHOD(VBVars3)(VARIANT* pVAR1,VARIANT* pVAR2,VARIANT* pVAR3);
	STDMETHOD(VBVars4)(long *pVal);
};
#endif //__WZD_H_
