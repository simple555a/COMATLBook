// MyTest.cpp : Implementation of CMTAServerApp and DLL registration.

#include "stdafx.h"
#include "MTAServer.h"
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
	::MessageBox(NULL, "Hello World", "My Test", MB_OK);

	return S_OK;
}
