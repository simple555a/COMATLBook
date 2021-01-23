// MyCount.cpp : Implementation of CGlobalCountApp and DLL registration.

#include "stdafx.h"
#include "GlobalCount.h"
#include "MyCount.h"

// #define USECRITICALSECTION
// #define USEINTERLOCK
#define USECPLATOMICCOUNTER

/////////////////////////////////////////////////////////////////////////////
//

#ifdef USECRITICALSECTION
CComAutoCriticalSection g_myCS;
long g_nCount = 500;
#endif

#ifdef USEINTERLOCK
long g_nCount = 500;
#endif

#ifdef USECPLATOMICCOUNTER
CCPLWinAtomicCounter g_nCount;
#endif

STDMETHODIMP CMyCount::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyCount,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

#ifdef USECRITICALSECTION

STDMETHODIMP CMyCount::GetCount(long *plCount)
{
	g_myCS.Lock();
	*plCount = g_nCount;
	g_myCS.Unlock();

	return S_OK;
}

STDMETHODIMP CMyCount::IncrementCount(long nValue)
{
	g_myCS.Lock();
	g_nCount += nValue;
	g_myCS.Unlock();

	return S_OK;
}

#endif

#ifdef USEINTERLOCK

STDMETHODIMP CMyCount::GetCount(long *plCount)
{
	*plCount = g_nCount;

	return S_OK;
}

STDMETHODIMP CMyCount::IncrementCount(long nValue)
{
	::InterlockedExchangeAdd(&g_nCount, nValue);

	return S_OK;
}
#endif

#ifdef USECPLATOMICCOUNTER

STDMETHODIMP CMyCount::GetCount(long *plCount)
{
	*plCount = g_nCount;

	return S_OK;
}

STDMETHODIMP CMyCount::IncrementCount(long nValue)
{
	g_nCount += nValue;

	return S_OK;
}
#endif

