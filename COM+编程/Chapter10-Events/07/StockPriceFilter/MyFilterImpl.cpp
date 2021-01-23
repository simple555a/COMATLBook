// MyFilterImpl.cpp : Implementation of CStockPriceFilterApp and DLL registration.

#include "stdafx.h"
#include "StockPriceFilter.h"
#include "MyFilterImpl.h"

inline bool ISNULL(IUnknown* p)
{
	return (NULL == p);
}

inline bool ISNOTNULL(IUnknown* p)
{
	return (NULL != p);
}

#define RETURNIFFAILED(hr) { if (FAILED(hr)) return hr; }

/////////////////////////////////////////////////////////////////////////////
//

static CComBSTR g_bsMETHODNAME = "NewQuote";

CMyFilterImpl::CMyFilterImpl()
{
}

CMyFilterImpl::~CMyFilterImpl()
{
	m_spColl = NULL;
	m_spFC = NULL;
}

STDMETHODIMP CMyFilterImpl::Initialize(IMultiInterfaceEventControl *pMIEC)
{
	_ASSERT (ISNULL(m_spColl));

	int nErr = 0;
	HRESULT hr = pMIEC->GetSubscriptions(__uuidof(IMyStockPriceEvent),
										 g_bsMETHODNAME,
										 0,
										 &nErr,
										 &m_spColl);
	return hr;
}

STDMETHODIMP CMyFilterImpl::PrepareToFire(REFIID riid, BSTR methodname, IFiringControl* pFC)
{
	if (NULL == pFC)
		return E_INVALIDARG;

	_ASSERT (__uuidof(IMyStockPriceEvent) == riid);
	_ASSERT (!wcsicmp(methodname, g_bsMETHODNAME));

	m_spFC = pFC;

	return S_OK;
}

STDMETHODIMP CMyFilterImpl::NewQuote(/*[in]*/ BSTR bsSymbol, /*[in]*/ double dValue)
{
	_ASSERT (ISNOTNULL(m_spFC));
	_ASSERT (ISNOTNULL(m_spColl));

	CComPtr<IEnumEventObject> spEnum;
	HRESULT hr = m_spColl->get_NewEnum(&spEnum);
	RETURNIFFAILED(hr);

	ULONG nRet = 0;
	CComPtr<IUnknown> spUnk;
	while(S_OK == (hr = spEnum->Next(1, &spUnk, &nRet))) {
		CComPtr<IEventSubscription> spSub;
		hr = spUnk->QueryInterface(&spSub);
		RETURNIFFAILED(hr);
		spUnk = NULL;

		CComVariant v;
		hr = spSub->GetPublisherProperty(CComBSTR("MyLicenseKey"), &v);
		if (FAILED(hr)) {
			continue; // not a valid subscriber
		}

		if (wcscmp(V_BSTR(&v), L"1234")) {
			continue; // not a valid subscriber
		}

		hr = m_spFC->FireSubscription(spSub);
	}

	return hr;
}

