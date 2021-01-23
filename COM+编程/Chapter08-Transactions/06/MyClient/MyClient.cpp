// MyClient.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

ADOConnectionPtr OpenAccountsDB(ITransaction* pTransaction)
{
	ADOConnectionPtr spConn;
	HRESULT hr = spConn.CreateInstance(__uuidof(ADODB::Connection));
	CHECKHR(hr);

	_bstr_t bsDSN = "provider=sqloledb;database=AccountsDB";
	_bstr_t bsUser = "sa";
	hr = spConn->Open (bsDSN, bsUser, (LPCTSTR) NULL, NULL);
	CHECKHR(hr);

	if (NULL == pTransaction) {
		return spConn;
	}

	ADODB::ADOConnectionConstructionPtr spConnConst = spConn;

	IUnknownPtr spUnk = spConnConst->Session;
	CComPtr<ITransactionJoin> spTranJoin;
	hr = spUnk->QueryInterface(__uuidof(ITransactionJoin), (void**) &spTranJoin);
	CHECKHR(hr);
	hr = spTranJoin->JoinTransaction(pTransaction,
		ISOLATIONLEVEL_ISOLATED, 0, NULL);
	CHECKHR(hr);

	return spConn;
}

void ReduceBalance(ADOConnectionPtr spConn, BSTR bsClient, long lDiff)
{
	TCHAR buf[256];
	_stprintf(buf, _T("UPDATE Accounts SET Balance = Balance - %ld WHERE [client] = '%S'"), 
		lDiff, (LPCWSTR) bsClient);

	_variant_t vRecordCount;
	spConn->Execute(buf, &vRecordCount,-1);
}

void sub();

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	CCPLComInitializer init;
	try {
		sub();
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	return 0;
}

void sub()
{
	CComPtr<ITransactionDispenser> spTxDisp;
	HRESULT hr = ::DtcGetTransactionManager(
		NULL,							// host name
		NULL,							// TM name
		__uuidof(ITransactionDispenser),// interface
		0,								// reserved
		0,								// reserved
		0,								// reserved
		(void**) &spTxDisp);			// [out] pointer
	CHECKHR(hr);

	CComPtr<ITransaction> spTx;
	hr = spTxDisp->BeginTransaction(
		NULL,							// outer component
		ISOLATIONLEVEL_ISOLATED,		// Isolation level
		ISOFLAG_RETAIN_DONTCARE,		// Isolation flag
		NULL,							// Options
		&spTx);							// [out] pointer
	if (FAILED(hr)) {
		_com_issue_errorex(hr, spTxDisp, 
			__uuidof(ITransactionDispenser));
	}

	// ADOConnectionPtr spConn = OpenAccountsDB(NULL);
	ADOConnectionPtr spConn = OpenAccountsDB(spTx);
	ReduceBalance(spConn, _bstr_t("Don"),10);
	// spTx->Abort(NULL, 0, FALSE);
	hr = spTx->Commit(0, XACTTC_SYNC_PHASEONE, 0);
	if (FAILED(hr)) {
		_com_issue_errorex(hr, spTx, 
			__uuidof(ITransaction));
	}

}


