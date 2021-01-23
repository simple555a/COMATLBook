// WzdSubscribe.cpp : Implementation of CWzdSubscribe
#include "stdafx.h"
#include "Scribe.h"
#include "WzdSubscribe.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdSubscribe


STDMETHODIMP CWzdSubscribe::WzdEvent(long lArg)
{
	::MessageBox(NULL,"Bang!","Scribe",0);

	return S_OK;
}
