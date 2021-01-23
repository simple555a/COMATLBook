#if !defined(AFX_WZDSRV_H__4487D433_A6FF_11D3_A398_00C04F570E2C__INCLUDED_)
#define AFX_WZDSRV_H__4487D433_A6FF_11D3_A398_00C04F570E2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WzdSrv.h : header file
//
#include "afxctl.h"
#include "..\IServer\IWzd.h"

/////////////////////////////////////////////////////////////////////////////
// Implement our own derivation of COleObjectFactory class factory

class CWzdOleObjectFactory : public COleObjectFactory
{
public:
	CWzdOleObjectFactory( REFCLSID clsid, CRuntimeClass* pRuntimeClass, 
		BOOL bMultiInstance, LPCTSTR lpszProgID ) :
			COleObjectFactory(clsid,pRuntimeClass,bMultiInstance,lpszProgID)
			{};

	virtual BOOL VerifyUserLicense()
	{
		return AfxVerifyLicFile(AfxGetInstanceHandle(),"licence.lic",L"1234567890",-1);
	}
};


#define DECLARE_OLECREATE_WZD(class_name) \
public: \
	static AFX_DATA CWzdOleObjectFactory factory; \
	static AFX_DATA const GUID guid; \

#define IMPLEMENT_OLECREATE_WZD(class_name, external_name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
	AFX_DATADEF CWzdOleObjectFactory class_name::factory(class_name::guid, \
		RUNTIME_CLASS(class_name), FALSE, _T(external_name)); \
	AFX_COMDAT const AFX_DATADEF GUID class_name::guid = \
		{ l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }; \

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
	BOOL VerifyUserLicense();

// Implementation
protected:
	virtual ~CWzdSrv();

	// Generated message map functions
	//{{AFX_MSG(CWzdSrv)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE_WZD(CWzdSrv)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CWzdSrv)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
	BEGIN_INTERFACE_PART(WzdClass, IWzd)
		STDMETHOD_(HRESULT,Method1)(long, long *);
		STDMETHOD_(HRESULT,Method2)(long, unsigned long);
	END_INTERFACE_PART(WzdClass)

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WZDSRV_H__4487D433_A6FF_11D3_A398_00C04F570E2C__INCLUDED_)
