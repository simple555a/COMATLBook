// WzdSrv.cpp : implementation file
//

#include "stdafx.h"
#include "Server.h"
#include "WzdSrv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdSrv

IMPLEMENT_DYNCREATE(CWzdSrv, CCmdTarget)

CWzdSrv::CWzdSrv()
{
	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

CWzdSrv::~CWzdSrv()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}


void CWzdSrv::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BOOL CWzdSrv::VerifyUserLicense()
{
	return TRUE;
}




BEGIN_MESSAGE_MAP(CWzdSrv, CCmdTarget)
	//{{AFX_MSG_MAP(CWzdSrv)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CWzdSrv, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CWzdSrv)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IWzdSrv to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {4487D431-A6FF-11D3-A398-00C04F570E2C}
static const IID IID_IWzdSrv =
{ 0x4487d431, 0xa6ff, 0x11d3, { 0xa3, 0x98, 0x0, 0xc0, 0x4f, 0x57, 0xe, 0x2c } };

// add this line from idl project (iwzd_i.c)
const IID IID_IWzd = {0xC177116E,0x9AAA,0x11D3,{0x80,0x5D,0x00,0x00,0x00,0x00,0x00,0x00}};

BEGIN_INTERFACE_MAP(CWzdSrv, CCmdTarget)
	INTERFACE_PART(CWzdSrv, IID_IWzdSrv, Dispatch)
	INTERFACE_PART(CWzdSrv, IID_IWzd, WzdClass) // add this line
END_INTERFACE_MAP()

// {4487D432-A6FF-11D3-A398-00C04F570E2C}
IMPLEMENT_OLECREATE_WZD(CWzdSrv, "Server.WzdSrv", 0x4487d432, 0xa6ff, 0x11d3, 0xa3, 0x98, 0x0, 0xc0, 0x4f, 0x57, 0xe, 0x2c)

/////////////////////////////////////////////////////////////////////////////
// CWzdSrv message handlers



//////////////////////////////////////////////////////////////
/// XWzdClass Implementation
ULONG FAR EXPORT CWzdSrv::XWzdClass::AddRef()
{
	METHOD_PROLOGUE(CWzdSrv, WzdClass);
	return pThis->ExternalAddRef();//pThis accesses enclosing class's this pointer
}

ULONG FAR EXPORT CWzdSrv::XWzdClass::Release()
{
	METHOD_PROLOGUE(CWzdSrv, WzdClass);
	return pThis->ExternalRelease();
}

HRESULT FAR EXPORT CWzdSrv::XWzdClass::QueryInterface(REFIID iid, void FAR* FAR* ppvObj)
{
	METHOD_PROLOGUE(CWzdSrv, WzdClass);
    return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CWzdSrv::XWzdClass::Method1(long lArg1, long *plArg2)
{
	METHOD_PROLOGUE(CWzdSrv, WzdClass);

	return S_OK;
}

STDMETHODIMP CWzdSrv::XWzdClass::Method2(long lArg, unsigned long ulArg)
{
	METHOD_PROLOGUE(CWzdSrv, WzdClass);

	return S_OK;
}
