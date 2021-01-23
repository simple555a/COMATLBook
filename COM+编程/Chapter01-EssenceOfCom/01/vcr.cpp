#include "vcr.h"

CVcr:: CVcr ()
{ 
	m_lCurValue = 5; 
}

long CVcr::GetSignalValue()
{
	long lReturnValue = m_lCurValue;
	m_lCurValue += 10;
	return lReturnValue;
}

