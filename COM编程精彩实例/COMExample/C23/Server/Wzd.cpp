// Wzd.cpp : Implementation of CWzd
#include "stdafx.h"
#include "comdef.h"
#include "Server.h"
#include "Wzd.h"

/////////////////////////////////////////////////////////////////////////////
// CWzd


//////////////////////////////////////////////////////////////////////////
////////////////     PASSING SIMPLE DATA    ///////////////////////////
//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CWzd::Method1(long lArg)
{
	m_lSave=lArg;

	return S_OK;
}

