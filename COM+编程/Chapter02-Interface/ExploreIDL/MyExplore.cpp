// MyExplore.cpp : Implementation of CExploreIDLApp and DLL registration.

#include "stdafx.h"
#include "ExploreIDL.h"
#include "MyExplore.h"
#include <stdlib.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////
//


STDMETHODIMP CMyExplore::GetRandomValue(long *pVal)
{
	*pVal = rand();

	return S_OK;
}

STDMETHODIMP CMyExplore::DirectionDemo(long val1, long *pVal2, long *pVal3, long *pVal4, long val5)
{
	*pVal2 = val1 + 100;

	*pVal3 = *pVal3 + 200;

	*pVal4 = val5 + 300;

	return S_OK;
}


STDMETHODIMP CMyExplore::StringParam(OLECHAR *pwszName)
{
	printf("String is %S\n", pwszName); 
	return S_OK;
}

STDMETHODIMP CMyExplore::RevisedStringParam(BSTR bstrVal)
{
	LPCWSTR pwszName = bstrVal;

	printf("String is %S\n", pwszName); 
	return S_OK;

}

STDMETHODIMP CMyExplore::GetString(BSTR *pVal)
{
	/*
	*pVal = ::SysAllocString(OLESTR("Alexander, The Great"));
	if (NULL == *pVal) {
		return E_OUTOFMEMORY;
	}

	return S_OK;
	*/

	CComBSTR bstrName = "Alexander, The Great";
	if (NULL == static_cast<BSTR>(bstrName)) {
		return E_OUTOFMEMORY;
	}

	*pVal = bstrName.Detach();
	return S_OK;
}

STDMETHODIMP CMyExplore::GetEnum(MYCOLOR *pVal)
{
	*pVal = (MYCOLOR) (MYRED | MYBLUE);

	return S_OK;
}

STDMETHODIMP CMyExplore::AliasDemo(long *val1, long *val2, long *val3)
{
	if (NULL != val1) {
		*val1 = 10;
	}
	if (NULL != val2) {
		*val2 = 20;
	}
	if (NULL != val3) {
		*val3 = 30;
	}

	return S_OK;
}

STDMETHODIMP CMyExplore::AliasDemoInParam(long *pVal1, long *pVal2)
{
	if (NULL != pVal2) {
		*pVal2 = 10;
	}

	return S_OK;
}

STDMETHODIMP CMyExplore::SendCircularBuf(CIRCULARBUF *pBuf)
{
	CIRCULARBUF* p1 = pBuf;
	CIRCULARBUF* p2 = p1->pNext;
	CIRCULARBUF* p3 = p2->pNext;
	CIRCULARBUF* p4 = p3->pNext;
		

	return S_OK;
}

STDMETHODIMP CMyExplore::EmbeddedDemo(MYITEM* val)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CMyExplore::ArrayDemo(long nCount, long *pVal)
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CMyExplore::StructDemo(MYPOINT *pVal)
{
	pVal->lX = 10;
	pVal->lY = 20;

	return S_OK;
}

STDMETHODIMP CMyExplore::SimpleArrayDemoIn(long alVal[])
{
	// TODO: Add your implementation code here

	return S_OK;
}

STDMETHODIMP CMyExplore::SimpleArrayDemoOut(long alVal[])
{
	alVal[0] = 50;
	alVal[99] = 100;

	return S_OK;
}

STDMETHODIMP CMyExplore::SimpleUnionIn(MYVALUETYPE i, MYNUMBER num)
{
	long l;
	float f;

	switch(i) {
	case MYLONG:
		l = num.l;
		break;
	case MYFLOAT:
		f = num.f;
		break;
	}

	return S_OK;
}

STDMETHODIMP CMyExplore::EncapsulatedUnionIn(MYENUMBER num)
{
	long l;
	float f;

	switch(num.type) {
	case MYLONG:
		l = num.l;
		break;
	case MYFLOAT:
		f = num.f;
		break;
	}

	return S_OK;
}

STDMETHODIMP CMyExplore::ConformantArrayIn(long lCount, long *aVal)
{
	long lFirstVal = aVal[0];
	long lLastVal = aVal[lCount-1];

	return S_OK;
}

STDMETHODIMP CMyExplore::ConformantArrayIn2(long lCount, long aVal[])
{
	long lFirstVal = aVal[0];
	long lLastVal = aVal[lCount];

	return S_OK;
}

STDMETHODIMP CMyExplore::ConformantArrayOut(long lCount, long alVal[])
{
	alVal[0] = 25;
	alVal[lCount-1] = 50;

	return S_OK;
}

STDMETHODIMP CMyExplore::GetGrades1(long lSize, long alGrades[])
{
	for(long i=0;i<lSize;i++) {
		alGrades[i] = i + 15;
	}

	return S_OK;
}

STDMETHODIMP CMyExplore::GetGrades2(long lSize, long *plActual, long alGrades[])
{
	*plActual = 5;
	for(long i=0;i<*plActual;i++) {
		alGrades[i] = i + 15;
	}

	return S_OK;
}

STDMETHODIMP CMyExplore::GetGrades3(long lSize, long *plActual, long alGrades[])
{
	*plActual = 5;
	for(long i=0;i<*plActual;i++) {
		alGrades[i] = i + 15;
	}

	return S_OK;
}

STDMETHODIMP CMyExplore::GetGrades4(long lSize, long *plActual, long *plFirst, long alGrades[])
{
	*plActual = 5;
	*plFirst = 10;
	for(long i=0;i<*plActual;i++) {
		alGrades[*plFirst+i] = i + 15;
	}

	return S_OK;
}

STDMETHODIMP CMyExplore::GetGrades5(long lSize, 
									long *plActual, 
									long *plFirst, 
									long alGrades[])
{
	long lMarks = alGrades[*plFirst];

	*plActual = 5;
	*plFirst = 10;
	for(long i=0;i<*plActual;i++) {
		alGrades[*plFirst+i] = i + lMarks;
	}

	return S_OK;

}

STDMETHODIMP CMyExplore::GetGrades6(long *plCount, long **palVal)
{
	long lCount = 10;
	long* alVal = (long*) CoTaskMemAlloc(lCount * sizeof(long));
	for (int i=0;i<lCount; i++) {
		alVal[i] = i + 15;
	}
	*plCount = lCount;
	*palVal = alVal;

	return S_OK;
}

STDMETHODIMP CMyExplore::MyLinkList(MYLONGLIST *pList)
{
	long l;
	while(NULL != pList) {
		l = pList->lVal;
		pList = pList->pNext;
	}

	return S_OK;
}

STDMETHODIMP CMyExplore::MyCircularList(MYCIRCULARLIST *pList)
{
	if (NULL == pList) {
		return S_OK;
	}

	long l;
	MYCIRCULARLIST* pFirst = pList;
	do {
		l = pList->lVal;
		pList = pList->pNext;
	}while(pList != pFirst);
	return S_OK;
}

STDMETHODIMP CMyExplore::GetMyLeaders(MYLEADERS *pDataArray)
{
	pDataArray->lElements = 2;
	pDataArray->pData = (MYLEADER*) ::CoTaskMemAlloc(2 * sizeof(MYLEADER));

	pDataArray->pData[0].bsFirstName = ::SysAllocString(L"Mohandas");
	pDataArray->pData[0].bsLastName  = ::SysAllocString(L"Gandhi");
	VARIANT& v0 = pDataArray->pData[0].vTitle;
	::VariantInit(&v0);
	V_VT(&v0) = VT_BSTR; V_BSTR(&v0) = ::SysAllocString(L"Mahatma");

	pDataArray->pData[1].bsFirstName = ::SysAllocString(L"Winston");
	pDataArray->pData[1].bsLastName  = ::SysAllocString(L"Churchil");
	VARIANT& v1 = pDataArray->pData[1].vTitle;
	::VariantInit(&v1);
	V_VT(&v1) = VT_BSTR; V_BSTR(&v1) = ::SysAllocString(L"Sir");

	return S_OK;
}
