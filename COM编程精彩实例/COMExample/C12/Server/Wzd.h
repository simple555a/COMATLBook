#if !defined(AFX_WZD_H__351495F8_AA6D_11D3_807E_000000000000__INCLUDED_)
#define AFX_WZD_H__351495F8_AA6D_11D3_807E_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Wzd.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CWzd command target

class CWzd : public CCmdTarget
{
	DECLARE_DYNCREATE(CWzd)

	CWzd();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzd)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWzd();

	// Generated message map functions
	//{{AFX_MSG(CWzd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CWzd)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CWzd)
	afx_msg long GetProperty1();
	afx_msg void SetProperty1(long nNewValue);
	afx_msg void Method1(long lArg);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZD_H__351495F8_AA6D_11D3_807E_000000000000__INCLUDED_)
