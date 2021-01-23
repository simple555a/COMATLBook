// File VcrDll.cpp

#include "StdAfx.h"

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (DLL_PROCESS_ATTACH == dwReason) {
		g_MyModule.Init(hInstance);
	}else
	if (DLL_PROCESS_DETACH == dwReason) {
		g_MyModule.Term();
	}

    return TRUE;    // ok
}

// Returns the requested interface for the requested clsid

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return g_MyModule.GetClassObject(rclsid, riid, ppv);
}

// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	return g_MyModule.RegisterServer();
}


// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	return g_MyModule.UnregisterServer();
}

// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (g_MyModule.GetLockCount()==0) ? S_OK : S_FALSE;
}

