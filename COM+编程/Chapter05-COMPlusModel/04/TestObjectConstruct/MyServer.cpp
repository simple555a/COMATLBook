// MyServer.cpp : Implementation of CTestObjectConstructApp and DLL registration.

#include "stdafx.h"
#include "TestObjectConstruct.h"
#include "MyServer.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyServer::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyServer,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMyServer::Construct(IDispatch* pDisp)
{
	CComPtr<IObjectConstructString> spConstructString;
	HRESULT hr = pDisp->QueryInterface(&spConstructString);
	_ASSERT (SUCCEEDED(hr));
	hr = spConstructString->get_ConstructString(&m_bsInitString);
	_ASSERT (SUCCEEDED(hr));
	return hr;
}

STDMETHODIMP CMyServer::DoIt(BSTR *bsRetVal)
{
	*bsRetVal = m_bsInitString.Copy();

	return S_OK;
}
