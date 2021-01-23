// Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "c:\winnt\system32\comsvcs.dll"
using namespace COMSVCSLib;

void sub1();
void sub2();

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CCPLComInitializer init;

	try {
		sub1();
		sub2();
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	return 0;
}

void sub1()
{
	ISharedPropertyGroupManagerPtr spGroupMgr;
	HRESULT hr = spGroupMgr.CreateInstance(__uuidof(SharedPropertyGroupManager));
	if (FAILED(hr)) {
		_com_issue_error(hr);
	}

	long lIsoMode = LockSetGet;
	long lRelMode = Process;
	VARIANT_BOOL bExists;
	ISharedPropertyGroupPtr spGroup =
		spGroupMgr->CreatePropertyGroup("LicenseInfo", 
		&lIsoMode, &lRelMode, &bExists);

	ISharedPropertyPtr spProperty = spGroup->CreateProperty("Key", &bExists);
	spProperty->Value = "MyMagicNumber1234";
}

void sub2()
{
	ISharedPropertyGroupManagerPtr spGroupMgr;
	HRESULT hr = spGroupMgr.CreateInstance(__uuidof(SharedPropertyGroupManager));
	if (FAILED(hr)) {
		_com_issue_error(hr);
	}

	ISharedPropertyGroupPtr spGroup = spGroupMgr->GetGroup("LicenseInfo");
	ISharedPropertyPtr spProperty = spGroup->GetProperty("Key");
	::MessageBox(NULL, _bstr_t(spProperty->Value), _T("License Key"), MB_OK);
}

