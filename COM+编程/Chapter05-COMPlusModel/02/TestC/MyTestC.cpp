// MyTestC.cpp : Implementation of CTestCApp and DLL registration.

#include "stdafx.h"
#include "TestC.h"
#include "MyTestC.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyTestC::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyTestC,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMyTestC::DoIt(BSTR *pbVal)
{
	CComBSTR bs("You got to me");
	*pbVal = bs.Detach();

	return S_OK;
}
