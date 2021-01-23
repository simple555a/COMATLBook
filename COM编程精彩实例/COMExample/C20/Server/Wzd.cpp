// Wzd.cpp : Implementation of CWzd
#include "stdafx.h"
#include "WzdSrv.h"
#include "Wzd.h"

extern HANDLE ghNow, ghDie, ghDone;
extern long glArg;
/////////////////////////////////////////////////////////////////////////////
// CWzd


STDMETHODIMP CWzd::Method1(long lArg)
{
	glArg=lArg;
	SetEvent(ghNow);
	return S_OK;
}
