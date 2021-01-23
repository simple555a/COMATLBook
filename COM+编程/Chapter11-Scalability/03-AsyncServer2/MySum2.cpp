// MySum2.cpp : Implementation of CAsyncServer2App and DLL registration.

#include "stdafx.h"
#include "AsyncServer2.h"
#include "MySum2.h"
#include "MyAsyncSumCallObject.h"

/////////////////////////////////////////////////////////////////////////////
//


STDMETHODIMP CMySum2::GetSum(long lVal1, long lVal2, long *plSum)
{
	*plSum = lVal1 + lVal2;

	return S_OK;
}

STDMETHODIMP CMySum2::CreateCall(REFIID riid1, IUnknown* pUnk, REFIID riid2, IUnknown** ppv)
{
	*ppv = NULL;

	// Step 1: Ensure that input parameters are valid
	if (__uuidof(AsyncIMySum2) != riid1) {
		return E_INVALIDARG;
	}
	if (NULL != pUnk && IID_IUnknown != riid2) {
		return E_INVALIDARG;
	}

	// Step 2: Create call object and aggregrate it with pUnk
	CComPtr<CComPolyObject<CMyAsyncSumCallObject> > spCallObject;
	HRESULT hr = CComPolyObject<CMyAsyncSumCallObject>::CreateInstance(pUnk, &spCallObject);
	_ASSERT (SUCCEEDED(hr));
	spCallObject->InternalAddRef();

	// Step 3: Return the requested interface
	return spCallObject->QueryInterface(riid2, (void**) ppv);
}
