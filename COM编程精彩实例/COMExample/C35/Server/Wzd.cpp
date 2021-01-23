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

STDMETHODIMP CWzd::Simple1(BYTE byArg, short sArg, long lArg)
{

	return S_OK;
}

STDMETHODIMP CWzd::Simple2(float fArg, double dArg)
{

	return S_OK;
}

STDMETHODIMP CWzd::Simple3(long lArg1,long* lArg2,long* lArg3)
{
	*lArg2=543;
	*lArg3=987;
	return S_OK;
}
//////////////////////////////////////////////////////////////////////////
////////////////     PASSING ARRAYS       ///////////////////////////
//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CWzd::Array1(long lFirst, long lLast, long lSize, long *aArg)
{
	for (int i=lFirst;i<=lLast;i++)
	{
		int j=aArg[i];
	}
	return S_OK;
}

STDMETHODIMP CWzd::Array2(long lFirst, long lLength, long lSize, long *aArg)
{						
	for (int i=lFirst;i<(lFirst+lLength);i++)
	{
		int j=aArg[i];
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////
////////////////     PASSING VISUAL BASIC VARIABLES /////////////////////
//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CWzd::VBVars1(BSTR bstr, BSTR* pBSTR)
{
	*pBSTR=::SysAllocString(L"return");
	return S_OK;
}

STDMETHODIMP CWzd::VBVars2(SAFEARRAY** pSA)
{
	return S_OK;
}

STDMETHODIMP CWzd::VBVars3(VARIANT* pVAR1,VARIANT* pVAR2,VARIANT* pVAR3)
{
	// get input long
	_variant_t vartMyVariant1(*pVAR1);
	long lLong=long(vartMyVariant1);

	// get input string
	_variant_t vartMyVariant2(*pVAR2);
	_bstr_t bstrtMyString=_bstr_t(vartMyVariant2);

	// get input safearray using V_xxx macros (other types can be found in OLEAUTO.H)
	if (V_VT(pVAR3)==(VT_ARRAY | VT_UI1 | VT_BYREF))
		SAFEARRAY **saMySafeArray=V_ARRAYREF(pVAR3);

	return S_OK;
}

STDMETHODIMP CWzd::VBVars4(long *pVal)
{
	*pVal=1234;
	return S_OK;
}

