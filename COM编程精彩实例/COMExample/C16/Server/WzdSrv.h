#if !defined(AFX_WZDSRV_H__4487D433_A6FF_11D3_A398_00C04F570E2C__INCLUDED_)
#define AFX_WZDSRV_H__4487D433_A6FF_11D3_A398_00C04F570E2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WzdSrv.h : header file
//

#include "..\IServer\IWzd.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdSrv command target

class CWzdSrv : public CCmdTarget
{
	DECLARE_DYNCREATE(CWzdSrv)

	CWzdSrv();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWzdSrv)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL
    // override for aggregation
    virtual BOOL OnCreateAggregates();


// Implementation
protected:
	virtual ~CWzdSrv();

	// Generated message map functions
	//{{AFX_MSG(CWzdSrv)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CWzdSrv)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CWzdSrv)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	BEGIN_INTERFACE_PART(WzdClass, IWzd)
		STDMETHOD_(HRESULT,Method2)(long, unsigned long);
	END_INTERFACE_PART(WzdClass)
private:
    IUnknown* m_punkWzdAgSvr;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDSRV_H__4487D433_A6FF_11D3_A398_00C04F570E2C__INCLUDED_)
