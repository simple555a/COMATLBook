#include "Video.h"
#include "ClassObject.h"
#include "Video_i.c"

// Returns the requested interface for the requested clsid

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	if (!IsEqualIID(rclsid, CLSID_VCR)) {
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	static CVcrClassObject* g_pVCRClassObject = NULL;

	if (NULL == g_pVCRClassObject) {
		g_pVCRClassObject = new CVcrClassObject;
		if (NULL == g_pVCRClassObject) {
			return E_OUTOFMEMORY;
		}
		g_pVCRClassObject->AddRef(); // Keep the pointer alive for server lifetime
	}

	HRESULT hr = g_pVCRClassObject->QueryInterface(riid, ppv);

	return hr;
}

