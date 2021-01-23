// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
#define AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include "CplBase.h"
// ADO Stuff
#import "c:\program files\common files\system\ado\msado15.dll" rename ( "EOF", "adoEOF" )

typedef ADODB::_ConnectionPtr ADOConnectionPtr;
typedef ADODB::_RecordsetPtr ADORecordsetPtr;

#define CHECKHR(hr) \
   { if (FAILED(hr)) _com_issue_error(hr ); }


#include <windows.h>
#include <comsvcs.h>
#include <xolehlp.h>
#include <oledb.h>
#include <atlbase.h>

#pragma comment(lib, "xolehlp.lib")

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
