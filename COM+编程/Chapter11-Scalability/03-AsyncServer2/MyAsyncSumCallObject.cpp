// MyAsyncSum.cpp: implementation of the CMyAsyncSumCallObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyAsyncSumCallObject.h"

CMyThread::CMyThread()
{
	m_pCallObject = NULL;
}

HRESULT CMyThread::Init(CMyAsyncSumCallObject* p)
{
	HRESULT hr = CCPLWinThread::Init();
	if (FAILED(hr))
		return hr;

	_ASSERT (NULL != p);
	_ASSERT (NULL == m_pCallObject);
	m_pCallObject = p;

	return S_OK;
}

CMyThread::~CMyThread()
{
	m_pCallObject = NULL;
}


void CMyThread::Proc()
{
	_ASSERT (NULL != m_pCallObject);

	// Step 1: Sleep for five seconds before computing the sum
	::Sleep(5 * 1000); // sleep for five seconds;
	m_pCallObject->m_lSum = m_pCallObject->m_lVal1 + m_pCallObject->m_lVal2;

	// Step 2: Signal the call object that the sum has been computed
	CComPtr<ISynchronize> spSync;
	HRESULT hr = m_pCallObject->QueryInterface(__uuidof(ISynchronize), (void**) &spSync);
	_ASSERT (SUCCEEDED(hr));
	spSync->Signal();
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyAsyncSumCallObject::CMyAsyncSumCallObject()
{
	m_spUnkInner = NULL;
	m_lVal1 = 0;
	m_lVal2 = 0;
	m_lSum = 0;

	SAFEBOOL::GUARD guard(m_bCallInProgress);
	bool& bCallInProgress = guard;
	bCallInProgress = false;
}

HRESULT CMyAsyncSumCallObject::FinalConstruct()
{
	HRESULT hr = m_Thread.Init(this);
	m_Thread.SetApartmentToEnter(COINIT_MULTITHREADED);
	return hr;
}

CMyAsyncSumCallObject::~CMyAsyncSumCallObject()
{
	m_Thread.WaitForCompletion();
}

STDMETHODIMP CMyAsyncSumCallObject::Begin_GetSum(/*[in]*/ long lVal1, /*[in]*/ long lVal2)
{
	// Ensure that only one call is processed at a time
	{
		SAFEBOOL::GUARD guard(m_bCallInProgress);
		bool& bCallInProgress = guard;
		if (true == bCallInProgress) {
			return RPC_S_CALLPENDING;
		}
		bCallInProgress = true;
	}

	// Store the values
	m_lVal1 = lVal1;
	m_lVal2 = lVal2;

	// Reset the synchronization object
	CComPtr<ISynchronize> spSync;
	HRESULT hr = this->QueryInterface(__uuidof(ISynchronize), (void**) &spSync);
	_ASSERT (SUCCEEDED(hr));
	spSync->Reset();

	// Start the thread
	m_Thread.StartThread();

	return S_OK;
}

STDMETHODIMP CMyAsyncSumCallObject::Finish_GetSum(/*[out, retval]*/ long* plSum)
{
	*plSum = 0; // initialize

	// Ensure that begin has been called
	SAFEBOOL::GUARD guard(m_bCallInProgress);
	bool& bCallInProgress = guard;
	if (false == bCallInProgress) {
		return RPC_E_CALL_COMPLETE;
	}

	// wait till the thread signals the completion
	CComPtr<ISynchronize> spSync;
	HRESULT hr = this->QueryInterface(__uuidof(ISynchronize), (void**) &spSync);
	_ASSERT (SUCCEEDED(hr));
	spSync->Wait(0, INFINITE);
	spSync = NULL;

	*plSum = m_lSum;
	bCallInProgress = false;
	return S_OK;
}

