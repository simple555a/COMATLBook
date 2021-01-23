// File ClassObject.cpp

#include "StdAfx.h"
#include "Vcr.h"
#include "ClassObject.h"

CVcrClassObject::CVcrClassObject()
{ 
	m_lRefCount = 0;
}

CVcrClassObject::~CVcrClassObject()
{
}

STDMETHODIMP CVcrClassObject::QueryInterface(REFIID iid, void** ppRetVal)
{
	*ppRetVal = NULL;

	if (IsEqualIID(iid, IID_IUnknown)) {
		*ppRetVal = GetUnknown();
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

STDMETHODIMP_(ULONG) CVcrClassObject::AddRef()
{
	return ++m_lRefCount;
}

STDMETHODIMP_(ULONG) CVcrClassObject::Release()
{
	ULONG lRetVal = (--m_lRefCount);
	if (0 == lRetVal) {
		delete this;
	}
	return lRetVal;
}
    

STDMETHODIMP CVcrClassObject::CreateInstance(
	IUnknown* pUnkOuter,
	REFIID riid,
	void** ppV)
{
	*ppV = NULL; // always initialize the return value

	if (NULL != pUnkOuter) {
		return CLASS_E_NOAGGREGATION;
	}

	CVcr* pVCR = new CVcr;
	if (NULL == pVCR) {
		return E_OUTOFMEMORY;
	}

	HRESULT hr = pVCR->QueryInterface(riid, ppV);
	if (FAILED(hr)) {
		delete pVCR;
	}
	return hr;
}

STDMETHODIMP CVcrClassObject::LockServer(BOOL fLock)
{
	if (TRUE == fLock) {
		g_MyModule.Lock();
	}else {
		g_MyModule.Unlock();
	}

	return S_OK;
}

