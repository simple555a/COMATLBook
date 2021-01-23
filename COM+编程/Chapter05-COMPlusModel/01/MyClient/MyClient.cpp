// MyClient.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "../TestB/TestB.tlb"
using namespace TESTBLib; 

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	::CoInitialize(NULL);

	IMyTestBPtr sp;
	HRESULT hr = sp.CreateInstance(__uuidof(MyTestB));
	if (SUCCEEDED(hr)) {
		sp->DoIt();
	}
	sp = NULL;
	::CoUninitialize();

	return 0;
}



