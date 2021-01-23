// MyStockEventSubscriber.cpp : Implementation of CMySubscriberApp and DLL registration.

#include "stdafx.h"
#include "MySubscriber.h"
#include "MyStockEventSubscriber.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyStockEventSubscriber::NewQuote(BSTR bsSymbol, double dValue)
{
	TCHAR buf[100];
	_stprintf(buf, _T("%S %lf"), bsSymbol, dValue);
	::MessageBox(NULL, buf, _T("Stock Price"), MB_OK);

	return S_OK;
}
