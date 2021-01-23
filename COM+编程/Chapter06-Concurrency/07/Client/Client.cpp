// Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "../GlobalCount/GlobalCount.tlb"
using namespace GLOBALCOUNTLib;

class CMyThread : public CCPLWinThread
{
public:
	void Proc()
	{
		try {
			IMyCountPtr spCount(__uuidof(MyCount));

			// Increment the count every second.
			// Quit if stop requested
			while(m_hStopEvent != this->Wait(1000)) {
				spCount->IncrementCount(10);
			}
		}catch(_com_error& e) {
			// message box from a worker thread is ok for our test
			::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
		}
	}
};

void DisplayCount(long nCount)
{
	TCHAR buf[20];
	_stprintf(buf, _T("%ld"), nCount);
	::MessageBox(NULL, buf, _T("Current Count"), MB_OK);
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	CCPLComInitializer init;


	try {
		CMyThread myThread; myThread.Init();
		IMyCountPtr spCount(__uuidof(MyCount));
		myThread.StartThread();

		for(int i=0; i<10; i++) {
			long nCurCount = spCount->GetCount();
			DisplayCount(nCurCount);
		}
	}catch(_com_error& e) {
		// message box from a worker thread is ok for our test
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}


	return 0;
}



