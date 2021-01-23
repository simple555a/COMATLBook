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

STDMETHODIMP CWzd::Simple1(unsigned char cArg, short sArg, unsigned short usArg, workday enumArg)
{

	return S_OK;
}

STDMETHODIMP CWzd::Simple2(long lArg, unsigned long ulArg )
{

	return S_OK;
}

STDMETHODIMP CWzd::Simple3(float fArg, double dArg)
{

	return S_OK;
}

STDMETHODIMP CWzd::Simple4(boolean bArg, byte byArg, hyper yArg, unsigned hyper uyArg)
{

	return S_OK;
}

STDMETHODIMP CWzd::Simple5(long lArg1,long* lArg2,long* lArg3)
{
	*lArg2=543;
	*lArg3=987;
	return S_OK;
}
//////////////////////////////////////////////////////////////////////////
////////////////     PASSING ARRAYS       ///////////////////////////
//////////////////////////////////////////////////////////////////////////
STDMETHODIMP CWzd::Array1(long aArg[25])
{
	return S_OK;
}

STDMETHODIMP CWzd::Array2(long lSize, long aArg[][5])
{
	for (int i=0;i<lSize;i++)
	{
		int j=aArg[i][0];
	}
	return S_OK;
}

STDMETHODIMP CWzd::Array3(long lFirst, long lLast, long lSize, long *aArg)
{
	for (int i=lFirst;i<=lLast;i++)
	{
		int j=aArg[i];
	}
	return S_OK;
}

STDMETHODIMP CWzd::Array4(long lFirst, long lLength, long lSize, long *aArg)
{
	for (int i=lFirst;i<(lFirst+lLength);i++)
	{
		int j=aArg[i];
	}
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////
////////////////     PASSING STRUCTURES AND CLASSES /////////////////////
//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CWzd::Structs1(MYSTRUCT myStruct, IUnknown *myClass)
{
	IWzd *pWzd=(IWzd*)myClass;
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////
////////////////     PASSING ENCAPSULATED UNIONS /////////////////////
//////////////////////////////////////////////////////////////////////////
STDMETHODIMP CWzd::EUnions1(long lType, MYEUNION myEUnion)
{
	if (lType==1)
		float f=myEUnion.fFloat[0];

	return S_OK;
}

//////////////////////////////////////////////////////////////////////////
////////////////     PASSING MEMORY POINTERS /////////////////////
//////////////////////////////////////////////////////////////////////////
STDMETHODIMP CWzd::MemPtr1(MYSTRUCT *pStruct)
{
	return S_OK;
}

STDMETHODIMP CWzd::MemPtr2(MYSTRUCT **pPtr)
{
	::CoTaskMemFree(*pPtr);
	*pPtr=(MYSTRUCT*)::CoTaskMemAlloc(
								sizeof(MYSTRUCT)		//number of bytes to allocate
							 	);

	return S_OK;
}

STDMETHODIMP CWzd::MemPtr3(MYSTRUCT **pStruct1,MYSTRUCT **pStruct2)
{
	(*pStruct1)->lElement=123;
	(*pStruct2)->lElement=456;
	return S_OK;
}

STDMETHODIMP CWzd::MemPtr4(MYSTRUCT **pStruct1,MYSTRUCT **pStruct2)
{
	return S_OK;
}

//////////////////////////////////////////////////////////////////////////
////////////////     PASSING VISUAL BASIC VARIABLES /////////////////////
//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CWzd::VBVars1(BSTR bstr, BSTR* pBSTR)
{
	*pBSTR=L"return";
	return S_OK;
}

STDMETHODIMP CWzd::VBVars2(SAFEARRAY** pSA)
{
	return S_OK;
}

STDMETHODIMP CWzd::VBVars3(VARIANT* pVAR1,VARIANT* pVAR2,VARIANT* pVAR3)
{
	return S_OK;
}

STDMETHODIMP CWzd::VBVars4(long *pVal)
{
	*pVal=1234;
	return S_OK;
}

