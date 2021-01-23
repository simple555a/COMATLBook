// MyServerB.cpp : Implementation of CServerBApp and DLL registration.

#include "stdafx.h"
#include "ServerB.h"
#include "MyServerB.h"
#include "../ServerC/ServerC.h"
#include "../ServerC/ServerC_i.c"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyServerB::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyServerB,
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
	bRetVal += "LocalFileB.txt";
	return bRetVal;
}

_bstr_t GetRemoteFileName()
{
	return "\\\\PVDC\\Data\\NetFile.txt";
}

CComBSTR OpenFileForReadOnly(LPCTSTR pszFileName)
{
	HANDLE h = ::CreateFile(pszFileName,
		GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);

	if (INVALID_HANDLE_VALUE == h) {
		HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
		if (S_OK == hr) hr = E_FAIL; // Odd! GetLastError shouldn't return success
		return _com_error(hr).ErrorMessage();
	}

	::CloseHandle(h);
	return "SUCCEEDED";
}

STDMETHODIMP CMyServerB::DoIt(long lDelegate, BSTR *pbsRetVal)
{
	// Get the security interface pointer
	CComPtr<IServerSecurity> spSec;
	HRESULT hr = ::CoGetCallContext(__uuidof(IServerSecurity), (void**) &spSec);
	if (FAILED(hr)) {
		return Error(_T("Error getting call context"), __uuidof(IMyServerB), hr);
	}

	// Impersonate the client
	hr = spSec->ImpersonateClient();
	if (FAILED(hr)) {
		return Error(_T("Error impersonating client"), __uuidof(IMyServerB), hr);
	}

	// Check if you can open a local file
	CComBSTR bsOutput = "ServerB - Local file open: ";
	bsOutput += OpenFileForReadOnly(GetLocalFileName());

	// Check if you can open a network file
	bsOutput += "\nServerB - Network file open: ";
	bsOutput += OpenFileForReadOnly(GetRemoteFileName());

	// Now lets try it on the remote server
	IUnknownPtr spUnkC;
	hr = CPLCreateInstance(OLESTR("PVDC"), CLSID_MyServerC,	&spUnkC);
	if (FAILED(hr)) {
		bsOutput += "\nCould not create remote instance: ";
		bsOutput += _com_error(hr).ErrorMessage();
		*pbsRetVal = bsOutput.Detach();
		return S_OK;
	}

	CComPtr<IMyServerC> spServerC;
	hr = spUnkC->QueryInterface(&spServerC);
	if (FAILED(hr)) {
		bsOutput += "\nQI on remote instance failed: ";
		bsOutput += _com_error(hr).ErrorMessage();
		*pbsRetVal = bsOutput.Detach();
		return S_OK;
	}

	DWORD dwCapability = EOAC_NONE;
	DWORD dwImpLevel = RPC_C_IMP_LEVEL_IMPERSONATE;
	if (lDelegate > 0) {
		dwImpLevel = RPC_C_IMP_LEVEL_DELEGATE;
		if (1 == lDelegate) {
			dwCapability = EOAC_NONE; // no cloaking
		}else
		if (2 == lDelegate) {
			dwCapability = EOAC_DYNAMIC_CLOAKING;
		}
	}

	CComPtr<IClientSecurity> spClientSec;
	hr = spServerC->QueryInterface(&spClientSec);
	if (FAILED(hr)) {
		bsOutput += "\nQI for IClientSecurity on remote instance failed: ";
		bsOutput += _com_error(hr).ErrorMessage();
	}else {
		hr = spClientSec->SetBlanket(spServerC, 
			RPC_C_AUTHN_DEFAULT,
			RPC_C_AUTHZ_DEFAULT,
			NULL,
			RPC_C_AUTHN_LEVEL_DEFAULT,
			dwImpLevel,
			NULL,
			dwCapability);
		if (FAILED(hr)) {
			bsOutput += "\nSet blanket failed: ";
			bsOutput += _com_error(hr).ErrorMessage();
		}
	}


	CComBSTR bsOutputFromRemoteMachine;
	hr = spServerC->DoIt(&bsOutputFromRemoteMachine);
	if (FAILED(hr)) {
		bsOutput += "\nDoIt on remote instance failed: ";
		bsOutput += _com_error(hr).ErrorMessage();
		*pbsRetVal = bsOutput.Detach();
		return S_OK;
	}

	bsOutput += "\n";
	bsOutput += bsOutputFromRemoteMachine;

	*pbsRetVal = bsOutput.Detach();

	return S_OK;
}
