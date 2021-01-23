// MyTestA.cpp : Implementation of CTestAApp and DLL registration.

#include "stdafx.h"
#include "TestA.h"
#include "MyTestA.h"

/////////////////////////////////////////////////////////////////////////////
//
void DumpContext(LPCTSTR pszCaption)
{

	CComPtr<IUnknown> spUnk;
	HRESULT hr = ::CoGetObjectContext(IID_IUnknown, 
		reinterpret_cast<void**>(&spUnk));
	if (FAILED(hr)) {
		::MessageBox(NULL, _T("Context not available"), pszCaption, MB_OK);
		return;
	}

	CComPtr<IObjectContextInfo> spCI;
	hr = spUnk->QueryInterface(IID_IObjectContextInfo,
		reinterpret_cast<void**>(&spCI));
	if (FAILED(hr)) {
		::MessageBox(NULL, _T("Context info interface not available"), pszCaption, MB_OK);
		return;
	}

	GUID contextid;
	hr = spCI->GetContextId(&contextid);
	if (FAILED(hr)) {
		::MessageBox(NULL, _T("Context ID not available"), pszCaption, MB_OK);
		return;
	}

	OLECHAR str[40];
	::StringFromGUID2(contextid, str, 40);
	USES_CONVERSION;
	LPTSTR pszText = W2A(str);
	::MessageBox(NULL, pszText, pszCaption, MB_OK);
}

class CMyThread : public CCPLWinThread
{
public:
	void Proc()
	{
		DumpContext("From the worker thread of CMyTestA::DoIt");
	}
};


STDMETHODIMP CMyTestA::DoIt()
{
 	CMyThread t;
	t.Init();

	t.StartThread();

	t.WaitForCompletion();
	DumpContext(_T("From CMyTestA::DoIt"));

	return S_OK;
}
