// MyBroker.cpp : Implementation of CConnectionPointApp and DLL registration.

#include "stdafx.h"
#include "ConnectionPoint.h"
#include "MyBroker.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyBroker::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyBroker,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

CMyBroker::CMyBroker()
{
}

HRESULT CMyBroker::FinalConstruct()
{
	return CCPLWinThread::Init();
}

CMyBroker::~CMyBroker()
{
	StopThread(); // if running
}

STDMETHODIMP CMyBroker::Enable()
{
	StartThread();

	return S_OK;
}

STDMETHODIMP CMyBroker::Disable()
{
	StopThread();

	return S_OK;
}

void CMyBroker::Proc()
{
	CComBSTR bsStock = "MSFT";
	double dPrice = 100.0;

	for(;;) {
		HANDLE h = Wait(5000); // wait for 5 seconds
		if (h == m_hStopEvent)
			break;
		this->Fire_NewQuote(bsStock, dPrice);
		dPrice += 1.0;
	}
}

