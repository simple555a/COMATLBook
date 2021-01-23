// File MyModule.cpp

#include "StdAfx.h"
#include "ClassObject.h"
#include "Video.h"
#include "Video_i.c"
#include <crtdbg.h>

CMyModule::CMyModule()
{
	m_hInstance = NULL;
	m_pVCRClassObject = NULL;
	m_lCount = 0;
}

HRESULT CMyModule::Init(HINSTANCE hInst)
{
	m_hInstance = hInst;
	return S_OK;
}

CMyModule::~CMyModule()
{
	_ASSERT (NULL == m_pVCRClassObject);
	_ASSERT (0 == m_lCount);
}

void CMyModule::Term()
{
	if (NULL != m_pVCRClassObject) {
		m_pVCRClassObject->Release();
		m_pVCRClassObject = NULL;
	}
	_ASSERT (0 == m_lCount);
}

//
// Global count access
//

LONG CMyModule::Lock()
{
	return ++m_lCount;
}

LONG CMyModule::Unlock()
{
	return --m_lCount;
}

//
// Class object access
//
HRESULT CMyModule::GetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	if (!IsEqualIID(rclsid, CLSID_VCR)) {
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	if (NULL == m_pVCRClassObject) {
		m_pVCRClassObject = new CVcrClassObject;
		if (NULL == m_pVCRClassObject) {
			return E_OUTOFMEMORY;
		}
		m_pVCRClassObject->AddRef(); // Keep the pointer alive for server lifetime
	}

	return m_pVCRClassObject->QueryInterface(riid, ppv);
}

HRESULT CMyModule::AddRegistryEntry(LPCTSTR pszSubKey, LPCTSTR pszValueName, LPCTSTR pszValue)
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

HRESULT CMyModule::DeleteRegistryKey(HKEY hParentKey, LPCTSTR pszSubKey)
{
	HKEY hKey;
	LONG lRes = ::RegOpenKeyEx(hParentKey, pszSubKey, 0, KEY_READ|KEY_WRITE, &hKey);
	if (lRes != ERROR_SUCCESS) {
		return HRESULT_FROM_WIN32(lRes);
	}

	FILETIME time;
	const BUFSIZE = 256;
	DWORD dwSize = BUFSIZE;
	TCHAR szBuffer[BUFSIZE];
	while (RegEnumKeyEx(hKey, 0, szBuffer, &dwSize, NULL, NULL, NULL,
		&time)==ERROR_SUCCESS)
	{
		lRes = DeleteRegistryKey(hKey, szBuffer);
		if (lRes != ERROR_SUCCESS) {
			::RegCloseKey(hKey);
			return HRESULT_FROM_WIN32(lRes);
		}
		dwSize = BUFSIZE;
	}
	::RegCloseKey(hKey);
	lRes = ::RegDeleteKey(hParentKey, pszSubKey);
	return HRESULT_FROM_WIN32(lRes);
}


// RegisterServer - Adds entries to the system registry

HRESULT CMyModule::RegisterServer(void)
{
	// Remove old entries first
	UnregisterServer();

	// Add New entries
	TCHAR szPath[MAX_PATH];
	::GetModuleFileName(m_hInstance, szPath, sizeof(szPath)/sizeof(TCHAR));
	HRESULT hr = AddRegistryEntry(
		"CLSID\\{318B4AD3-06A7-11d3-9B58-0080C8E11F14}\\InprocServer32", "", szPath);
	return hr;
}


// UnregisterServer - Removes entries from the system registry

HRESULT CMyModule::UnregisterServer(void)
{
	DeleteRegistryKey(HKEY_CLASSES_ROOT,
		"CLSID\\{318B4AD3-06A7-11d3-9B58-0080C8E11F14}");
	return S_OK;
}

