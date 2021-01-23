// ClientA.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <tchar.h>

int DisplayUsage()
{
	static LPCTSTR g_pszUsage = 
_T("ClientA.exe [-anon | -iden | -imp | -del | -delB | -cloak]");

	::MessageBox(NULL, g_pszUsage, _T("Usage"), MB_OK);
	return 1;
}

void sub(DWORD dwImpLevel, long lDelegate);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	if (2 != __argc) {
		return DisplayUsage();
	}

	long lDelegate = 0;
	DWORD dwImpersonationLevel;
	if (!stricmp(__targv[1], "-anon")) {
		dwImpersonationLevel = RPC_C_IMP_LEVEL_ANONYMOUS;
	}else
	if (!stricmp(__targv[1], "-iden")) {
		dwImpersonationLevel = RPC_C_IMP_LEVEL_IDENTIFY;
	}else
	if (!stricmp(__targv[1], "-imp")) {
		dwImpersonationLevel = RPC_C_IMP_LEVEL_IMPERSONATE;
	}else
	if (!stricmp(__targv[1], "-del")) {
		dwImpersonationLevel = RPC_C_IMP_LEVEL_DELEGATE;
	}else
	if (!stricmp(__targv[1], "-delB")) { // delegation at ServerB as well
		dwImpersonationLevel = RPC_C_IMP_LEVEL_DELEGATE;
		lDelegate = 1; // no cloaking
	}else
	if (!stricmp(__targv[1], "-cloak")) { // delegation at ServerB as well
		dwImpersonationLevel = RPC_C_IMP_LEVEL_DELEGATE;
		lDelegate = 2; // cloaking
	}else {
		return DisplayUsage();
	}

	
 	CCPLComInitializer init;

	try {
		sub(dwImpersonationLevel, lDelegate);
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	return 0;
}

void sub(DWORD dwImpLevel, long lDelegate)
{
	HRESULT hr = ::CoInitializeSecurity(
		NULL, 
		-1, 
		NULL, 
		NULL, 
		RPC_C_AUTHN_LEVEL_DEFAULT, 
		dwImpLevel,
		NULL, 
		EOAC_NONE,
		NULL);
	if (FAILED(hr)) {
		_com_issue_error(hr);
	}

	IUnknownPtr spUnk;
	hr = CPLCreateInstance(OLESTR("PVDEV"), 
		__uuidof(SERVERBLib::MyServerB),
		&spUnk);
	if (FAILED(hr)) {
		_com_issue_error(hr);
	}

	SERVERBLib::IMyServerBPtr spServer = spUnk;
	_bstr_t bsOutput = spServer->DoIt(lDelegate);
	::MessageBox(NULL, bsOutput, _T("Output"), MB_OK);
}

