// MyClient.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

ADOConnectionPtr OpenDB(LPCTSTR pszDbName)
{
	ADOConnectionPtr spConn;
	HRESULT hr = spConn.CreateInstance(__uuidof(ADODB::Connection));
	CHECKHR(hr);

	TCHAR buf[200];
	_stprintf(buf,
		_T("DSN=LocalServer;database=%s;UID=sa;PWD=;"), 
		pszDbName);

	_bstr_t bsDSN = buf;
	// _bstr_t bsUser = "sa";
	hr = spConn->Open (bsDSN, (LPCTSTR) NULL, (LPCTSTR) NULL, NULL);
	CHECKHR(hr);

	return spConn;
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
	ADOConnectionPtr spConn[10];
	for (int i=0; i<10;i++) {
		TCHAR buf[100];
		_stprintf(buf, _T("MyDB%d"), i);
		spConn[i] = OpenDB(buf);
	}
}


