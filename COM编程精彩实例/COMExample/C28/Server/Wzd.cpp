// Wzd.cpp : Implementation of CWzd
#include "stdafx.h"
#include "Server.h"
#include "Wzd.h"

/////////////////////////////////////////////////////////////////////////////
// CWzd


STDMETHODIMP CWzd::Method1(long lArg)
{

	Fire_Callback(4321);

	return S_OK;
}
