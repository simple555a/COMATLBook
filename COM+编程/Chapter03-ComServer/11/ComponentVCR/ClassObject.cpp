// File ClassObject.cpp

#include "StdAfx.h"
#include "ComponentVcr.h"
#include "ClassObject.h"

CComponentVcrClassObject::CComponentVcrClassObject()
{ 
	m_lRefCount = 0;
}

CComponentVcrClassObject::~CComponentVcrClassObject()
{
}

STDMETHODIMP CComponentVcrClassObject::QueryInterface(REFIID iid, void** ppRetVal)
{
	*ppRetVal = NULL;

	if (IsEqualIID(iid, IID_IUnknown)) {
		*ppRetVal = static_cast<IUnknown*>(this);
	}else
	if (IsEqualIID(iid, IID_IClassFactory)) {
		*ppRetVal = static_cast<IClassFactory*>(this);
	}

	if (NULL != (*ppRetVal)) {
		AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CComponentVcrClassObject::AddRef()
{
	long lRetVal = (++m_lRefCount);
	if (lRetVal == 2) {
        // a client is requesting for a AddRef
		g_MyModule.lCount++;
	}
	return lRetVal;
}

STDMETHODIMP_(ULONG) CComponentVcrClassObject::Release()
{
	ULONG lRetVal = (--m_lRefCount);
	if (1 == lRetVal) {
		// all clients have released the references
		g_MyModule.lCount--;
	}else
	if (0 == lRetVal) {
		delete this;
	}
	return lRetVal;
}
    

STDMETHODIMP CComponentVcrClassObject::CreateInstance(
	IUnknown* pUnkOuter,
	REFIID riid,
	void** ppV)
{
	*ppV = NULL; // always initialize the return value

	if (NULL != pUnkOuter) {
		return CLASS_E_NOAGGREGATION;
	}

	CComponentVcr* pVCR = new CComponentVcr;
	if (NULL == pVCR) {
		return E_OUTOFMEMORY;
	}

	HRESULT hr = pVCR->QueryInterface(riid, ppV);
	if (FAILED(hr)) {
		delete pVCR;
	}
	return hr;
}

STDMETHODIMP CComponentVcrClassObject::LockServer(BOOL fLock)
{
	if (TRUE == fLock) {
		g_MyModule.lCount++;
	}else {
		g_MyModule.lCount--;
	}

	return S_OK;
}

