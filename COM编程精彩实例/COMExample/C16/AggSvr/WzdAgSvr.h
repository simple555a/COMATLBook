#if !defined(AFX_WZDAGGSVR_H__603F1E0D_A7D8_11D3_A398_00C04F570E2C__INCLUDED_)
#define AFX_WZDAGGSVR_H__603F1E0D_A7D8_11D3_A398_00C04F570E2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WzdAgSvr.h : header file
//

#include "..\IAggSvr\IWzdAgg.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdAgSvr command target

class CWzdAgSvr : public CCmdTarget
{
	DECLARE_DYNCREATE(CWzdAgSvr)

	CWzdAgSvr();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdAgSvr)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWzdAgSvr();

	// Generated message map functions
	//{{AFX_MSG(CWzdAgSvr)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CWzdAgSvr)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CWzdAgSvr)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	BEGIN_INTERFACE_PART(WzdClass, IWzdAgg)
		STDMETHOD_(HRESULT,Method1)(long, long*);
	END_INTERFACE_PART(WzdClass)
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDAGGSVR_H__603F1E0D_A7D8_11D3_A398_00C04F570E2C__INCLUDED_)
