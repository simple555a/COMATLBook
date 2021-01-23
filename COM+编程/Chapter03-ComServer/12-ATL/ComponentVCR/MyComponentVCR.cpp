// MyComponentVCR.cpp : Implementation of CComponentVCRApp and DLL registration.

#include "stdafx.h"
#include "ComponentVCR.h"
#include "MyComponentVCR.h"

/////////////////////////////////////////////////////////////////////////////
//

CComponentVCR::CComponentVCR()
{
	m_lCurValue = 5; 
	m_nCurCount = 0;
}

STDMETHODIMP CComponentVCR::GetCVideoSignalValue(long *pRetVal)
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
