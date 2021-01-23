// Person.cpp : Implementation of CSyncTestApp and DLL registration.

#include "stdafx.h"
#include "SyncTest.h"
#include "Person.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CPerson::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IPerson,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CPerson::LockAccess()
{
	m_CS.Lock();
	return S_OK;
}


STDMETHODIMP CPerson::SetFirstName(BSTR bsFirstName)
{
	m_bsFirstName = bsFirstName;
	return S_OK;
}

STDMETHODIMP CPerson::SetLastName(BSTR bsLastName)
{
	m_bsLastName = bsLastName;
	return S_OK;
}

STDMETHODIMP CPerson::UnlockAccess()
{
	m_CS.Unlock();
	return S_OK;
}

// forgot to put a lock
STDMETHODIMP CPerson::GetName(BSTR *pbsFirstName, BSTR *pbsLastName)
{
	*pbsFirstName = m_bsFirstName.Copy();
	*pbsLastName = m_bsLastName.Copy();

	return S_OK;
}
