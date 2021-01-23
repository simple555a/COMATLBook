// Vcr.cpp : Implementation of CMyVCRApp and DLL registration.

#include "stdafx.h"
#include "MyVCR.h"
#include "Vcr.h"

/////////////////////////////////////////////////////////////////////////////
//

CVcr::CVcr()
{
	m_lCurValue = 5; 
	m_nCurCount = 0;
}

STDMETHODIMP CVcr::GetSignalValue(long *pRetVal)
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

STDMETHODIMP CVcr::GetSVideoSignalValue(long *pRetVal)
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
