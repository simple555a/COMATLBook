// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__9E562B04_0B95_4A89_BA48_DA815B3B1941__INCLUDED_)
#define AFX_STDAFX_H__9E562B04_0B95_4A89_BA48_DA815B3B1941__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif
#define _ATL_APARTMENT_THREADED

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>

// ADO Stuff
#import "c:\program files\common files\system\ado\msado15.dll" rename ( "EOF", "adoEOF" )

typedef ADODB::_ConnectionPtr ADOConnectionPtr;
typedef ADODB::_RecordsetPtr ADORecordsetPtr;

#define CHECKHR(hr) \
   { if (FAILED(hr)) _com_issue_error(hr ); }



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__9E562B04_0B95_4A89_BA48_DA815B3B1941__INCLUDED)
