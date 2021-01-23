// File vcr.cpp

#include "vcr.h"
#include <string.h>

CVcr:: CVcr ()
{ 
	m_lCurValue = 5; 
	m_nCurCount = 0;
}

IGeneral* CVcr::Probe(char* pszType)
{
	if (!stricmp(pszType, "general")) {
		IGeneral* p = static_cast<IVideo*>(this);
		return p;
	}	
	if (!stricmp(pszType, "video")) {
		IVideo* p = this;
		return p;
	}	
	if (!stricmp(pszType, "svideo")) {
		ISVideo* p = this;
		return p;
	}	

	return NULL;
}
    

long CVcr::GetSignalValue()
{
	m_nCurCount++;
	if (5 == m_nCurCount ) {
		m_lCurValue = 5;
		m_nCurCount = 1;
	}

	long lReturnValue = m_lCurValue;
	m_lCurValue += 10;
	return lReturnValue;
}

long CVcr::GetSVideoSignalValue()
{
	m_nCurCount++;
	if (5 == m_nCurCount ) {
		m_lCurValue = 5;
		m_nCurCount = 1;
	}

	long lReturnValue = m_lCurValue;
	m_lCurValue += 20;
	return lReturnValue;
}

void CVcr::Delete()
{
	delete this;
}


IGeneral* _stdcall CreateVCR(void)
{
	return static_cast<IVideo*>(new CVcr);
}

