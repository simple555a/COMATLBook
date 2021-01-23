#if !defined(AFX_SERVER_H__A039CB6D_AE33_11D3_8088_000000000000__INCLUDED_)
#define AFX_SERVER_H__A039CB6D_AE33_11D3_8088_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Server.h : main header file for SERVER.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CServerApp : See Server.cpp for implementation.

class CServerApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVER_H__A039CB6D_AE33_11D3_8088_000000000000__INCLUDED)
