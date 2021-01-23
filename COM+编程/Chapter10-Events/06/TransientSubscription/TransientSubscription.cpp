// TransientSubscription.cpp : Defines the entry point for the application.
//

#include "StdAfx.h"
#include <comsvcs.h>
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
	public IComMethodEvents,
	public CComObjectRoot
{
public:
	CMyTransientEvent() {}
	~CMyTransientEvent() {}

BEGIN_COM_MAP(CMyTransientEvent)
	COM_INTERFACE_ENTRY(IComMethodEvents)
END_COM_MAP()

    STDMETHODIMP OnMethodCall( 
        /* [in] */ COMSVCSEVENTINFO __RPC_FAR *pInfo,
        /* [in] */ ULONG64 oid,
        /* [in] */ REFCLSID guidCid,
        /* [in] */ REFIID guidRid,
        /* [in] */ ULONG iMeth)
	{
		::MessageBox(NULL, "OnMethodCall", NULL, MB_OK);
		return S_OK;
	}
    
    STDMETHODIMP OnMethodReturn( 
        /* [in] */ COMSVCSEVENTINFO __RPC_FAR *pInfo,
        /* [in] */ ULONG64 oid,
        /* [in] */ REFCLSID guidCid,
        /* [in] */ REFIID guidRid,
        /* [in] */ ULONG iMeth,
        /* [in] */ HRESULT hresult)
	{
		::MessageBox(NULL, "OnMethodReturn", NULL, MB_OK);
		return S_OK;
	}
    
    STDMETHODIMP OnMethodException( 
        /* [in] */ COMSVCSEVENTINFO __RPC_FAR *pInfo,
        /* [in] */ ULONG64 oid,
        /* [in] */ REFCLSID guidCid,
        /* [in] */ REFIID guidRid,
        /* [in] */ ULONG iMeth)
	{
		::MessageBox(NULL, "OnMethodException", NULL, MB_OK);
		return S_OK;
	}
};

long GetIndexInCollection(COMAdmin::ICatalogCollectionPtr spColl, _bstr_t bsSubscriptionName);

LPOLESTR GetStringFromGUID(REFGUID rguid, LPOLESTR lpsz, int cchMax)
{
	int nChars = ::StringFromGUID2(rguid, lpsz, cchMax);
	if (0 == nChars)
		return NULL;
	return lpsz;
}
 
void sub()
{
	OLECHAR buf[40]; // to stringify GUIDs

	CComPtr<CComObject<CMyTransientEvent> > spEvent;
	HRESULT hr = CComObject<CMyTransientEvent>::CreateInstance(&spEvent);
	_ASSERT(SUCCEEDED(hr));
	spEvent->InternalAddRef();

	_bstr_t bsSubscriptionName = "MyMethodSubscription";

	COMAdmin::ICOMAdminCatalogPtr spCat(__uuidof(COMAdmin::COMAdminCatalog));
	
	COMAdmin::ICatalogCollectionPtr spColl = spCat->GetCollection("TransientSubscriptions");

	IDispatchPtr spDisp = spColl->Add();
	COMAdmin::ICatalogObjectPtr spCatObject = spDisp;
	spCatObject->Value["Name"] = bsSubscriptionName;
	spCatObject->Value["EventCLSID"] = GetStringFromGUID(__uuidof(COMEvents), buf, 40);
	spCatObject->Value["InterfaceID"] = GetStringFromGUID(__uuidof(IComMethodEvents), buf, 40);
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
