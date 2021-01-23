// File vcr.cpp

#include "StdAfx.h"
#include "Vcr.h"
#include "../ComponentVCR/ComponentVideo.h"
#include "../ComponentVCR/ComponentVideo_i.c"

CVcr:: CVcr()
{ 
	m_lCurValue = 5; 
	m_nCurCount = 0;

	m_lRefCount = 0;

	g_MyModule.lCount++;

	m_pUnkInner = NULL;
}

HRESULT CVcr::Init()
{
	HRESULT hr = ::CoCreateInstance(
		CLSID_ComponentVCR,
		GetRawUnknown(),
		CLSCTX_ALL,
		IID_IUnknown,
		reinterpret_cast<void**>(&m_pUnkInner));

	return hr;
}

CVcr::~CVcr()
{
	if (NULL != m_pUnkInner) {
		m_pUnkInner->Release();
	}

	g_MyModule.lCount--;
}

STDMETHODIMP CVcr::QueryInterface(REFIID iid, void** ppRetVal)
{
	*ppRetVal = NULL;

	if (IsEqualIID(iid, IID_IUnknown)) {
		*ppRetVal = GetRawUnknown();
	}else
	if (IsEqualIID(iid, IID_IVideo)) {
		*ppRetVal = static_cast<IVideo*>(this);
	}else
	if (IsEqualIID(iid, IID_ISVideo)) {
		*ppRetVal = static_cast<ISVideo*>(this);
	}else	
	if (IsEqualIID(iid, IID_IComponentVideo)) {
		return m_pUnkInner->QueryInterface(iid, ppRetVal);
	}

	if (NULL != (*ppRetVal)) {
		AddRef();
		return S_OK;
	}

	return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CVcr::AddRef()
{
	return (++m_lRefCount);
}

STDMETHODIMP_(ULONG) CVcr::Release()
{
	ULONG lRetVal = (--m_lRefCount);
	if (0 == lRetVal) {
		delete this;
	}
	return lRetVal;
}
    

HRESULT CVcr::GetSignalValue(long* pRetVal)
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
	m_lCurValue += 10;
	*pRetVal = lReturnValue;
	return S_OK;
}

HRESULT CVcr::GetSVideoSignalValue(long* pRetVal)
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
	m_lCurValue += 20;
	*pRetVal = lReturnValue;
	return S_OK;
}

