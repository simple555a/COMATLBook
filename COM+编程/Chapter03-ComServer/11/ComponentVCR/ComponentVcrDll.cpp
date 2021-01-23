// File VcrDll.cpp

#include "StdAfx.h"
#include "ComponentVideo.h"
#include "ClassObject.h"
#include "ComponentVideo_i.c"

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID /*lpReserved*/)
{
	if (DLL_PROCESS_ATTACH == dwReason) {
		g_MyModule.hInstance = hInstance;
	}else
	if (DLL_PROCESS_DETACH == dwReason) {
		if (NULL != g_MyModule.pVCRClassObject) {
			g_MyModule.pVCRClassObject->Release();
		}
	}

    return TRUE;    // ok
}

// Returns the requested interface for the requested clsid

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	if (!IsEqualIID(rclsid, CLSID_ComponentVCR)) {
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	if (NULL == g_MyModule.pVCRClassObject) {
		g_MyModule.pVCRClassObject = new CComponentVcrClassObject;
		if (NULL == g_MyModule.pVCRClassObject) {
			return E_OUTOFMEMORY;
		}
		g_MyModule.pVCRClassObject->AddRef(); // Keep the pointer alive for server lifetime
	}

	HRESULT hr = g_MyModule.pVCRClassObject->QueryInterface(riid, ppv);

	return hr;
}

HRESULT AddRegistryEntry(LPCTSTR pszSubKey, LPCTSTR pszValueName, LPCTSTR pszValue)
{
	HKEY hSubKey = NULL;
	LONG lRetVal = ::RegCreateKey(HKEY_CLASSES_ROOT, pszSubKey, &hSubKey);
	if (ERROR_SUCCESS != lRetVal) {
		return HRESULT_FROM_WIN32(lRetVal);
	}

	int len = lstrlen(pszValue) + 1; // include terminating NULL char
	lRetVal = ::RegSetValueEx(hSubKey, pszValueName, 0, REG_SZ, reinterpret_cast<const BYTE*>(pszValue), len);
	::RegCloseKey(hSubKey);
	return HRESULT_FROM_WIN32(lRetVal);
}


// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	TCHAR szPath[MAX_PATH];
	::GetModuleFileName(g_MyModule.hInstance, szPath, sizeof(szPath)/sizeof(TCHAR));
	HRESULT hr = AddRegistryEntry(
		"CLSID\\{318B4AD6-06A7-11d3-9B58-0080C8E11F14}\\InprocServer32", "", szPath);
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	long lRetVal = ::RegDeleteKey(HKEY_CLASSES_ROOT, 
		"CLSID\\{318B4AD6-06A7-11d3-9B58-0080C8E11F14}\\InprocServer32");
	if (ERROR_SUCCESS != lRetVal) {
		return HRESULT_FROM_WIN32(lRetVal);
	}
	lRetVal = ::RegDeleteKey(HKEY_CLASSES_ROOT, 
      "CLSID\\{318B4AD6-06A7-11d3-9B58-0080C8E11F14}");
	return HRESULT_FROM_WIN32(lRetVal);
	
}

// Used to determine whether the DLL can be unloaded by OLE

STDAPI DllCanUnloadNow(void)
{
    return (g_MyModule.lCount==0) ? S_OK : S_FALSE;
}

