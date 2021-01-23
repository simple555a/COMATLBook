#include "StdAfx.h"
#include <crtdbg.h>

extern "C" int WINAPI WinMain(HINSTANCE hInstance, 
    HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int /*nShowCmd*/)
{
	DebugBreak();
	::CoInitialize(NULL);
	g_MyModule.Init(hInstance);

	if (0==lstrcmpi(lpCmdLine, "-Regserver")) {
		g_MyModule.RegisterServer();
		::CoUninitialize();
		return 0;
	}

	if (0==lstrcmpi(lpCmdLine, "-Unregserver")) {
		g_MyModule.UnregisterServer();
		::CoUninitialize();
		return 0;
	}

	
	// Register the class object
	HRESULT hRes = g_MyModule.RegisterClassObject();
	_ASSERT(SUCCEEDED(hRes));

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0)) {
		DispatchMessage(&msg);
	}

	g_MyModule.RevokeClassObject();

	::CoUninitialize();
	return 0;
}

