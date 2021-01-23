// MyJITDemo.cpp : Implementation of CJITSvrApp and DLL registration.

#include "stdafx.h"
#include "JITSvr.h"
#include "MyJITDemo.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyJITDemo::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyJITDemo,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

void DisplayMsg(LPCTSTR pszMsg)
{
	::MessageBox(NULL, pszMsg, _T("Info"), MB_OK);
}

CMyJITDemo::CMyJITDemo()
{
	DisplayMsg(_T("Constructor called"));
}

CMyJITDemo::~CMyJITDemo()
{
	DisplayMsg(_T("Destructor called"));
}

STDMETHODIMP CMyJITDemo::GetSalary(long *pVal)
{
	DisplayMsg("GetSalary called");
	CComPtr<IContextState> spState;
	HRESULT hr = ::CoGetObjectContext(__uuidof(IContextState), (void**) &spState);
	_ASSERT (SUCCEEDED(hr));
	hr = spState->SetDeactivateOnReturn(VARIANT_TRUE);
	_ASSERT (SUCCEEDED(hr));
	

	*pVal = 100000;

	return S_OK;
}

STDMETHODIMP CMyJITDemo::SetEmployee(BSTR bsEmployeeName)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CMyJITDemo::Activate()
{
	DisplayMsg("Activate called");
	return S_OK;
}

STDMETHODIMP_(VOID) CMyJITDemo::Deactivate()
{
	DisplayMsg("deactivate called");
}

STDMETHODIMP_(BOOL) CMyJITDemo::CanBePooled()
{
	DisplayMsg("CanBePooled called");
	return FALSE;
}
