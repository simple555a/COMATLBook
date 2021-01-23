// MyStockPriceEvent.cpp : Implementation of CStockPriceApp and DLL registration.

#include "stdafx.h"
#include "StockPrice.h"
#include "MyStockPriceEvent.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyStockPriceEvent::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyStockPriceEvent,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMyStockPriceEvent::NewQuote(BSTR bsSymbol, double dValue)
{
	// TODO: Add your implementation code here

	return S_OK;
}
