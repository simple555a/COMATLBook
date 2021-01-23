// TransientSubscription.cpp : Defines the entry point for the application.
//

#include "StdAfx.h"
#include "../StockPrice/StockPrice.h"
#include "../StockPrice/StockPrice_i.c"
#import <com/comadmin.dll>

void sub();

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CCPLComInitializer init;
	_Module.Init(NULL, hInstance);

	try {
		sub();
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	_Module.Term();

	return 0;
}

class CMyTransientEvent : 
	public IDispatchImpl<IMyStockPriceEvent, &IID_IMyStockPriceEvent, &LIBID_STOCKPRICELib>, 
	public CComObjectRoot
{
public:
	CMyTransientEvent() {}
	~CMyTransientEvent() {}

BEGIN_COM_MAP(CMyTransientEvent)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyStockPriceEvent)
END_COM_MAP()

// IMyStockPriceEvent
public:
	STDMETHOD(NewQuote)(/*[in]*/ BSTR bsSymbol, /*[in]*/ double dValue);
};

STDMETHODIMP CMyTransientEvent::NewQuote(BSTR bsSymbol, double dValue)
{
	TCHAR buf[100];
	_stprintf(buf, _T("%S %lf"), bsSymbol, dValue);
	::MessageBox(NULL, buf, _T("Transient Event : Stock Price"), MB_OK);

	return S_OK;
}

long GetIndexInCollection(COMAdmin::ICatalogCollectionPtr spColl, _bstr_t bsSubscriptionName);

void sub()
{
	CComPtr<CComObject<CMyTransientEvent> > spEvent;
	HRESULT hr = CComObject<CMyTransientEvent>::CreateInstance(&spEvent);
	_ASSERT(SUCCEEDED(hr));
	spEvent->InternalAddRef();

	_bstr_t bsSubscriptionName = "My transient subscription";

	COMAdmin::ICOMAdminCatalogPtr spCat(__uuidof(COMAdmin::COMAdminCatalog));
	
	COMAdmin::ICatalogCollectionPtr spColl = spCat->GetCollection("TransientSubscriptions");

	IDispatchPtr spDisp = spColl->Add();
	COMAdmin::ICatalogObjectPtr spCatObject = spDisp;
	spCatObject->Value["Name"] = bsSubscriptionName;
	spCatObject->Value["InterfaceID"] ="{A9E6D819-1891-462D-B32C-ED4AFD61B08B}";
	/*[optional]*/ // spCatObject->Value["EventCLSID"] = "{1F6F353D-5738-4C05-9DA1-A64E19370A0E}";
	/*[optional]*/ // spCatObject->Value["PublisherID"] = "My Stock Price Publisher X";
	spCatObject->Value["SubscriberInterface"] = static_cast<IUnknown*>(spEvent);

	spColl->SaveChanges();

	::MessageBox(NULL, "Click OK to exit", "Transient Event", MB_OK);

	// Remove the object
	spColl = spCat->GetCollection("TransientSubscriptions");
	spColl->Populate();
	long lIndex = GetIndexInCollection(spColl, bsSubscriptionName);
	spColl->Remove(lIndex);
	spColl->SaveChanges();
	::MessageBox(NULL, "Removed the handler", "Transient Event", MB_OK);
}

long GetIndexInCollection(COMAdmin::ICatalogCollectionPtr spColl, _bstr_t bsSubscriptionName)
{
	long lTotal = spColl->Count;
	for (long i = 0; i< lTotal; i++) {
		IDispatchPtr spDisp = spColl->Item[i];
		COMAdmin::ICatalogObjectPtr spCatObject = spDisp;
		_bstr_t bsName = spCatObject->Name;
		if (!wcsicmp(bsName, bsSubscriptionName))
			return i;
	}
	return -1;
}
