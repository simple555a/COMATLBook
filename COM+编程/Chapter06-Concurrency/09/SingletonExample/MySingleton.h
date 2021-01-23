// MySingleton.h: Definition of the CMySingleton class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSINGLETON_H__6C6D0DA4_A73E_4C14_BA13_CFCE9D3E1436__INCLUDED_)
#define AFX_MYSINGLETON_H__6C6D0DA4_A73E_4C14_BA13_CFCE9D3E1436__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMySingleton

class CMySingleton : 
	public IDispatchImpl<IMySingleton, &IID_IMySingleton, &LIBID_SINGLETONEXAMPLELib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMySingleton,&CLSID_MySingleton>
{
public:
	CMySingleton();
	~CMySingleton();

BEGIN_COM_MAP(CMySingleton)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMySingleton)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMySingleton) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 
DECLARE_CLASSFACTORY_SINGLETON(CMySingleton)

DECLARE_REGISTRY_RESOURCEID(IDR_MySingleton)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMySingleton
public:
	STDMETHOD(get_LicenseKey)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_LicenseKey)(/*[in]*/ BSTR newVal);

private:
	CCPLWinSharedResource<CComBSTR> m_bsLicenseKey;
};

#endif // !defined(AFX_MYSINGLETON_H__6C6D0DA4_A73E_4C14_BA13_CFCE9D3E1436__INCLUDED_)
