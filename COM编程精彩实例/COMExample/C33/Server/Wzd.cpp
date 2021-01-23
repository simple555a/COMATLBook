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

STDMETHODIMP CWzd::Simple1(unsigned char cArg, short sArg, long lArg)
{

	return S_OK;
}

STDMETHODIMP CWzd::Simple2(float fArg, double dArg )
{

	return S_OK;
}


//////////////////////////////////////////////////////////////////////////
////////////////     PASSING VISUAL BASIC VARIABLES /////////////////////
//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CWzd::VBVars1(BSTR* pBSTR)
{
	// get string from input
	_bstr_t bstrtInput(*pBSTR);

	// return a string
	*pBSTR=::SysAllocString(L"Return");
	return S_OK;
}

STDMETHODIMP CWzd::VBVars2(SAFEARRAY** pSA)
{
	// get input array
	LPBYTE lpByte=NULL;
	::SafeArrayAccessData(
			*pSA,	//safearray vector from above
			(LPVOID*)&lpByte);		//pointer
	lpByte[0]=12;
	lpByte[1]=34;
	::SafeArrayUnaccessData(
			*pSA);	//safearray vector from above

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
	if (V_VT(pVAR3)==(VT_ARRAY | VT_UI1))
		SAFEARRAY *saMySafeArray=V_ARRAY(pVAR3);

	return S_OK;
}

STDMETHODIMP CWzd::VBVars4(long *pVal)
{
	*pVal=1234;
	return S_OK;
}

