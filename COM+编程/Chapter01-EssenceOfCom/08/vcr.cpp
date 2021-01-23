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

IGeneral* CVcr::Probe(char* pszType)
{
	IGeneral* p = NULL;
	if (!stricmp(pszType, "general")) {
		p = static_cast<IVideo*>(this);
	}else	
	if (!stricmp(pszType, "video")) {
		p = static_cast<IVideo*>(this);
	}else	
	if (!stricmp(pszType, "svideo")) {
		p = static_cast<ISVideo*>(this);
	}	

	if (NULL != p) {
		AddReference();
	}

	return p;
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


IGeneral* _stdcall CreateVCR(void)
{
	CVcr* p = new CVcr;
	p->AddReference();
	
	return  static_cast<IVideo*>(p);
}

