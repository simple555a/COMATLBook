#include "StdAfx.h"
#include <comdef.h>
#include <atlbase.h>
#include "..\ExploreIDL\ExploreIDL.h"
#include "TestFuncs.h"

void RandomValue(IMyExplore* pMyExplore)
{
	cout << "\n\nRandom value Test" << endl;
	long lVal;
	HRESULT hr = pMyExplore->GetRandomValue(&lVal);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
	cout << "Random value is: " << lVal << endl;
}

void DirectionDemo(IMyExplore* pMyExplore)
{
	cout << "\n\nDirection demo test" << endl;

	long val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5;
	cout << "Before: " << val1 << ", " << val2 << ", " << val3 << ", " << val4 << ", " << val5 << endl;
	HRESULT hr = pMyExplore->DirectionDemo(val1, &val2, &val3, &val4, val5);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
	cout << "After: " << val1 << ", " << val2 << ", " << val3 << ", " << val4 << ", " << val5 << endl;
}

void StringDemo(IMyExplore* pMyExplore)
{
	cout << "\n\nString demo test" << endl;
	wchar_t* pwszString = L"Alexander, The Great";
	HRESULT hr = pMyExplore->StringParam(pwszString);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

	LPOLESTR pwszString1 = OLESTR("Alexander, The Great");
	hr = pMyExplore->StringParam(pwszString1);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

}

void BstrStringDemo(IMyExplore* pMyExplore)
{

	LPOLESTR pwszName = OLESTR("Alexander, The Great");

	BSTR bstrName = ::SysAllocString(pwszName);
	HRESULT hr = pMyExplore->RevisedStringParam(bstrName);
	::SysFreeString(bstrName);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

	_bstr_t bstrName1 = "Alexander, The Great";
	hr = pMyExplore->RevisedStringParam(bstrName1);

	CComBSTR bstrName2 = "Alexander, The Great";
	hr = pMyExplore->RevisedStringParam(bstrName2);

}

void GetStringDemo(IMyExplore* pMyExplore)
{
	BSTR bstrName = NULL;
	HRESULT hr = pMyExplore->GetString(&bstrName);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

	USES_CONVERSION;
	LPSTR pszString = W2A(bstrName);
	cout << "Name: " << pszString << endl;
	::SysFreeString(bstrName);

	CComBSTR bstrName1;
	hr = pMyExplore->GetString(&bstrName1);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
	cout << "Name1: " << W2A(bstrName1) << endl;
}

void GetEnumDemo(IMyExplore* pMyExplore)
{
	MYCOLOR color;
	HRESULT hr = pMyExplore->GetEnum(&color);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

	cout << "Color is: " << color << endl;
}


void TestAliasDemo(IMyExplore* pMyExplore)
{
	long val1 = 100, val2 = 200, val3 = 300;

	HRESULT hr = pMyExplore->AliasDemoInParam(&val1, NULL);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
	cout << "After: " << val1 << ", " << val2 << ", " << val3 << endl;

}

void TestCircularBuf(IMyExplore* pMyExplore)
{
	CIRCULARBUF* pBuf = new CIRCULARBUF;
	CIRCULARBUF* pFirst = pBuf;

	for (int i=0; i<3; i++) {
		pBuf->lVar = i + 100;
		pBuf->pNext = new CIRCULARBUF;
		pBuf = pBuf->pNext;
	}
	pBuf->lVar = i + 100;
	// pBuf->pNext = pFirst;
	pBuf->pNext = NULL;

	HRESULT hr = pMyExplore->SendCircularBuf(pFirst);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
}

void TestEmbeddedDemo(IMyExplore* pMyExplore)
{
	MYITEM item;
	item.lVal = 20;
	item.plVal = NULL;

	HRESULT hr = pMyExplore->EmbeddedDemo(&item);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
}

void TestArrayDemo(IMyExplore* pMyExplore)
{
	long val[3];
	val[0] = 5;
	val[1] = 10;
	val[2] = 15;

	HRESULT hr = pMyExplore->ArrayDemo(0, NULL);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
}

void TestSimpleStruct(IMyExplore* pMyExplore)
{
	MYPOINT pt;
	HRESULT hr = pMyExplore->StructDemo(&pt);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

}

void TestSimpleArrayDemoIn(IMyExplore* pMyExplore)
{
	long alVal[100];

	alVal[0] = 25;
	HRESULT hr = pMyExplore->SimpleArrayDemoIn(alVal);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

}

void TestSimpleArrayDemoOut(IMyExplore* pMyExplore)
{
	long alVal[100];

	alVal[0] = 25;
	alVal[99] = 50;
	HRESULT hr = pMyExplore->SimpleArrayDemoOut(alVal);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
}

void TestSimpleUnionIn(IMyExplore* pMyExplore)
{
	MYNUMBER num;

	num.f = 15.0;
	HRESULT hr = pMyExplore->SimpleUnionIn(MYFLOAT, num);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

	num.l = 10;
	hr = pMyExplore->SimpleUnionIn(MYLONG, num);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
}

void TestEUnionIn(IMyExplore* pMyExplore)
{
	MYENUMBER num;

	num.type = MYFLOAT;
	num.f = 15.0;
	HRESULT hr = pMyExplore->EncapsulatedUnionIn(num);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

	num.type = MYLONG;
	num.l = 10;
	hr = pMyExplore->EncapsulatedUnionIn(num);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

}

void TestConformantIn(IMyExplore* pMyExplore)
{
	long alVal[100];
	alVal[0] = 50;
	alVal[99] = 25;
	HRESULT hr = pMyExplore->ConformantArrayIn(100, alVal);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
}

void TestConformantIn2(IMyExplore* pMyExplore)
{
	long alVal[100];
	alVal[0] = 50;
	alVal[99] = 25;
	HRESULT hr = pMyExplore->ConformantArrayIn2(99, alVal);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
}

void TestConformantOut(IMyExplore* pMyExplore)
{
	long alVal[100];
	alVal[0] = 0;
	alVal[99] = 0;
	HRESULT hr = pMyExplore->ConformantArrayOut(100, alVal);

	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
	cout << alVal[0] << ", " << alVal[99] << endl;
}

void GetGrades1(IMyExplore* pMyExplore)
{
	long alGrades[25];
	for(long i=0; i<25; i++) { alGrades[i] = 0; }
	pMyExplore->GetGrades1(25, alGrades);
	for(i=0; i<25; i++) { cout << alGrades[i] << endl; }
}

void GetGrades2(IMyExplore* pMyExplore)
{
	long alGrades[25];
	for(long i=0; i<25; i++) { alGrades[i] = 0; }

	long lActual = 0;
	pMyExplore->GetGrades2(25, &lActual, alGrades);
	for(i=0; i<lActual; i++) { cout << alGrades[i] << endl; }
}

void GetGrades3(IMyExplore* pMyExplore)
{
	long alGrades[25];
	for(long i=0; i<25; i++) { alGrades[i] = 0; }

	long lActual = 0;
	pMyExplore->GetGrades3(25, &lActual, alGrades);
	for(i=0; i<lActual; i++) { cout << alGrades[i] << endl; }
}

void GetGrades4(IMyExplore* pMyExplore)
{
	long alGrades[25];
	for(long i=0; i<25; i++) { alGrades[i] = 0; }

	long lActual = 0; long lFirst = 0;
	pMyExplore->GetGrades4(25, &lActual, &lFirst, alGrades);
	cout << "First is: " << lFirst << endl;
	for(i=0; i<lActual; i++) { cout << alGrades[lFirst+i] << endl; }
}

void GetGrades5(IMyExplore* pMyExplore)
{
	long alGrades[25];
	for(long i=0; i<25; i++) { alGrades[i] = 0; }

	long lActual = 1; long lFirst = 24; alGrades[lFirst] = 50;
	HRESULT hr = pMyExplore->GetGrades5(25, &lActual, &lFirst, alGrades);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}
	cout << "First is: " << lFirst << endl;
	for(i=0; i<lActual; i++) { cout << alGrades[lFirst+i] << endl; }
}

void GetGrades6(IMyExplore* pMyExplore)
{
	long* palGrades;
	long lCount = 0;
	pMyExplore->GetGrades6(&lCount, &palGrades);
	for(long i=0; i<lCount; i++) { cout << palGrades[i] << endl; }
	CoTaskMemFree(palGrades);
}

void LinkListDemo(IMyExplore* pMyExplore)
{
	MYLONGLIST lastItem;
	lastItem.lVal = 100;
	lastItem.pNext = NULL;

	MYLONGLIST firstItem;
	firstItem.lVal = 200;
	firstItem.pNext = &lastItem;

	HRESULT hr = pMyExplore->MyLinkList(&firstItem);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

}

void CircularListDemo(IMyExplore* pMyExplore)
{
	MYCIRCULARLIST lastItem;
	lastItem.lVal = 100;
	lastItem.pNext = NULL;

	MYCIRCULARLIST firstItem;
	firstItem.lVal = 200;
	firstItem.pNext = &lastItem;

	lastItem.pNext = &firstItem;


	HRESULT hr = pMyExplore->MyCircularList(&firstItem);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

}

void MemoryMgmtDemo(IMyExplore* pMyExplore)
{
	MYLEADERS leaders;

	HRESULT hr = pMyExplore->GetMyLeaders(&leaders);
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

	USES_CONVERSION;
	for(long i=0; i<leaders.lElements; i++) {
		MYLEADER* pLeader = &leaders.pData[i];
		VARIANT& v = pLeader->vTitle;

		LPSTR pszTitle = W2A(V_BSTR(&v));
		LPSTR pszFirstName = W2A(pLeader->bsFirstName);
		LPSTR pszLastName = W2A(pLeader->bsLastName);
		cout << pszTitle << " " << pszFirstName << " " << pszLastName << endl;
	}

	// Free memory
	for(i=0; i<leaders.lElements; i++) {
		MYLEADER* pLeader = &leaders.pData[i];
		::VariantClear(&pLeader->vTitle);
		::SysFreeString(pLeader->bsFirstName);
		::SysFreeString(pLeader->bsLastName);
	}

	::CoTaskMemFree(leaders.pData);
}
