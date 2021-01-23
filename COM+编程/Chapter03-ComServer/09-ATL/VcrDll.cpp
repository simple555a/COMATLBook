// File VcrDll.cpp

#include "StdAfx.h"
#include "Video.h"
#include "Video_i.c"
#include "Vcr.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
	OBJECT_ENTRY(CLSID_VCR, CVcr)
END_OBJECT_MAP()

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (DLL_PROCESS_ATTACH == dwReason) {
		_Module.Init(ObjectMap, hInstance, NULL);
	}else
	if (DLL_PROCESS_DETACH == dwReason) {
		_Module.Term();
	}

    return TRUE;    // ok
}

// Returns the requested interface for the requested clsid

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	return _Module.GetClassObject(rclsid, riid, ppv);
}

// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	return _Module.RegisterServer();
}


// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	return _Module.UnregisterServer();
}

// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

