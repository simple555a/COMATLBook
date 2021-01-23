// 01.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

struct MYPARAM {
	int nVal1;
	int nVal2;
	int nProduct;
};

DWORD WINAPI MyThreadProc(LPVOID pData)
{
	::Sleep(30 * 1000); // Just sleep for 30 seconds
	MYPARAM* pParam = reinterpret_cast<MYPARAM*>(pData);
	pParam->nProduct = pParam->nVal1 * pParam->nVal2;
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// Step 1: Initialize the data to be passed to the thread
 	MYPARAM data;
	data.nVal1 = 5;
	data.nVal2 = 7;
	data.nProduct = 0;

	// Step 2: Create and run the thread
	DWORD dwThreadID;
	HANDLE hThread = ::CreateThread(NULL, 0, MyThreadProc, &data, 0, &dwThreadID);

	// Step 3: Wait for the thread to quit
	::WaitForSingleObject(hThread, INFINITE);

	// Step 4: Release the thread handle
	::CloseHandle(hThread); hThread = NULL;

	// Step 5: Display the product
	TCHAR buf[100];
	_stprintf(buf, _T("The product is %d"), data.nProduct);
	::MessageBox(NULL, buf, _T("Compute Product"), MB_OK);

	return 0;
}



