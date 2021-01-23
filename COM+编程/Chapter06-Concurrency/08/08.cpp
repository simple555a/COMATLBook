// 02.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

class CMyProductThread : public CCPLWinThread
{
public:
	CMyProductThread()
	{
		m_nVal1 = m_nVal2 = m_nProduct = 0;
	}

	void Init(int val1, int val2)
	{
		CCPLWinThread::Init();
		m_nVal1 = val1;
		m_nVal2 = val2;
		m_hDoItEvent.Init();
		AddHandleToWaitGroup(m_hDoItEvent);
	}

	void DoIt()
	{
		m_hDoItEvent.Signal();
	}

	int GetProduct() { return m_nProduct; }

	void Proc()
	{
		HANDLE hEvent = Wait(30 * 1000);
		if (hEvent == m_hStopEvent) {
			// Request to exit the thread
			return;
		}

		if (NULL == hEvent) {
			// no request came in within 30 sec.
			// set the product to an illegal value
			m_nProduct = -1;
			return;
		}

		_ASSERT (hEvent == m_hDoItEvent);
		m_nProduct = m_nVal1 * m_nVal2;
	}

private:
	int m_nVal1;
	int m_nVal2;
	int m_nProduct;

	CCPLWinEvent m_hDoItEvent;
};

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	// Step 1: Create an instance and initialize it
 	CMyProductThread myThread;	
	myThread.SetApartmentToEnter(COINIT_MULTITHREADED);

	myThread.Init(5, 7);
	
	// Step 2: Start the thread
	myThread.StartThread();

	// Step 3: Wait for n seconds before requesting the thread to DoIt
	::Sleep(20 * 1000);
	myThread.DoIt();

	// Step 4: Wait for the thread to quit
	myThread.WaitForCompletion();

	// Step 5: Display the product
	TCHAR buf[100];
	_stprintf(buf, _T("The product is %d"), myThread.GetProduct());
	::MessageBox(NULL, buf, _T("Compute Product"), MB_OK);

	return 0;
}



