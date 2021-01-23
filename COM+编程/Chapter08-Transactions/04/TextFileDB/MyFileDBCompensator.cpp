// MyFileDBCompensator.cpp : Implementation of CTextFileDBApp and DLL registration.

#include "stdafx.h"
#include "TextFileDB.h"
#include "MyFileDBCompensator.h"

/////////////////////////////////////////////////////////////////////////////
//

CMyFileDBCompensator::CMyFileDBCompensator()
{

}

CMyFileDBCompensator::~CMyFileDBCompensator()
{
	
}

STDMETHODIMP CMyFileDBCompensator::SetLogControl( 
    /* [in] */ ICrmLogControl __RPC_FAR *pLogControl)
{
	return S_OK;
}

STDMETHODIMP CMyFileDBCompensator::BeginPrepare( void)
{
	return S_OK;
}

STDMETHODIMP CMyFileDBCompensator::PrepareRecord( 
    /* [in] */ CrmLogRecordRead crmLogRec,
    /* [retval][out] */ BOOL __RPC_FAR *pfForget)
{
	*pfForget = FALSE; // do not drop any records

	return S_OK;
}

STDMETHODIMP CMyFileDBCompensator::EndPrepare( 
    /* [retval][out] */ BOOL __RPC_FAR *pfOkToPrepare)
{
	*pfOkToPrepare = TRUE;
	return S_OK;
}

STDMETHODIMP CMyFileDBCompensator::BeginCommit( 
    /* [in] */ BOOL fRecovery)
{
	return S_OK;
}

STDMETHODIMP CMyFileDBCompensator::CommitRecord( 
    /* [in] */ CrmLogRecordRead crmLogRec,
    /* [retval][out] */ BOOL __RPC_FAR *pfForget)
{
	*pfForget = FALSE; // don't drop the record
	BLOB& blob = crmLogRec.blobUserData;
	DBACTION* pAction = reinterpret_cast<DBACTION*>(blob.pBlobData);
	if (dbOpen == pAction->actionType) {
		DBACTIONOPEN* pActionOpen = reinterpret_cast<DBACTIONOPEN*>(pAction);
		m_bsFilePath = pActionOpen->pszFileName;

		// load the contents of the file
		USES_CONVERSION;
		CMyFile file;
		HRESULT hr = file.Open(W2T(m_bsFilePath), CMyFile::READ);
		if (FAILED(hr)) { 
			return hr; 
		}
		hr = file.Load(m_AccountDB);
		if (FAILED(hr)) {
			return hr;
		}
		return S_OK;
	}

	if (dbUpdate == pAction->actionType) {
		DBACTIONUPDATE* pActionUpdate = reinterpret_cast<DBACTIONUPDATE*>(pAction);
		long lNewBalance = pActionUpdate->lNewBalance;
		LPWSTR pwszClient = pActionUpdate->pszClient;
		MYACCOUNTDB::iterator i = m_AccountDB.find(pwszClient);
		if (i == m_AccountDB.end()) {
			return E_INVALIDARG;
		}
		(*i).second = lNewBalance;

		return S_OK;
	}

	return S_OK;
}

STDMETHODIMP CMyFileDBCompensator::EndCommit( void)
{
	// Save the information back to file
	USES_CONVERSION;
	CMyFile file;
	HRESULT hr = file.Open(W2T(m_bsFilePath), CMyFile::WRITE);
	if (FAILED(hr)) {
		return hr;
	}
	file.Save(m_AccountDB);
	return S_OK;
}

STDMETHODIMP CMyFileDBCompensator::BeginAbort( 
    /* [in] */ BOOL fRecovery)
{
	return S_OK;
}

STDMETHODIMP CMyFileDBCompensator::AbortRecord( 
    /* [in] */ CrmLogRecordRead crmLogRec,
    /* [retval][out] */ BOOL __RPC_FAR *pfForget)
{
	return S_OK;
}

STDMETHODIMP CMyFileDBCompensator::EndAbort( void)
{
	return S_OK;
}

