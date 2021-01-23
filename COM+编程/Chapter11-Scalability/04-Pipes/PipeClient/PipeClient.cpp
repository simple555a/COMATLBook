// PipeClient.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

void sub();

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CCPLComInitializer init;

	try {
		sub();
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	return 0;
}

using namespace PIPESVRLib;

_COM_SMARTPTR_TYPEDEF(IPipeLong, __uuidof(IPipeLong));

void DisplayValue(long l)
{
	// do something
}

void sub()
{
	// Instantiate the object
	IUnknownPtr spUnk(__uuidof(MyPipeSvr));

	// Obtain the IPipeLong interface
	IPipeLongPtr spPipe = spUnk;

	// Push data to the pipe
	const int BUFSIZE = 100000;
	LONG buf[BUFSIZE];
	for (long i=0; i<BUFSIZE; i++) {
		buf[i] = i;
	}

	HRESULT hr = spPipe->Push(buf, BUFSIZE);
	if (FAILED(hr)) {
		_com_issue_error(hr);
	}
	::MessageBox(NULL, _T("Sent data"), _T("Client"), MB_OK);
}




