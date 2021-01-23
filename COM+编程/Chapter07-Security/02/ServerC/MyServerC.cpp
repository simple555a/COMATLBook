// MyServerC.cpp : Implementation of CServerCApp and DLL registration.

#include "stdafx.h"
#include "ServerC.h"
#include "MyServerC.h"
#include <comdef.h>

_bstr_t GetServerSecurityBlanket()
{
	// Step 1: Get IServerSecurity interface
	CComPtr<IServerSecurity> spSec;
	HRESULT hr = ::CoGetCallContext(__uuidof(IServerSecurity),
		(void**) &spSec);
	if (FAILED(hr)) {
		_bstr_t bsDisplay = "SecurityBlanket: Error getting call context\n";
		bsDisplay += _com_error(hr).ErrorMessage();
		return bsDisplay;
	}

	// Step 2: Get the client's identity
	DWORD dwAuthnSvc, dwAuthzSvc, dwAuthnLevel, dwImpLevel, dwCapabilities;
	OLECHAR* pPrincipalName = NULL;
	RPC_AUTHZ_HANDLE hPrivs;
	hr = spSec->QueryBlanket(
		&dwAuthnSvc,
		&dwAuthzSvc,
		&pPrincipalName,
		&dwAuthnLevel,
		&dwImpLevel,
		&hPrivs,
		&dwCapabilities);
	if (FAILED(hr)) {
		_bstr_t bsDisplay = "Error getting security blanket\n";
		bsDisplay += _com_error(hr).ErrorMessage();
		return bsDisplay;
	}

	_bstr_t bsDisplay = _T("Principal name: ");
	if (NULL == pPrincipalName) {
		bsDisplay += "(Unknown)";
	}else {
		bsDisplay += pPrincipalName;
		::CoTaskMemFree(pPrincipalName); pPrincipalName = NULL;
	}

	bsDisplay += "\nPrivilege name: ";
	if (NULL == hPrivs) {
		bsDisplay += "(Unknown)";
	}else {
		bsDisplay += reinterpret_cast<LPCWSTR>(hPrivs);
	}

	TCHAR buf[256];
	_stprintf(buf, _T("\ndwAuthnSvc=%d, dwAuthzSvc=%d, dwAuthnLevel=%d, dwImpLevel=%d, dwCapabilities=%d"),
			dwAuthnSvc, dwAuthzSvc, dwAuthnLevel, dwImpLevel, dwCapabilities);
	bsDisplay += buf;
	return bsDisplay;
}

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyServerC::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyServerC,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

static _bstr_t GetLocalFileName()
{
	TCHAR szModule[_MAX_PATH];
	GetModuleFileName(_pModule->GetModuleInstance(), szModule, _MAX_PATH);

	TCHAR szDrive[_MAX_DRIVE], szDir[_MAX_DIR];
	_tsplitpath(szModule, szDrive, szDir, NULL, NULL);

	_bstr_t bRetVal = szDrive;
	bRetVal += szDir;
	bRetVal += "LocalFileC.txt";
	return bRetVal;
}

CComBSTR OpenFileForReadOnly(LPCTSTR pszFileName)
{
	CComBSTR bsOutput = pszFileName;
	bsOutput += ": ";
	HANDLE h = ::CreateFile(pszFileName,
		GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);

	if (INVALID_HANDLE_VALUE == h) {
		HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
		if (S_OK == hr) hr = E_FAIL; // Odd! GetLastError shouldn't return success
		bsOutput += _com_error(hr).ErrorMessage();
	}else {
		bsOutput += "SUCCEEDED";
		::CloseHandle(h);
	}
	return bsOutput;
}

STDMETHODIMP CMyServerC::DoIt(BSTR *pbsRetVal)
{
	CComBSTR bsOutput;

	// Get the security interface pointer
	CComPtr<IServerSecurity> spSec;
	HRESULT hr = ::CoGetCallContext(__uuidof(IServerSecurity), (void**) &spSec);
	if (FAILED(hr)) {
		return Error(_T("Error getting call context"), __uuidof(IMyServerC), hr);
	}
	bsOutput = (LPCWSTR) GetServerSecurityBlanket();

	// Impersonate the client
	hr = spSec->ImpersonateClient();
	if (FAILED(hr)) {
		return Error(_T("Error impersonating client"), __uuidof(IMyServerC), hr);
	}

	// Check if you can open a local file
	bsOutput += "\nServerC - Local file open: ";
	bsOutput += OpenFileForReadOnly(GetLocalFileName());

	*pbsRetVal = bsOutput.Detach();

	return S_OK;
}
