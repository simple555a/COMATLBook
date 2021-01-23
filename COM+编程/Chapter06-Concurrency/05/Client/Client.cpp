// Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "../MTAServer/MTAServer.tlb"
using namespace MTASERVERLib;

#define VERIFYHR(hr) \
   { if (FAILED(hr)) _com_issue_error(hr ); }

void ReportError(_com_error& e)
{
	::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
}

// #define NOMARSHAL
// #define MARSHALONHGLOBAL
#define MARSHALWITHGIT


#ifdef NOMARSHAL

class CMyThread : public CCPLWinThread
{
public:
	IMyTestPtr m_spTest;

	void Proc()
	{
		try {
			m_spTest->DoIt();
		}
		catch(_com_error& e) {
			ReportError(e);
		}
	}
};

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CComInitializer init(COINIT_MULTITHREADED);

	try {
		// Create object and get IMyTest interface
		IMyTestPtr spTest(__uuidof(MyTest));

		// Create a thread. Set it to enter STA
		CMyThread myThread; myThread.Init();
		myThread.SetApartmentToEnter(COINIT_APARTMENTTHREADED);

		// Pass the interface pointer to the thread without marshaling
		myThread.m_spTest = spTest;

		// Start the thread and wait for the thread to quit
		myThread.StartThread();
		myThread.WaitForCompletion();
	}catch(_com_error& e) {
		ReportError(e);
	}

	return 0;
}

#endif

#ifdef MARSHALONHGLOBAL

HGLOBAL MyMarshalInterface(IMyTestPtr spTest)
{
	// Create an IStream pointer on a dynamally allocated global memory
	IStreamPtr spStream;
	HRESULT hr = ::CreateStreamOnHGlobal(0, FALSE, &spStream);
	VERIFYHR(hr);

	// Marshal the interface pointer into the stream
	hr = ::CoMarshalInterface(spStream, 
		__uuidof(IMyTest),
		spTest,
		MSHCTX_INPROC,
		0,
		MSHLFLAGS_NORMAL);
	VERIFYHR(hr);

	// obtain the handle to the global memory and return it
	HGLOBAL hRetVal;
	hr = ::GetHGlobalFromStream(spStream, &hRetVal);
	VERIFYHR(hr);
	return hRetVal;
}

IMyTestPtr MyUnmarshalInterface(HGLOBAL& hGlobal)
{
	// Create an Istream pointer over the global memory handle
	IStreamPtr spStream;
	HRESULT hr = ::CreateStreamOnHGlobal(hGlobal, TRUE, &spStream);
	VERIFYHR(hr);
	hGlobal = NULL; // the handle will be deleted on releasing spStream

	IMyTestPtr spTest;
	hr = ::CoUnmarshalInterface(spStream, __uuidof(IMyTest), (void**) &spTest);
	VERIFYHR(hr);
	return spTest;
}

class CMyThread : public CCPLWinThread
{
public:
	HGLOBAL m_hGlobal;

	void Proc()
	{
		try {
			IMyTestPtr spTest = MyUnmarshalInterface(m_hGlobal);
			spTest->DoIt();
		}
		catch(_com_error& e) {
			ReportError(e);
		}
	}
};

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CComInitializer init(COINIT_MULTITHREADED);

	try {
		// Create object and get IMyTest interface
		IMyTestPtr spTest(__uuidof(MyTest));

		// Create a thread. Set it to enter STA
		CMyThread myThread; myThread.Init();
		myThread.SetApartmentToEnter(COINIT_APARTMENTTHREADED);

		// Pass the interface pointer to the thread
		myThread.m_hGlobal = MyMarshalInterface(spTest);

		// Start the thread and wait for the thread to quit
		myThread.StartThread();
		myThread.WaitForCompletion();
	}catch(_com_error& e) {
		ReportError(e);
	}

	return 0;
}

#endif


#ifdef MARSHALWITHGIT

DWORD MyMarshalInterfaceInGIT(IMyTestPtr spTest)
{
	// Create an instance of GIT
	IGlobalInterfaceTablePtr spGIT;
	HRESULT hr = ::CoCreateInstance(CLSID_StdGlobalInterfaceTable,
		0,
		CLSCTX_INPROC_SERVER,
		__uuidof(IGlobalInterfaceTable),
		(void**) &spGIT);
	VERIFYHR(hr);

	// Add our interface pointer to GIT
	DWORD dwCookie;
	hr = spGIT->RegisterInterfaceInGlobal(spTest, __uuidof(IMyTest), &dwCookie);
	VERIFYHR(hr);
	return dwCookie;
}

IMyTestPtr MyUnmarshalInterfaceFromGIT(DWORD dwCookie)
{
	// Create an instance of GIT
	IGlobalInterfaceTablePtr spGIT;
	HRESULT hr = ::CoCreateInstance(CLSID_StdGlobalInterfaceTable,
		0,
		CLSCTX_INPROC_SERVER,
		__uuidof(IGlobalInterfaceTable),
		(void**) &spGIT);
	VERIFYHR(hr);

	IMyTestPtr spTest;
	hr = spGIT->GetInterfaceFromGlobal(dwCookie, 
		__uuidof(IMyTest), (void**) &spTest);
	VERIFYHR(hr);
	return spTest;
}

class CMyThread : public CCPLWinThread
{
public:
	DWORD m_dwCookie;

	void Proc()
	{
		try {
			IMyTestPtr spTest = MyUnmarshalInterfaceFromGIT(m_dwCookie);
			spTest->DoIt();
		}
		catch(_com_error& e) {
			ReportError(e);
		}
	}
};

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CCPLComInitializer init(COINIT_MULTITHREADED);

	try {
		// Create object and get IMyTest interface
		IMyTestPtr spTest(__uuidof(MyTest));

		// Create a thread. Set it to enter STA
		CMyThread myThread; myThread.Init();
		myThread.SetApartmentToEnter(COINIT_APARTMENTTHREADED);

		// Pass the interface pointer to the thread
		myThread.m_dwCookie = MyMarshalInterfaceInGIT(spTest);

		// Start the thread and wait for the thread to quit
		myThread.StartThread();
		myThread.WaitForCompletion();
	}catch(_com_error& e) {
		ReportError(e);
	}

	return 0;
}

#endif


