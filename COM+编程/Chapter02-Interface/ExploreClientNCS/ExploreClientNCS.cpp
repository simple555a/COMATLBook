// ExploreClientNCS.cpp : Defines the entry point for the console application.
//

// NATIVE COM SUPPORT

#include "StdAfx.h"
#import "..\ExploreIDL\ExploreIDL.tlb"
using namespace EXPLOREIDLLib;

void ReportError(_com_error& e)
{
	cout << "Error: " << e.ErrorMessage() << endl;
}

void sub();

int main(int argc, char* argv[])
{
	::CoInitialize(NULL);
	try {
		sub();
	}
	catch(_com_error& e) {
		ReportError(e);
	}
	
	::CoUninitialize();
	return 0;
}

void sub()
{
	IMyExplorePtr spMyExplore;
	HRESULT hr = spMyExplore.CreateInstance(__uuidof(MyExplore));
	if (FAILED(hr)) {
		throw _com_error(hr);
	}

	long val = spMyExplore->GetRandomValue();
	cout << "Val: " << val << endl;
}

