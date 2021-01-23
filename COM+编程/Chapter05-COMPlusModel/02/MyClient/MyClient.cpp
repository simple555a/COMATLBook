// MyClient.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "../TestC/TestC.tlb"
using namespace TESTCLib;

enum INSTANTIATIONTYPE {
	LOCAL_MACHINE,
	REMOTE_MACHINE
};


void Sub(INSTANTIATIONTYPE iType);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	try {
		Sub(REMOTE_MACHINE);
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), _T("Client"), MB_OK);
	}

	::CoUninitialize();

	return 0;
}

void Sub(INSTANTIATIONTYPE iType)
{
	IUnknownPtr spUnk;

	LPOLESTR pwszMach = (LOCAL_MACHINE == iType) ? NULL : OLESTR("PVDC");

	HRESULT hr = CPLCreateInstance(pwszMach, __uuidof(MyTestC), &spUnk);
	if (FAILED(hr)) {
		::MessageBox(NULL, _T("Instantiation failed"), _T("Client"), MB_OK);
		return;
	}

	IMyTestCPtr spTestC;
	hr = spUnk->QueryInterface(&spTestC);
	if (FAILED(hr)) {
		::MessageBox(NULL, _T("Interface not found"), _T("Client"), MB_OK);
		return;
	}

	_bstr_t retVal = spTestC->DoIt();
	::MessageBox(NULL, retVal, _T("Client"), MB_OK);
}
	

