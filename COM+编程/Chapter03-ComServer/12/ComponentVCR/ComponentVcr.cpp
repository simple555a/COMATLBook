// File ComponentVcr.cpp

#include "StdAfx.h"
#include "ComponentVcr.h"

CComponentVcr:: CComponentVcr()
{ 
	m_lCurValue = 5; 
	m_nCurCount = 0;

	m_lRefCount = 0;

	g_MyModule.lCount++;

	m_pUnkActual = NULL;
}

HRESULT CComponentVcr::Init(IUnknown* pUnkOuter)
{
	if (NULL == pUnkOuter) {
		m_pUnkActual = &m_NDUnknown;
	}else {
		m_pUnkActual = pUnkOuter;
	}
	return S_OK;
}

CComponentVcr::~CComponentVcr()
{
	g_MyModule.lCount--;
}

STDMETHODIMP CComponentVcr::InternalQueryInterface(REFIID iid, void** ppRetVal)
{
	*ppRetVal = NULL;

	if (IsEqualIID(iid, IID_IUnknown)) {
		*ppRetVal = static_cast<IUnknown*>(&m_NDUnknown);
	}else
	if (IsEqualIID(iid, IID_IComponentVideo)) {
		*ppRetVal = static_cast<IComponentVideo*>(this);
	}

	if (NULL != (*ppRetVal)) {
		reinterpret_cast<IUnknown*>(*ppRetVal)->AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CComponentVcr::InternalAddRef()
{
	return (++m_lRefCount);
}

STDMETHODIMP_(ULONG) CComponentVcr::InternalRelease()
{
	ULONG lRetVal = (--m_lRefCount);
	if (0 == lRetVal) {
		delete this;
	}
	return lRetVal;
}
HRESULT CComponentVcr::GetCVideoSignalValue(long* pRetVal)
{
	if (m_nCurCount >= 5 || m_nCurCount < 0) {
		return E_UNEXPECTED;
	}

	m_nCurCount++;
	if (5 == m_nCurCount ) {
		m_lCurValue = 5;
		m_nCurCount = 1;
	}

	long lReturnValue = m_lCurValue;
	m_lCurValue += 30;
	*pRetVal = lReturnValue;
	return S_OK;
}


