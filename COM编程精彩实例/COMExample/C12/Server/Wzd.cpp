// Wzd.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "Wzd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzd

IMPLEMENT_DYNCREATE(CWzd, CCmdTarget)

CWzd::CWzd()
{
	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

CWzd::~CWzd()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}


void CWzd::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CWzd, CCmdTarget)
	//{{AFX_MSG_MAP(CWzd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CWzd, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CWzd)
	DISP_PROPERTY_EX(CWzd, "Property1", GetProperty1, SetProperty1, VT_I4)
	DISP_FUNCTION(CWzd, "Method1", Method1, VT_EMPTY, VTS_I4)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IWzd to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {351495F7-AA6D-11D3-807E-000000000000}
static const IID IID_IWzd =
{ 0x351495f7, 0xaa6d, 0x11d3, { 0x80, 0x7e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 } };

BEGIN_INTERFACE_MAP(CWzd, CCmdTarget)
	INTERFACE_PART(CWzd, IID_IWzd, Dispatch)
END_INTERFACE_MAP()

// {351495D1-AA6D-11D3-807E-000000000000}
IMPLEMENT_OLECREATE(CWzd, "Server.Wzd", 0x351495d1, 0xaa6d, 0x11d3, 0x80, 0x7e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0)

/////////////////////////////////////////////////////////////////////////////
// CWzd message handlers

void CWzd::Method1(long lArg) 
{
	// TODO: Add your dispatch handler code here
}

long CWzd::GetProperty1() 
{
	// TODO: Add your property handler here

	return 0;
}

void CWzd::SetProperty1(long nNewValue) 
{
	// TODO: Add your property handler here

}
