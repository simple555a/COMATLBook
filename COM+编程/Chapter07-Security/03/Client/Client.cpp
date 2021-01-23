// Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "../../01/MyCompanySalary/MyCompanySalary.tlb"

void sub();


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	CCPLComInitializer init;

	// Auth Identity structure
	SEC_WINNT_AUTH_IDENTITY_W authidentity;
	ZeroMemory( &authidentity, sizeof(authidentity) );

	authidentity.User = L"pvguest";
	authidentity.UserLength = wcslen( authidentity.User );
	authidentity.Domain = L"pvhome";
	authidentity.DomainLength = wcslen( authidentity.Domain );
	authidentity.Password = L"xyz";
	authidentity.PasswordLength = wcslen( authidentity.Password );
	authidentity.Flags = SEC_WINNT_AUTH_IDENTITY_UNICODE;

	SOLE_AUTHENTICATION_INFO    authInfo[2];

	ZeroMemory( authInfo, sizeof( authInfo ) );

	// Kerberos Settings
	authInfo[0].dwAuthnSvc = RPC_C_AUTHN_GSS_KERBEROS ;
	authInfo[0].dwAuthzSvc = RPC_C_AUTHZ_NONE;
	authInfo[0].pAuthInfo = &authidentity;

	// NTLM Settings
	authInfo[1].dwAuthnSvc = RPC_C_AUTHN_WINNT;
	authInfo[1].dwAuthzSvc = RPC_C_AUTHZ_NONE;
	authInfo[1].pAuthInfo = &authidentity;

	SOLE_AUTHENTICATION_LIST    authList;

	authList.cAuthInfo = 2;
	authList.aAuthInfo = authInfo;

	HRESULT hr = ::CoInitializeSecurity(
		NULL,						// Security descriptor
		-1,							// Count of entries in asAuthSvc
		NULL,						// asAuthSvc array
		NULL,						// Reserved for future use
		RPC_C_AUTHN_LEVEL_DEFAULT,	// Authentication level
		RPC_C_IMP_LEVEL_IMPERSONATE,   // Impersonation level
		&authList,					// Authentication Information
		EOAC_NONE,					// Additional capabilities
		NULL						// Reserved
		);


	try {
		sub();
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	return 0;
}

void sub()
{
	IUnknownPtr spUnk;
	HRESULT hr = CPLCreateInstance(OLESTR("PVDEV"), 
		__uuidof(MYCOMPANYSALARYLib::EmployeeSalary),
		&spUnk);

	if (FAILED(hr)) {
		_com_issue_error(hr);
	}

	MYCOMPANYSALARYLib::IEmployeeSalaryPtr spSalary = spUnk;

	IClientSecurityPtr spClientSec = spSalary;

	long lVal = spSalary->GetSalary("PVHOME\\pradeep");
	TCHAR buf[40];
	_stprintf(buf, _T("%d"), lVal);
	::MessageBox(NULL, buf, _T("Salary"), MB_OK);
}

