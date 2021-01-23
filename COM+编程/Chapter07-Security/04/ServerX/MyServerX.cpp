// MyServerX.cpp : Implementation of CServerXApp and DLL registration.

#include "stdafx.h"
#include "ServerX.h"
#include "MyServerX.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyServerX::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyServerX,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMyServerX::Advise(ICallMe *pCallMe)
{
	HRESULT hr = pCallMe->Hello();

	if (FAILED(hr)) {
		return Error(_T("Error invoking the sink"), __uuidof(IMyServerX), hr);
	}

	return S_OK;
}
