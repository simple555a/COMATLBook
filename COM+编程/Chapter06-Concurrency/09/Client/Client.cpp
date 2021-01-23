// Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "..\SingletonExample\SingletonExample.tlb"
using namespace SINGLETONEXAMPLELib;

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
	IMySingletonPtr spSingleton;
	HRESULT hr = spSingleton.CreateInstance(__uuidof(MySingleton));
	if (FAILED(hr)) {
		_com_issue_error(hr);
	}
	spSingleton->LicenseKey = "MyMagicNumber1234";
}

void sub2()
{
	IMySingletonPtr spSingleton;
	HRESULT hr = spSingleton.CreateInstance(__uuidof(MySingleton));
	if (FAILED(hr)) {
		_com_issue_error(hr);
	}
	::MessageBox(NULL, spSingleton->LicenseKey, _T("License Key"), MB_OK);

}



