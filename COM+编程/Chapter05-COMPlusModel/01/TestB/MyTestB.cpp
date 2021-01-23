// MyTestB.cpp : Implementation of CTestBApp and DLL registration.

#include "stdafx.h"
#include "TestB.h"
#include "MyTestB.h"
#import "../TestA/TestA.tlb"
using namespace TESTALib; 

/////////////////////////////////////////////////////////////////////////////
//


STDMETHODIMP CMyTestB::DoIt()
{
	IMyTestAPtr sp;
	HRESULT hr = sp.CreateInstance(__uuidof(MyTestA));
	_ASSERT (SUCCEEDED(hr));
	sp->DoIt();
	sp = NULL;

	CComPtr<IObjectContextInfo> spCI;

	hr = ::CoGetObjectContext(IID_IObjectContextInfo, (void**) &spCI);
	_ASSERT (SUCCEEDED(hr));

	GUID guid;
	hr = spCI->GetContextId(&guid);

	OLECHAR str[40];
	::StringFromGUID2(guid, str, 40);
	::MessageBoxW(NULL, str, L"Id B", MB_OK);


	return S_OK;
}
