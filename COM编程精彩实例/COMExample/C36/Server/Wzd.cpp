// Wzd.cpp : Implementation of CWzd
#include "stdafx.h"
#include "Server.h"
#include "Wzd.h"
#include <comdef.h>

/////////////////////////////////////////////////////////////////////////////
// CWzd

HRESULT CWzd::Activate()
{
	HRESULT hr = GetObjectContext(&m_spObjectContext);
	if (SUCCEEDED(hr))
		return S_OK;
	return hr;
} 

BOOL CWzd::CanBePooled()
{
	return TRUE;
} 

void CWzd::Deactivate()
{
	m_spObjectContext.Release();
} 


STDMETHODIMP CWzd::Method1(long lArg)
{
	HRESULT hr=S_OK;
	try
	{
		// use ADO to access database


		// create other MTS objects




	}
	catch(_com_error& e)
	{
		hr=e.Error();
	}
	catch (...)
	{
		hr=E_FAIL;
	}

	// if context object exists (we're not in debug environment)
	if (m_spObjectContext)
	{
		if(FAILED(hr))
			m_spObjectContext->SetAbort();
		else
			m_spObjectContext->SetComplete();
	}
	return hr;
}
