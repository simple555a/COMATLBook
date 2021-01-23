// MyTNAServer.cpp : Implementation of CTNAServerApp and DLL registration.

#include "stdafx.h"
#include "TNAServer.h"
#include "MyTNAServer.h"
#import "../MTAServer/MTAServer.tlb"

/////////////////////////////////////////////////////////////////////////////
//


STDMETHODIMP CMyTNAServer::DoIt()
{
	MTASERVERLib::IMyMTAServerPtr spMTA(__uuidof(MTASERVERLib::MyMTAServer));

	spMTA->DoIt();


	return S_OK;
}
