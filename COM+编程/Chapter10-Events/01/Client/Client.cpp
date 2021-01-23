// Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

void ProcessEvents();

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CCPLComInitializer init;

	try {
		ProcessEvents();
	}
	catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	return 0;
}

class CMySink :
	public IStockPriceUpdate,
	public CComObjectRoot
{
public:

BEGIN_COM_MAP(CMySink)
	COM_INTERFACE_ENTRY(IStockPriceUpdate)
END_COM_MAP()

	STDMETHODIMP NewQuote(BSTR bsSymbol, double dPrice)
	{

		TCHAR buf[100];
		_stprintf(buf, _T("%S %lf"), bsSymbol, dPrice);
		::MessageBox(NULL, buf, _T("New price"), MB_OK);
		return S_OK;
	}
};


void ProcessEvents()
{
	// Step 0: Create the broker object
	CComPtr<IMyBroker> spMyBroker;
	HRESULT hr = ::CoCreateInstance(__uuidof(MyBroker), NULL, 
		CLSCTX_ALL, __uuidof(IMyBroker), (void**) &spMyBroker);
	if (FAILED(hr)) _com_issue_error(hr);

	
	
	// Step 1: Check if the object supports CPC
	CComPtr<IConnectionPointContainer> spCPC;
	hr = spMyBroker->QueryInterface(__uuidof(IConnectionPointContainer), (void**) &spCPC);
	if (FAILED(hr)) _com_issue_error(hr);

	// Step 2: Check if IStockPriceUpdate is supported as CP
	CComPtr<IConnectionPoint> spCP;
	hr = spCPC->FindConnectionPoint(__uuidof(IStockPriceUpdate), &spCP);
	if (FAILED(hr)) _com_issue_error(hr);

	// Step 3: Create and register the sink object with the connection point
	CComPtr<CComObject<CMySink> > spSink;
	hr = CComObject<CMySink>::CreateInstance(&spSink);
	if (FAILED(hr)) _com_issue_error(hr);
	spSink->InternalAddRef();

	DWORD dwCookie;
	hr = spCP->Advise(spSink, &dwCookie);
	if (FAILED(hr)) _com_issue_error(hr);

	// Step 4: Collect data for 30 sec (for our experiment)
	spMyBroker->Enable();
	::Sleep(30000); 
	spMyBroker->Disable();

	// Step 5: Remove the sink object
	hr = spCP->Unadvise(dwCookie);
	if (FAILED(hr)) _com_issue_error(hr);
}

