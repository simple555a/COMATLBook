// File vcr.cpp

#include "vcr.h"
#include <string.h>

CVcr:: CVcr()
{ 
	m_lCurValue = 5; 
	m_nCurCount = 0;

	m_lRefCount = 0;
}

CVcr::~CVcr()
{
}

VRESULT CVcr::Probe(char* pszType, IGeneral** ppRetVal)
{
	*ppRetVal = NULL;
	if (!stricmp(pszType, "general")) {
		*ppRetVal = static_cast<IVideo*>(this);
	}else
	if (!stricmp(pszType, "video")) {
		*ppRetVal = static_cast<IVideo*>(this);
	}else
	if (!stricmp(pszType, "svideo")) {
		*ppRetVal = static_cast<ISVideo*>(this);
	}	

	if (NULL != (*ppRetVal)) {
		AddReference();
		return V_OK;
	}

	return V_NOINTERFACE;
}
    

VRESULT CVcr::GetSignalValue(long* pRetVal)
{
	if (m_nCurCount >= 5 || m_nCurCount < 0) {
		return V_INTERNALERROR;
	}

	m_nCurCount++;
	if (5 == m_nCurCount ) {
		m_lCurValue = 5;
		m_nCurCount = 1;
	}

	long lReturnValue = m_lCurValue;
	m_lCurValue += 10;
	*pRetVal = lReturnValue;
	return V_OK;
}

VRESULT CVcr::GetSVideoSignalValue(long* pRetVal)
{
	if (m_nCurCount >= 5 || m_nCurCount < 0) {
		return V_INTERNALERROR;
	}

	m_nCurCount++;
	if (5 == m_nCurCount ) {
		m_lCurValue = 5;
		m_nCurCount = 1;
	}

	long lReturnValue = m_lCurValue;
	m_lCurValue += 20;
	*pRetVal = lReturnValue;
	return V_OK;
}

void CVcr::AddReference()
{
	++m_lRefCount;
}

void CVcr::Delete()
{
	if ( (--m_lRefCount) == 0) {
		delete this;
	}
}


VRESULT _stdcall CreateVCR(char* pszType, IGeneral** ppRetVal)
{
	*ppRetVal = NULL;

	CVcr* pVcr = new CVcr;
	if (NULL == pVcr) {
		return V_OUTOFMEMORY;
	}

	VRESULT vr = pVcr->Probe(pszType, ppRetVal);
	if (V_FAILED(vr)) {
		delete pVcr;
	}
	
	return vr;
}

