// EnumSSP.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#define SECURITY_WIN32
#include <sspi.h>

#pragma comment(lib, "Secur32.lib")

// #define STREXPAND(P1) {P1, _T("#P1") }

struct SSPCAPABILITIES {
	ULONG uCapability;
	LPCTSTR pszDesc;
};


SSPCAPABILITIES g_CapabilityList[] = {
   {SECPKG_FLAG_INTEGRITY       , _T("Supports integrity on messages")},
   {SECPKG_FLAG_PRIVACY         , _T("Supports privacy (confidentiality)")},
   {SECPKG_FLAG_TOKEN_ONLY      , _T("Only security token needed")},
   {SECPKG_FLAG_DATAGRAM        , _T("Datagram RPC support")},
   {SECPKG_FLAG_CONNECTION      , _T("Connection oriented RPC support")},
   {SECPKG_FLAG_MULTI_REQUIRED  , _T("Full 3-leg required for re-auth.")},
   {SECPKG_FLAG_CLIENT_ONLY     , _T("Server side functionality not available")},
   {SECPKG_FLAG_EXTENDED_ERROR  , _T("Supports extended error msgs")},
   {SECPKG_FLAG_IMPERSONATION   , _T("Supports impersonation")},
   {SECPKG_FLAG_ACCEPT_WIN32_NAME   , _T("Accepts Win32 names")},
   {SECPKG_FLAG_STREAM          , _T("Supports stream semantics")},
   {SECPKG_FLAG_NEGOTIABLE      , _T("Can be used by the negotiate package")},
   {SECPKG_FLAG_GSS_COMPATIBLE  , _T("GSS Compatibility Available")},
   {SECPKG_FLAG_LOGON           , _T("Supports common LsaLogonUser")},
   {SECPKG_FLAG_ASCII_BUFFERS   , _T("Token Buffers are in ASCII")},
   {SECPKG_FLAG_FRAGMENT        , _T("Package can fragment to fit")},
   {SECPKG_FLAG_MUTUAL_AUTH     , _T("Package can perform mutual authentication")},
   {SECPKG_FLAG_DELEGATION      , _T("Package can delegate")},
};

void ContructCapabilityList(ULONG capability, CComBSTR& bsRetVal)
{
	const int nItems = sizeof(g_CapabilityList)/sizeof(g_CapabilityList[0]);

	for (int i=0; i<nItems; i++) {
		if (capability & g_CapabilityList[i].uCapability) {
			bsRetVal += "   ";
			bsRetVal += g_CapabilityList[i].pszDesc;
			bsRetVal += "\n";
		}
	}
}


	
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	ULONG cPackages;
	SecPkgInfo* aPackageInfo;
	SECURITY_STATUS status = ::EnumerateSecurityPackages(&cPackages, &aPackageInfo);

	USES_CONVERSION;
	for (ULONG i=0; i<cPackages; i++) {
		CComBSTR bsOut;
		SecPkgInfo& curPkg = aPackageInfo[i];
		ContructCapabilityList(curPkg.fCapabilities, bsOut);
		MessageBox(NULL, W2T(bsOut), curPkg.Name, MB_OK);
	};



	return 0;
}



