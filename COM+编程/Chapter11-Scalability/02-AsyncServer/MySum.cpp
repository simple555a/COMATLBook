// MySum.cpp : Implementation of CAsyncServerApp and DLL registration.

#include "stdafx.h"
#include "AsyncServer.h"
#include "MySum.h"

/////////////////////////////////////////////////////////////////////////////
//
#define CHECK_FOR_CANCELLATION

STDMETHODIMP CMySum::GetSum(long lVal1, long lVal2, long *plSum)
{
#ifndef CHECK_FOR_CANCELLATION
	::Sleep(5 * 1000); // sleep for 5 seconds
	*plSum = lVal1 + lVal2;

	return S_OK;
#else
	CComPtr<ICancelMethodCalls> spCancel;
	HRESULT hr = ::CoGetCallContext(__uuidof(ICancelMethodCalls), (void**) & spCancel);
	_ASSERT (SUCCEEDED(hr));

	for(int i=0; i<5;i++) {
		::Sleep(1 * 1000);
		hr = spCancel->TestCancel();
		if (RPC_E_CALL_CANCELED == hr) {
			return RPC_E_CALL_CANCELED;
		}
	}
	*plSum = lVal1 + lVal2;

	return S_OK;

#endif
}
