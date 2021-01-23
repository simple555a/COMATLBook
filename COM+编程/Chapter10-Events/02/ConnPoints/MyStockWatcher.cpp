// MyStockWatcher.cpp : Implementation of CConnPointsApp and DLL registration.

#include "stdafx.h"
#include "ConnPoints.h"
#include "MyStockWatcher.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyStockWatcher::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyStockWatcher,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

CMyStockWatcher::CMyStockWatcher()
{
}

CMyStockWatcher::~CMyStockWatcher()
{
}

HRESULT CMyStockWatcher::FinalConstruct()
{
	return CCPLWinThread::Init();
}

STDMETHODIMP CMyStockWatcher::Enable()
{
	StartThread();

	return S_OK;
}

STDMETHODIMP CMyStockWatcher::Disable()
{
	StopThread();

	return S_OK;
}

void CMyStockWatcher::Proc()
{
	long lPrice = 100;
	for(;;) {
		HANDLE h=Wait(5 * 1000);
		if (h == m_hStopEvent) 
			break;
		this->Fire_StockUpdate(CComBSTR("MSFT"), lPrice);
		lPrice += 5;
	}
}
