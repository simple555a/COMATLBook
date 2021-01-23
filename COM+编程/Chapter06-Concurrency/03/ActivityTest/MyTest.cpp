// MyTest.cpp : Implementation of CActivityTestApp and DLL registration.

#include "stdafx.h"
#include "ActivityTest.h"
#include "MyTest.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyTest::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyTest,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMyTest::DoIt()
{
	CComPtr<IObjectContextActivity> spActivity;

	HRESULT hr = ::CoGetObjectContext(
		__uuidof(IObjectContextActivity), (void**) &spActivity);
	_ASSERT (SUCCEEDED(hr));
	GUID idActivity;
	hr = spActivity->GetActivityId(&idActivity);
	_ASSERT (SUCCEEDED(hr));


	OLECHAR buf[40];
	hr = ::StringFromGUID2(idActivity, buf, 40);
	_ASSERT (SUCCEEDED(hr));

	USES_CONVERSION;
	::MessageBox(NULL, W2T(buf), _T("Activity ID"), MB_OK);
	return S_OK;


	return S_OK;
}
