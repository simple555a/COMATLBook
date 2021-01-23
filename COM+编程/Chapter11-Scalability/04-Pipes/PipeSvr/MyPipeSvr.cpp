// MyPipeSvr.cpp : Implementation of CPipeSvrApp and DLL registration.

#include "stdafx.h"
#include "PipeSvr.h"
#include "MyPipeSvr.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyPipeSvr::Pull(LONG *buf, ULONG cRequest, ULONG *pcReturned)
{
	return E_NOTIMPL;
}
    
STDMETHODIMP CMyPipeSvr::Push(LONG *buf, ULONG cSent)
{
	::MessageBox(NULL, _T("Received data"), _T("Server"), MB_OK);
	for (ULONG i=0; i<cSent; i++) {
		// do something with buf[i]
	}
	return S_OK;;
}