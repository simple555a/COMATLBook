// MyPhoneEntry.cpp : Implementation of CPhoneBookApp and DLL registration.

#include "stdafx.h"
#include "PhoneBook.h"
#include "MyPhoneEntry.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CMyPhoneEntry::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyPhoneEntry,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMyPhoneEntry::put_FirstName(BSTR newVal)
{
	m_bsFirstName = newVal;

	return S_OK;
}

STDMETHODIMP CMyPhoneEntry::put_LastName(BSTR newVal)
{
	m_bsLastName = newVal;

	return S_OK;
}

STDMETHODIMP CMyPhoneEntry::put_PhoneNumber(BSTR newVal)
{
	m_bsPhoneNumber = newVal;

	return S_OK;
}

ADOConnectionPtr OpenPhoneBookDB()
{
	ADOConnectionPtr spConn;
	HRESULT hr = spConn.CreateInstance(__uuidof(ADODB::Connection));
	CHECKHR(hr);

	_bstr_t bsDSN = "provider=sqloledb;database=PhoneBookDB";
	_bstr_t bsUser = "sa";
	hr = spConn->Open (bsDSN, bsUser, (LPCTSTR) NULL, NULL);
	CHECKHR(hr);
	return spConn;
}

void InsertEntry(ADOConnectionPtr spConn, 
				 BSTR bsLastName,
				 BSTR bsFirstName,
				 BSTR bsPhoneNumber)
{
	TCHAR buf[256];
	_stprintf(buf, _T("INSERT INTO Friends VALUES ('%S', '%S','%S')"),
		bsLastName, bsFirstName, bsPhoneNumber);

	_variant_t vRecordCount;
	spConn->Execute(buf, &vRecordCount,-1);
}

STDMETHODIMP CMyPhoneEntry::Update()
{
	try {
		ADOConnectionPtr spConn = OpenPhoneBookDB();
		InsertEntry(spConn, m_bsLastName, m_bsFirstName, m_bsPhoneNumber);
	}catch(_com_error& e) {
		return Error((LPCWSTR) e.Description(), __uuidof(IMyPhoneEntry), E_FAIL);
	}

	return S_OK;
}


STDMETHODIMP CMyPhoneEntry::Response(BSTR bsDesc)
{
	USES_CONVERSION;
	::MessageBox(NULL, W2T(bsDesc), _T("PhoneBook"), MB_OK);

	return S_OK;
}

STDMETHODIMP CMyPhoneEntry::UpdateWithResponse(BSTR bsClientMachine)
{
	CComBSTR bsDesc;
	try {
		ADOConnectionPtr spConn = OpenPhoneBookDB();
		InsertEntry(spConn, m_bsLastName, m_bsFirstName, m_bsPhoneNumber);
		bsDesc = "Added entry: ";
	}catch(_com_error& e) {
		bsDesc = static_cast<LPCWSTR>(e.Description());
	}

	bsDesc += m_bsFirstName;
	bsDesc += " ";
	bsDesc += m_bsLastName;

	// Construct display name for the moniker
	CComBSTR bsDisplayName = "queue:ComputerName=";
	bsDisplayName += bsClientMachine;
	bsDisplayName += "/new:PhoneBook.MyPhoneEntry";

	CComPtr<IMyPhoneEntry> spPhoneEntry;
	HRESULT hr = ::CoGetObject(bsDisplayName, NULL, 
		__uuidof(IMyPhoneEntry), (void**) &spPhoneEntry);
	if (FAILED(hr)) {
		return hr;
	}
	spPhoneEntry->Response(bsDesc);
	return S_OK;
}
