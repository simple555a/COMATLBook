// AggSvr.h : main header file for the AGGSVR DLL
//

#if !defined(AFX_AGGSVR_H__603F1E00_A7D8_11D3_A398_00C04F570E2C__INCLUDED_)
#define AFX_AGGSVR_H__603F1E00_A7D8_11D3_A398_00C04F570E2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAggSvrApp
// See AggSvr.cpp for the implementation of this class
//

class CAggSvrApp : public CWinApp
{
public:
	CAggSvrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAggSvrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CAggSvrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AGGSVR_H__603F1E00_A7D8_11D3_A398_00C04F570E2C__INCLUDED_)
