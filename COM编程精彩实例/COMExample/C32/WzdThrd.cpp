// WzdThrd.cpp : thread process
//

#include "stdafx.h"
#include "WzdThrd.h"
#import "server\server.tlb" no_namespace

/////////////////////////////////////////////////////////////////////////////
// CWzdThrd

UINT WzdThrd( LPVOID pParam )
{
	// get data from thread creator
	THREADDATA *pData=(THREADDATA *)pParam;

	// every thread in process requires CoInit
	::CoInitializeEx(NULL,COINIT_APARTMENTTHREADED);
	LPUNKNOWN p;
	HRESULT hr=::CoGetInterfaceAndReleaseStream(
			pData->lpStream,	//stream 
			__uuidof(IWzd),		//identifier of the interface
			(LPVOID*)&p);
	if (FAILED(hr))
	{
		_com_error err(hr);
		AfxMessageBox(err.ErrorMessage());
		return 0;
	}
	IWzdPtr pPtr(p);

//////////////////////////////////////////////////////////////////////////
////////////////     CALL THE METHOD    ///////////////////////////
//////////////////////////////////////////////////////////////////////////
	IWzd* pRawWzd=(IWzd*)pData->lpRawWzd;
	pRawWzd->Method1(1234);
	pPtr->Method1(1234);

	::CoUninitialize();
	return 0;	// return value up to you--parent can retrieve with GetExitCodeThread();
				// can also call AfxEndThread(0) where the meaning of the argument is up to you
}
