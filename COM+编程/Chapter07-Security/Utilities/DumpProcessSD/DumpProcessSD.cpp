// DumpProcessSD.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int DisplayUsage()
{
	::MessageBox(NULL, _T("DumpProcessSD pid"), _T("Usage"), MB_OK);
	return 1;
}

_bstr_t DisplaySID(PSID psid)
{
	if (NULL == psid) {
		return " (No owner)";
	}

	const int BUFSIZE = 80;
	TCHAR szAccountName[BUFSIZE], szDomainName[BUFSIZE];
	DWORD dwAccountSize = 80, dwDomainSize = 80;
	SID_NAME_USE sidType;
	BOOL bFlag = ::LookupAccountSid(NULL, psid, 
		szAccountName, &dwAccountSize, 
		szDomainName, &dwDomainSize,
		&sidType);
	if (FALSE == bFlag) {
		HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
		return _com_error(hr).ErrorMessage();
	}

	_bstr_t bsRetVal = szAccountName;
	bsRetVal += " FROM ";
	bsRetVal += szDomainName;
	return bsRetVal;
}

int DisplayError(LPCTSTR pszDesc, HRESULT hr)
{
	_bstr_t bsDisplay = pszDesc;
	bsDisplay += "\n";
	bsDisplay += _com_error(hr).ErrorMessage();
	::MessageBox(NULL, bsDisplay, NULL, MB_OK);
	return 1;
}

_bstr_t DisplayACL(ACL* pAcl)
{
	ACL_SIZE_INFORMATION aclSize;
	BOOL bFlag = ::GetAclInformation(pAcl, &aclSize, sizeof(ACL_SIZE_INFORMATION), AclSizeInformation);
	if (FALSE == bFlag) {
		HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
		return _com_error(hr).ErrorMessage();
	}

	_bstr_t bsRetVal = "\n";
	for(DWORD i=0; i<aclSize.AceCount; i++) {
		ACCESS_ALLOWED_ACE* pAce;
		bFlag = ::GetAce(pAcl, i, (void**) &pAce);
		_ASSERT (TRUE == bFlag);
		TCHAR buf[100];
		_stprintf(buf, _T("\n   ACE type: 0x%x mask: 0x%x for "),
			(int) pAce->Header.AceType,
			(int) pAce->Mask);
		bsRetVal += buf;
		bsRetVal += DisplaySID(&pAce->SidStart);
	}

	return bsRetVal;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	if (2 != __argc) {
		return DisplayUsage();
	}

	DWORD dwProcId = _ttoi(__targv[1]);

	CCPLWinHandle hProc = ::OpenProcess(READ_CONTROL, FALSE, dwProcId);
	if (!hProc.IsValid()) {
		return DisplayError(_T("Unable to open the process id"), 
			HRESULT_FROM_WIN32(::GetLastError()));
	}


	// Get the size
	DWORD dwSizeRqd;
	BOOL bFlag = ::GetKernelObjectSecurity(hProc, 
		OWNER_SECURITY_INFORMATION | GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION,
		NULL, 0, &dwSizeRqd);

	BYTE* pData = new BYTE[dwSizeRqd];
	bFlag = ::GetKernelObjectSecurity(hProc, 
		OWNER_SECURITY_INFORMATION | GROUP_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION,
		pData, dwSizeRqd, &dwSizeRqd);
	if (FALSE == bFlag) {
		delete [] pData;
		return DisplayError(_T("Unable to get kernel object information"), 
			HRESULT_FROM_WIN32(::GetLastError()));
	}

	SECURITY_DESCRIPTOR* pSD = reinterpret_cast<SECURITY_DESCRIPTOR*>(pData);

	hProc = NULL; // No need to keep the handle open

	// Get the owner first
	_bstr_t bsDisplay = "OWNER: ";
	PSID psid;
	BOOL bOwnerDefaulted;
	bFlag = ::GetSecurityDescriptorOwner(pSD, &psid, &bOwnerDefaulted);
	if (FALSE == bFlag) {
		HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
		bsDisplay += _com_error(hr).ErrorMessage();
	}else {
		bsDisplay += DisplaySID(psid);
	}

	// Get the group
	bsDisplay += "\nGROUP: ";
	bFlag = ::GetSecurityDescriptorGroup(pSD, &psid, &bOwnerDefaulted);
	if (FALSE == bFlag) {
		HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
		bsDisplay += _com_error(hr).ErrorMessage();
	}else {
		bsDisplay += DisplaySID(psid);
	}

	// Get the DACL
	bsDisplay += "\nAccess: ";

	BOOL bDaclPresent, bDaclDefaulted;
	PACL pDacl;
	bFlag = ::GetSecurityDescriptorDacl(pSD, &bDaclPresent, &pDacl, &bDaclDefaulted);
	if (FALSE == bFlag) {
		HRESULT hr = HRESULT_FROM_WIN32(::GetLastError());
		bsDisplay += _com_error(hr).ErrorMessage();
	}else
	if (FALSE == bDaclPresent) {
		bsDisplay += " (Unrestricted access)";
	}else {
		bsDisplay += DisplayACL(pDacl);
	}

	delete [] pData; pData = NULL; pSD = NULL;

	TCHAR buf[100];
	_stprintf(buf, _T("Security Descriptor - Process %d"), dwProcId);
	::MessageBox(NULL, bsDisplay, buf, MB_OK);

	return 0;
}



