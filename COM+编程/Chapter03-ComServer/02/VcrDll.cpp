#include "Vcr.h"
#include "Video_i.c"

// Returns the requested interface for the requested clsid

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    if (!IsEqualIID(rclsid, CLSID_VCR)) {
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	static CVcr* g_pVCR = NULL;

	if (NULL == g_pVCR) {
		g_pVCR = new CVcr;
		if (NULL == g_pVCR) {
			return E_OUTOFMEMORY;
		}
		g_pVCR->AddRef(); // Keep the pointer alive for server lifetime
	}

	HRESULT hr = g_pVCR->QueryInterface(riid, ppv);

	return hr;
}

