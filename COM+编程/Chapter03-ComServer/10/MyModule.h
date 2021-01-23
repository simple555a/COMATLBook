// File MyModule.h

#pragma once

class CVcrClassObject; // forward declaration

class CMyModule
{
public:
	CMyModule();
	~CMyModule();

	// Initialize the object
	HRESULT Init(HINSTANCE hInst);

	// Cleanup the object
	void Term();

	// HINSTANCE access
	HINSTANCE GetModuleInstance(){return m_hInstance; }

	// Global count access
	LONG Lock();
	LONG Unlock();
	LONG GetLockCount(){ return m_lCount; }

	// Class object access (for DLL)
	HRESULT GetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv);

	// Class object registration (for EXE)
	HRESULT RegisterClassObject();
	HRESULT RevokeClassObject();

	// Registration routines
	HRESULT RegisterServer();
	HRESULT UnregisterServer();

	// Registry helper
	static HRESULT AddRegistryEntry(LPCTSTR pszSubKey, LPCTSTR pszValueName, LPCTSTR pszValue);
	static HRESULT DeleteRegistryKey(HKEY hKeyParent, LPCTSTR pszSubKey);

private:
	HINSTANCE m_hInstance;
	CVcrClassObject* m_pVCRClassObject;
	LONG m_lCount;
	DWORD m_dwVcr;
	DWORD m_dwThreadId;
};

extern CMyModule g_MyModule;

