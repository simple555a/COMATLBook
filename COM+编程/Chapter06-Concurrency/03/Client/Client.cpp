// Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

class CMyThread : public CCPLWinThread
{
public:
	IStreamPtr m_spStm;

	void Proc();
};

void CMyThread ::Proc()
{
	_ASSERT (NULL != m_spStm);

	ACTIVITYTESTLib::IMyTestPtr spTest;
	HRESULT hr = ::CoGetInterfaceAndReleaseStream(m_spStm,
		__uuidof(ACTIVITYTESTLib::IMyTest), (void**) &spTest);
	_ASSERT (SUCCEEDED(hr));
	m_spStm.Detach(); // ::CoGetInterface has already released the pointer
	spTest->DoIt();
}


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CCPLComInitializer cominit(COINIT_APARTMENTTHREADED);
	try {
		ACTIVITYTESTLib::IMyTestPtr spTest(__uuidof(ACTIVITYTESTLib::MyTest));

		CMyThread myThread; myThread.Init();
		HRESULT hr = ::CoMarshalInterThreadInterfaceInStream(
			__uuidof(ACTIVITYTESTLib::IMyTest), spTest, &myThread.m_spStm);
		_ASSERT (SUCCEEDED(hr));
		myThread.StartThread();
		::SwitchToThread(); ::Sleep(1000); // give the other thread a chance
		spTest->DoIt();
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	return 0;
}



