// MySingleton.cpp : Implementation of CSingletonExampleApp and DLL registration.

#include "stdafx.h"
#include "SingletonExample.h"
#include "MySingleton.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMySingleton::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMySingleton,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

CMySingleton::CMySingleton()
{
}

CMySingleton::~CMySingleton()
{
}

STDMETHODIMP CMySingleton::get_LicenseKey(BSTR *pVal)
{
	CCPLWinSharedResource<CComBSTR>::GUARD guard(m_bsLicenseKey);
	CComBSTR& bsLicenseKey = guard;
	*pVal = bsLicenseKey.Copy();

	return S_OK;
}

STDMETHODIMP CMySingleton::put_LicenseKey(BSTR newVal)
{
	CCPLWinSharedResource<CComBSTR>::GUARD guard(m_bsLicenseKey);
	CComBSTR& bsLicenseKey = guard;
	bsLicenseKey = newVal;

	return S_OK;
}
