// Wzd.cpp : Implementation of CWzd
#include "stdafx.h"
#include "comdef.h"
#include "Server.h"
#include "Wzd.h"
#include "errors.h"

/////////////////////////////////////////////////////////////////////////////
// CWzd

STDMETHODIMP CWzd::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IWzd
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CWzd::Method1(long lArg, long *plArg)
{
	

	return WZD_ERROR2;
}

STDMETHODIMP CWzd::Method2(long lArg)
{
	ICreateErrorInfo *cei;
	HRESULT hr = CreateErrorInfo(&cei);
	IErrorInfo *eip;
	hr = cei->QueryInterface(IID_IErrorInfo, (LPVOID*) &eip);
	if (!FAILED(hr))
	{
		cei->SetDescription(L"Something bad happened.");	// error in human form
		cei->SetSource(_bstr_t(__FILE__));					// where it happened
		cei->SetHelpContext(23);							// plug into help file to summon a
		cei->SetHelpFile(L"help.hlp");						// particular passage	
		SetErrorInfo(0, eip);
		eip->Release();
	}
	cei->Release();
	return WZD_ERROR3;
}
