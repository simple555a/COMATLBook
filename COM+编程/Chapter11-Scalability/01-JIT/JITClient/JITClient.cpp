// JITClient.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

void sub();

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CCPLComInitializer init;

	try {
		sub();
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	return 0;
}

void sub()
{
	// Create three objects
	JITSVRLib::IMyJITDemoPtr spJITDemo1(__uuidof(JITSVRLib::MyJITDemo));
	JITSVRLib::IMyJITDemoPtr spJITDemo2(__uuidof(JITSVRLib::MyJITDemo));
	JITSVRLib::IMyJITDemoPtr spJITDemo3(__uuidof(JITSVRLib::MyJITDemo));

	long val1 = spJITDemo1->GetSalary();

	long val2 = spJITDemo1->GetSalary();
}


