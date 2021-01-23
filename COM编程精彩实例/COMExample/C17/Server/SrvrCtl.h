#if !defined(AFX_SERVERCTL_H__A039CB75_AE33_11D3_8088_000000000000__INCLUDED_)
#define AFX_SERVERCTL_H__A039CB75_AE33_11D3_8088_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// SrvrCtl.h : Declaration of the CServerCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CServerCtrl : See SrvrCtl.cpp for implementation.

class CServerCtrl : public COleControl
{
	DECLARE_DYNCREATE(CServerCtrl)

// Constructor
public:
	CServerCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CServerCtrl();

	DECLARE_OLECREATE_EX(CServerCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CServerCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CServerCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CServerCtrl)		// Type name and misc status

	// Subclassed control support
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// Message maps
	//{{AFX_MSG(CServerCtrl)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CServerCtrl)
	long m_property2;
	afx_msg void OnProperty2Changed();
	afx_msg long GetProperty1();
	afx_msg void SetProperty1(long nNewValue);
	afx_msg long Method1(long lArg);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CServerCtrl)
	void FireEvent1(long lArg)
		{FireEvent(eventidEvent1,EVENT_PARAM(VTS_I4), lArg);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CServerCtrl)
	dispidProperty1 = 2L,
	dispidProperty2 = 1L,
	dispidMethod1 = 3L,
	eventidEvent1 = 1L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERCTL_H__A039CB75_AE33_11D3_8088_000000000000__INCLUDED)
