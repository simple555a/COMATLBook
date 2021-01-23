// MyMTAServer.cpp : Implementation of CMTAServerApp and DLL registration.

#include "stdafx.h"
#include "MTAServer.h"
#include "MyMTAServer.h"

/////////////////////////////////////////////////////////////////////////////
//


STDMETHODIMP CMyMTAServer::DoIt()
{
	::MessageBox(NULL, _T("From MTA"), _T("Do It"), MB_OK);

	return S_OK;
}
