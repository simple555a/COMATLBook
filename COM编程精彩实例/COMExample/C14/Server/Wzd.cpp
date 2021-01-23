// Wzd.cpp : Implementation of CWzd
#include "stdafx.h"
#include "Server.h"
#include "Wzd.h"

/////////////////////////////////////////////////////////////////////////////
// CWzd


STDMETHODIMP CWzd::Method1(long lArg)
{
	Fire_WzdSink(1234);

	return S_OK;
}
