// Person.cpp : Implementation of CSyncTestNewApp and DLL registration.

#include "stdafx.h"
#include "SyncTestNew.h"
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

STDMETHODIMP CPerson::SetName(BSTR bsFirstName, BSTR bsLastName)
{
	CCPLWinSharedResource<PERSONINFO>::GUARD guard(m_Info);
	PERSONINFO& info = guard;

	info.bsFirstName = bsFirstName;
	info.bsLastName = bsLastName;

	return S_OK;
}
