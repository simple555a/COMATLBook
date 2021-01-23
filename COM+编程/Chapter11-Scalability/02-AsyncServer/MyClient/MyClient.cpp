// MyClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void SimpleAsyncExecution();
void CheckForCallCompletion();
void NotifyCallCompletion();
void CancelCall();

int main(int argc, char* argv[])
{
	CCPLComInitializer init;
	_Module.Init(NULL, GetModuleHandle(NULL));

	// SimpleAsyncExecution();
	// CheckForCallCompletion();
	// NotifyCallCompletion();
	CancelCall();

	_Module.Term();

	return 0;
}

void SimpleAsyncExecution()
{
	// Step 1: Create the instance
	CComPtr<IUnknown> spUnk;
	HRESULT hr = ::CoCreateInstance(__uuidof(MySum), NULL, 
		CLSCTX_SERVER, __uuidof(IMySum), (void**) &spUnk);
	_ASSERT (SUCCEEDED(hr));

	// Step 2: Get the call factory
	CComPtr<ICallFactory> spCallFactory;
	hr = spUnk->QueryInterface(&spCallFactory);
	_ASSERT (SUCCEEDED(hr));
	spUnk = NULL; // not needed anymore

	// Step 3: Get the async interface
	CComPtr<AsyncIMySum> spMySum;
	hr = spCallFactory->CreateCall(__uuidof(AsyncIMySum),
		NULL,
		__uuidof(AsyncIMySum),
		(IUnknown**) &spMySum);
	_ASSERT (SUCCEEDED(hr));
	spCallFactory = NULL; // not needed anymore

	// Step 4: Initiate the call
	hr = spMySum->Begin_GetSum(10, 20);
	_ASSERT (SUCCEEDED(hr));

	// Step 5: Get the value
	long lSum;
	hr = spMySum->Finish_GetSum(&lSum);
	_ASSERT (SUCCEEDED(hr));
	cout << "Sum is: " << lSum << endl;

	// Step 6: Clean up
	spMySum = NULL;
}

void CheckForCallCompletion()
{
	// Step 1: Create the instance
	CComPtr<IUnknown> spUnk;
	HRESULT hr = ::CoCreateInstance(__uuidof(MySum), NULL, 
		CLSCTX_SERVER, __uuidof(IMySum), (void**) &spUnk);
	_ASSERT (SUCCEEDED(hr));

	// Step 2: Get the call factory
	CComPtr<ICallFactory> spCallFactory;
	hr = spUnk->QueryInterface(&spCallFactory);
	_ASSERT (SUCCEEDED(hr));
	spUnk = NULL; // not needed anymore

	// Step 3: Get the async interface
	CComPtr<AsyncIMySum> spMySum;
	hr = spCallFactory->CreateCall(__uuidof(AsyncIMySum),
		NULL,
		__uuidof(AsyncIMySum),
		(IUnknown**) &spMySum);
	_ASSERT (SUCCEEDED(hr));
	spCallFactory = NULL; // not needed anymore

	// Step 4: Initiate the call
	hr = spMySum->Begin_GetSum(10, 20);
	_ASSERT (SUCCEEDED(hr));

	// Step 5: Check for call completion every one second
	CComPtr<ISynchronize> spSync;
	hr = spMySum->QueryInterface(&spSync);
	_ASSERT (SUCCEEDED(hr));
	for(;;) {
		Sleep(1 * 1000);
		hr = spSync->Wait(0, 0);
		if (RPC_S_CALLPENDING != hr) {
			// finished call completion. Get the value.
			break;
		}
		cout << "Call is pending" << endl;
	}

	// Step 6: Get the value
	long lSum;
	hr = spMySum->Finish_GetSum(&lSum);
	_ASSERT (SUCCEEDED(hr));
	cout << "Sum is: " << lSum << endl;

	// Step 7: Clean up
	spMySum = NULL;
}

class CMyCallNotify : 
	public ISynchronize,
	public CComObjectRootEx<CComMultiThreadModel>
{
public:
	CMyCallNotify() {}
	HRESULT Init(ICallFactory* pCallFactory);
	~CMyCallNotify() {}

DECLARE_GET_CONTROLLING_UNKNOWN ()

BEGIN_COM_MAP(CMyCallNotify)
	COM_INTERFACE_ENTRY(ISynchronize)
	COM_INTERFACE_ENTRY_AGGREGATE_BLIND (m_spUnkInner.p)
END_COM_MAP()

// ISynchronize
public:
	STDMETHOD(Wait)(ULONG dwFlags, ULONG dwMilliseconds);
	STDMETHOD(Signal)();
	STDMETHOD(Reset)();

private:
	CComPtr<ISynchronize> m_spSyncInner;
	CComPtr<IUnknown> m_spUnkInner;
};

HRESULT CMyCallNotify::Init(ICallFactory* pCallFactory)
{
	// Step 1: Create a call object.
	HRESULT hr = pCallFactory->CreateCall(__uuidof(AsyncIMySum),
		GetControllingUnknown(),
		IID_IUnknown, &m_spUnkInner);
	if (FAILED (hr)) 
		return hr;

	// Step 2: Cache a pointer to the aggregated object's ISynchronize interface.
	hr = m_spUnkInner->QueryInterface(__uuidof(ISynchronize), (void**) &m_spSyncInner);
	if (FAILED (hr)) {
		m_spUnkInner = NULL;
		return hr;
	}

	return hr;
}

STDMETHODIMP CMyCallNotify::Wait(ULONG dwFlags, ULONG dwMilliseconds)
{
	// Forward the call to the inner object
	return m_spSyncInner->Wait(dwFlags, dwMilliseconds);
}

STDMETHODIMP CMyCallNotify::Signal()
{
	// Forward the call to the inner object
	HRESULT hr = m_spSyncInner->Signal();

	// Notify the user
	cout << "Call finished." << endl;
	cout << "Press enter to fetch the sum" << endl;

	return hr;
}

STDMETHODIMP CMyCallNotify::Reset()
{
	// Forward the call to the inner object
	return m_spSyncInner->Reset();
}

void NotifyCallCompletion()
{
	// Step 1: Create the instance
	CComPtr<IUnknown> spUnk;
	HRESULT hr = ::CoCreateInstance(__uuidof(MySum), NULL, 
		CLSCTX_SERVER, __uuidof(IMySum), (void**) &spUnk);
	_ASSERT (SUCCEEDED(hr));

	// Step 2: Get the call factory
	CComPtr<ICallFactory> spCallFactory;
	hr = spUnk->QueryInterface(&spCallFactory);
	_ASSERT (SUCCEEDED(hr));
	spUnk = NULL; // not needed anymore

	// Step 3: Create our call object and initialize it
	CComPtr<CComObject<CMyCallNotify> > spMyCallObject;
	hr = CComObject<CMyCallNotify>::CreateInstance(&spMyCallObject);
	_ASSERT (SUCCEEDED(hr));
	spMyCallObject->InternalAddRef();
	hr = spMyCallObject->Init(spCallFactory);
	_ASSERT (SUCCEEDED(hr));

	// Step 4: Get the async interface
	CComPtr<AsyncIMySum> spMySum;
	hr = spMyCallObject->QueryInterface(&spMySum);
	_ASSERT (SUCCEEDED(hr));

	// Step 5: Initiate the call
	hr = spMySum->Begin_GetSum(10, 20);
	_ASSERT (SUCCEEDED(hr));
	cout << "Call started..." << endl;

	// Step 6: Wait for user to press enter
	getchar();

	// Step 7: Get the value
	long lSum;
	hr = spMySum->Finish_GetSum(&lSum);
	_ASSERT (SUCCEEDED(hr));
	cout << "Sum is: " << lSum << endl;

	// Step 8: Clean up
	spMySum = NULL;
	spMyCallObject = NULL;
}

void CancelCall()
{
	// Step 1: Create the instance
	CComPtr<IUnknown> spUnk;
	HRESULT hr = ::CoCreateInstance(__uuidof(MySum), NULL, 
		CLSCTX_SERVER, __uuidof(IMySum), (void**) &spUnk);
	_ASSERT (SUCCEEDED(hr));

	// Step 2: Get the call factory
	CComPtr<ICallFactory> spCallFactory;
	hr = spUnk->QueryInterface(&spCallFactory);
	_ASSERT (SUCCEEDED(hr));
	spUnk = NULL; // not needed anymore

	// Step 3: Get the async interface
	CComPtr<AsyncIMySum> spMySum;
	hr = spCallFactory->CreateCall(__uuidof(AsyncIMySum),
		NULL,
		__uuidof(AsyncIMySum),
		(IUnknown**) &spMySum);
	_ASSERT (SUCCEEDED(hr));
	spCallFactory = NULL; // not needed anymore

	// Step 4: Initiate the call
	hr = spMySum->Begin_GetSum(10, 20);
	_ASSERT (SUCCEEDED(hr));

	// Step 5: Cancel the call if the call takes more than a second
	CComPtr<ICancelMethodCalls> spCancel;
	hr = spMySum->QueryInterface(&spCancel);
	_ASSERT (SUCCEEDED(hr));
	spCancel->Cancel(1);

	// Step 6: Get the value
	long lSum;
	hr = spMySum->Finish_GetSum(&lSum);
	if (SUCCEEDED(hr)) {
		cout << "Sum is: " << lSum << endl;
	}else {
		cout << "Finish failed: 0x" << hex << hr << endl;
	}

	// Step 7: Clean up
	spMySum = NULL;
}
