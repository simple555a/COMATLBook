// Wzd.h : Declaration of the CWzd

#ifndef __WZD_H_
#define __WZD_H_

#include "resource.h"       // main symbols


/////////////////////////////////////////////////////////////////////////////
// CWzdLicense-- a class that checks on licensing
class CWzdLicense
{
protected:
   static BOOL VerifyLicenseKey(BSTR bstr)
   {
	   // compare bstr with embedded license info
	   return TRUE; // valid license
   }

   static BOOL GetLicenseKey(DWORD dwReserved, BSTR* pBstr) 
   {
      *pBstr = L"licence";// embedded license info
      return TRUE;
   }

   static BOOL IsLicenseValid() 
   {  
	   // open license file and compare with license key info embedded in this class
	   return TRUE; //TRUE==licensed
   }
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

DECLARE_CLASSFACTORY2(CWzdLicense)
   
DECLARE_REGISTRY_RESOURCEID(IDR_WZD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWzd)
	COM_INTERFACE_ENTRY(IWzd)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWzd
public:
	STDMETHOD(Method1)(long lArg);
};
#endif //__WZD_H_
