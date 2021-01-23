// File vcr.cpp

#include "vcr.h"

CVcr::CVcr()
{ 
	m_lCurValue = 5; 
	m_nCurCount = 0;
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

void CVcr::Delete()
{
	delete this;
}


IVideo* _stdcall CreateVCR(void)
{
	return new CVcr;
}

