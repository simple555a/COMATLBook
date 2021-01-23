// ExploreClient.cpp : Defines the entry point for the console application.
//

#include "StdAfx.h"
#include <comdef.h>
#include <atlbase.h>
#include "..\ExploreIDL\ExploreIDL.h"
#include "..\ExploreIDL\ExploreIDL_i.c"
#include "TestFuncs.h"
#include "MallocSpy.h"

int main(int argc, char* argv[])
{
	// BSTR b = ::SysAllocStringByteLen("Howdy", 5);
	BSTR b = ::SysAllocStringLen(L"Howdy", 4);

	IMyExplore* CreateMyExplore();
	void TestMethods(IMyExplore* pMyExplore);

	
	::CoInitialize(NULL);
	CMallocSpyHook hook;
	hook.Init();
	
	IMyExplore* pMyExplore = CreateMyExplore();
	if (NULL != pMyExplore) {
		TestMethods(pMyExplore);
		pMyExplore->Release();
	}
	hook.Reset();

	::CoUninitialize();
	return 0;
}

IMyExplore* CreateMyExplore()
{
	IUnknown* pUnk = NULL;
	HRESULT hr = PTCreateRemoteInstance(OLESTR("PVDEV"), CLSID_MyExplore, &pUnk);
	if (FAILED(hr)) {
		DumpError(hr);
		return NULL;
	}

	IMyExplore* pMyExplore = NULL;
	hr = pUnk->QueryInterface(
		IID_IMyExplore,
		reinterpret_cast<void**>(&pMyExplore));

	if (FAILED(hr)) {
		DumpError(hr);
		pUnk->Release();
		return NULL;
	}

	pUnk->Release();
	return pMyExplore;
}

void TestMethods(IMyExplore* pMyExplore)
{
	// RandomValue(pMyExplore);
	// DirectionDemo(pMyExplore);
	// StringDemo(pMyExplore);
	// BstrStringDemo(pMyExplore);
	// GetStringDemo(pMyExplore);
	// GetEnumDemo(pMyExplore);
	// TestAliasDemo(pMyExplore);
	// TestCircularBuf(pMyExplore);
	// TestEmbeddedDemo(pMyExplore);
	// TestArrayDemo(pMyExplore);
	// TestSimpleStruct(pMyExplore);
	// TestSimpleArrayDemoIn(pMyExplore);
	// TestSimpleArrayDemoOut(pMyExplore);
	// TestSimpleUnionIn(pMyExplore);
	// TestEUnionIn(pMyExplore);
	// TestConformantIn(pMyExplore);
	// TestConformantIn2(pMyExplore);
	// TestConformantOut(pMyExplore);
	// GetGrades1(pMyExplore);
	// GetGrades2(pMyExplore);
	// GetGrades3(pMyExplore);
	// GetGrades4(pMyExplore);
	// GetGrades5(pMyExplore);
	// GetGrades6(pMyExplore);
	// LinkListDemo(pMyExplore);
	// CircularListDemo(pMyExplore);
	MemoryMgmtDemo(pMyExplore);
}

