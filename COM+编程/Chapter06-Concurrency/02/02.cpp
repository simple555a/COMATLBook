// 02.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

class CMyProductThread : public CCPLWinThread
{
public:
	int m_nVal1;
	int m_nVal2;
	int m_nProduct;

	void Proc()
	{
		m_nProduct = m_nVal1 * m_nVal2;
	}
};

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// Step 1: Create an instance and initialize it
 	CMyProductThread myThread;	myThread.Init();
	
	// Step 2: Initialize the data to be passed to the thread
	myThread.m_nVal1 = 5;
	myThread.m_nVal2 = 7;

	// Step 3: Start the thread
	myThread.StartThread();

	// Step 4: Wait for the thread to quit
	myThread.WaitForCompletion();

	// Step 5: Display the product
	TCHAR buf[100];
	_stprintf(buf, _T("The product is %d"), myThread.m_nProduct);
	::MessageBox(NULL, buf, _T("Compute Product"), MB_OK);

	return 0;
}



