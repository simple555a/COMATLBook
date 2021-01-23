// MyFileDB.cpp : Implementation of CTextFileDBApp and DLL registration.

#include "stdafx.h"
#include "TextFileDB.h"
#include "MyFileDB.h"
#include "MyFileDBCompensator.h"

/////////////////////////////////////////////////////////////////////////////
//

inline bool ISNOTNULL(IUnknown* p)
{
	return (NULL != p);
}

inline bool ISNULL(IUnknown* p)
{
	return (NULL == p);
}

STDMETHODIMP CMyFileDB::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IMyFileDB,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

CMyFileDB::CMyFileDB()
{
}

CMyFileDB::~CMyFileDB()
{
}

HRESULT CMyFileDB::InitCRM()
{
	if (ISNOTNULL(m_spCrmLC)) {
		m_spCrmLC = NULL;
	}

	HRESULT hr = ::CoCreateInstance(
		__uuidof(CRMClerk),
		NULL,
		CLSCTX_INPROC_SERVER,
		__uuidof(ICrmLogControl),
		(void**) &m_spCrmLC);

	if (FAILED(hr)) {
		return hr;
	}

	// Register the compensator. Try 5 times if recovery is in progress
	for(int i=0; i<5; i++) {
		hr = m_spCrmLC->RegisterCompensator(
			L"TextFileDB.MyFileDBCompensator",
			L"My file db compensator",
			CRMREGFLAG_ALLPHASES);

		if (SUCCEEDED(hr)) {
			return S_OK;
		}

		// deal with recovery in progress
		if (XACT_E_RECOVERYINPROGRESS == hr) {
			Sleep(1000); // sleep for a second
			continue; // and try again
		}
		break;
	}

	m_spCrmLC = NULL;
	return hr;
}

STDMETHODIMP CMyFileDB::Open(BSTR bsFilePath)
{
	HRESULT hr = InitCRM();
	if (FAILED(hr)) {
		return hr;
	}

	// Open the file
	USES_CONVERSION;
	LPCTSTR pszFile = W2T(bsFilePath);
	CMyFile file;
	hr = file.Open(pszFile, CMyFile::READ);
	if (FAILED(hr)) {
		m_spCrmLC->ForceTransactionToAbort();
		return hr;
	}

	// Log info with CRM that the file is being opened
	DBACTIONOPEN openAction;

	BLOB blobArray[2];
	blobArray[0].pBlobData = (BYTE*) &openAction;
	blobArray[0].cbSize = sizeof(DBACTIONOPEN);
	blobArray[1].pBlobData = (BYTE*) bsFilePath;
	blobArray[1].cbSize = ::SysStringByteLen(bsFilePath) + 
		sizeof(OLECHAR); // account for the end of string
	hr = m_spCrmLC->WriteLogRecord(blobArray, 2);
	if (FAILED(hr)) {
		m_spCrmLC->ForceTransactionToAbort();
		return hr;
	}

	// Now load file into memory
	hr = file.Load(m_AccountDB);
	if (FAILED(hr)) {
		m_spCrmLC->ForceTransactionToAbort();
		return hr;
	}

	return S_OK;
}

STDMETHODIMP CMyFileDB::GetBalance(BSTR bsClient, long *plBalance)
{
	*plBalance = 0;

	if (ISNULL(m_spCrmLC)) {
		return Error(OLESTR("File DB not opened"), GUID_NULL, E_FAIL);
	}

	MYACCOUNTDB::iterator i = m_AccountDB.find(bsClient);

	if (i == m_AccountDB.end()) {
		return Error(OLESTR("Account not found"), GUID_NULL, E_INVALIDARG);
	}

	*plBalance = (*i).second;
	return S_OK;

}

STDMETHODIMP CMyFileDB::UpdateBalance(BSTR bsClient, long lNewBalance)
{
	if (ISNULL(m_spCrmLC)) {
		return Error(OLESTR("File DB not opened"), GUID_NULL, E_FAIL);
	}

	MYACCOUNTDB::iterator i = m_AccountDB.find(bsClient);

	if (i == m_AccountDB.end()) {
		m_spCrmLC->ForceTransactionToAbort();
		return Error(OLESTR("Account not found"), GUID_NULL, E_INVALIDARG);
	}

	// Log info with CRM that the account is being updated
	DBACTIONUPDATE updateAction;
	updateAction.lNewBalance = lNewBalance;

	BLOB blobArray[2];
	blobArray[0].pBlobData = (BYTE*) &updateAction;
	blobArray[0].cbSize = sizeof(DBACTIONUPDATE);
	blobArray[1].pBlobData = (BYTE*) bsClient;
	blobArray[1].cbSize = ::SysStringByteLen(bsClient) + 
		sizeof(OLECHAR); // account for end of string
	HRESULT hr = m_spCrmLC->WriteLogRecord(blobArray, 2);
	if (FAILED(hr)) {
		m_spCrmLC->ForceTransactionToAbort();
		return hr;
	}

	// Update the in-memory account database
	(*i).second = lNewBalance;

	return S_OK;
}
