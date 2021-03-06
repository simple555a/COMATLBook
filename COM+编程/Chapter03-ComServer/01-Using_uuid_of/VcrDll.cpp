#include "Vcr.h"


// Returns the requested interface for the requested clsid

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    if (!IsEqualIID(rclsid, __uuidof(VCR))) {
		return CLASS_E_CLASSNOTAVAILABLE;
	}

	CVcr* pVCR = new CVcr;
	if (NULL == pVCR) {
		return E_OUTOFMEMORY;
	}

	HRESULT hr = pVCR->QueryInterface(riid, ppv);
	if (FAILED(hr)) {
		delete pVCR;
	}

	return hr;
}

