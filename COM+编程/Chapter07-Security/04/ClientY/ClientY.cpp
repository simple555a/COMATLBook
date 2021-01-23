// ClientY.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "../ServerX/ServerX.tlb"
#include "../ServerX/ServerX.h"
#include <IAccess.h>

void sub();

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CCPLComInitializer init;
	_Module.Init(NULL, hInstance);

	try {
		sub();
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	_Module.Term();

	return 0;
}

class CCallMe : 
	public ICallMe,
	public CComObjectRoot
{
public:
	CCallMe()
	{
	}

	~CCallMe()
	{
	}

BEGIN_COM_MAP(CCallMe)
	COM_INTERFACE_ENTRY(ICallMe)
END_COM_MAP()

	STDMETHODIMP Hello()
	{
		::MessageBox(NULL, _T("Hello"), _T("Sink"), MB_OK);
		return S_OK;
	}
};

void InitializeSecurityWithAccessControl();

void sub()
{
	CComPtr<CComObject<CCallMe> > spCallMe;
	HRESULT hr = CComObject<CCallMe>::CreateInstance(&spCallMe);
	_ASSERT (SUCCEEDED(hr));
	spCallMe->InternalAddRef();

	/*
	hr = ::CoInitializeSecurity(
		NULL,
		-1,
		NULL,
		NULL,
		RPC_C_AUTHN_LEVEL_DEFAULT,
		RPC_C_IMP_LEVEL_IDENTIFY,
		NULL,
		EOAC_NONE,
		NULL);
	_ASSERT (SUCCEEDED(hr));
	*/
	InitializeSecurityWithAccessControl();


	SERVERXLib::IMyServerXPtr spSvrX(__uuidof(SERVERXLib::MyServerX));
	spSvrX->Advise(reinterpret_cast<SERVERXLib::ICallMe*>(static_cast<ICallMe*>(spCallMe)));
}

void InitializeSecurityWithAccessControl()
{
	CComPtr<IAccessControl> spAC;

	HRESULT hr = ::CoCreateInstance(CLSID_DCOMAccessControl, NULL,
		CLSCTX_INPROC_SERVER, IID_IAccessControl, (void**) &spAC);
	_ASSERT (SUCCEEDED(hr));

	ACTRL_ACCESSW access;
	ACTRL_PROPERTY_ENTRYW propEntry;
	access.cEntries = 1;
	access.pPropertyAccessList = &propEntry;

	ACTRL_ACCESS_ENTRY_LISTW entryList;
	propEntry.lpProperty = NULL;
	propEntry.pAccessEntryList = &entryList;
	propEntry.fListFlags = 0;

	ACTRL_ACCESS_ENTRYW entry;
	entryList.cEntries = 1;
	entryList.pAccessList = &entry;

	// Set up the ACE
	entry.Access = COM_RIGHTS_EXECUTE;
	entry.ProvSpecificAccess = 0;
	entry.Inheritance = NO_INHERITANCE;
	entry.lpInheritProperty = NULL;

	// allow access to "usera"
	entry.fAccessFlags = ACTRL_ACCESS_ALLOWED;
	entry.Trustee.TrusteeForm = TRUSTEE_IS_NAME;
	entry.Trustee.TrusteeType = TRUSTEE_IS_USER;
	entry.Trustee.ptstrName = L"PVHOME\\userb";
	entry.Trustee.pMultipleTrustee = NULL;
	entry.Trustee.MultipleTrusteeOperation = NO_MULTIPLE_TRUSTEE;

	hr = spAC->GrantAccessRights(&access);
	_ASSERT (SUCCEEDED(hr));

	hr = ::CoInitializeSecurity(
		static_cast<IAccessControl*>(spAC),
		-1,
		NULL,
		NULL,
		RPC_C_AUTHN_LEVEL_DEFAULT,
		RPC_C_IMP_LEVEL_IDENTIFY,
		NULL,
		EOAC_ACCESS_CONTROL,
		NULL);
	_ASSERT (SUCCEEDED(hr));

}
