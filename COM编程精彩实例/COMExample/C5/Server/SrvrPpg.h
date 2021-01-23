#if !defined(AFX_SERVERPPG_H__A039CB77_AE33_11D3_8088_000000000000__INCLUDED_)
#define AFX_SERVERPPG_H__A039CB77_AE33_11D3_8088_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// SrvrPpg.h : Declaration of the CServerPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CServerPropPage : See SrvrPpg.cpp.cpp for implementation.

class CServerPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CServerPropPage)
	DECLARE_OLECREATE_EX(CServerPropPage)

// Constructor
public:
	CServerPropPage();

// Dialog Data
	//{{AFX_DATA(CServerPropPage)
	enum { IDD = IDD_PROPPAGE_SERVER };
	CString	m_Appearance;
	CString	m_Property1;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CServerPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERPPG_H__A039CB77_AE33_11D3_8088_000000000000__INCLUDED)
