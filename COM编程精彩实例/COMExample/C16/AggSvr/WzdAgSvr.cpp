// WzdAgSvr.cpp : implementation file
//

#include "stdafx.h"
#include "aggsvr.h"
#include "WzdAgSvr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWzdAgSvr

IMPLEMENT_DYNCREATE(CWzdAgSvr, CCmdTarget)

CWzdAgSvr::CWzdAgSvr()
{
	EnableAutomation();

	// allow this object to be aggregated by another
	EnableAggregation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

CWzdAgSvr::~CWzdAgSvr()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}


void CWzdAgSvr::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CWzdAgSvr, CCmdTarget)
	//{{AFX_MSG_MAP(CWzdAgSvr)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CWzdAgSvr, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CWzdAgSvr)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IWzdAgSvr to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {603F1E0B-A7D8-11D3-A398-00C04F570E2C}
static const IID IID_IWzdAgSvr =
{ 0x603f1e0b, 0xa7d8, 0x11d3, { 0xa3, 0x98, 0x0, 0xc0, 0x4f, 0x57, 0xe, 0x2c } };

// add this line from idl project (iwzdagg_i.c)
const IID IID_IWzdAgg = {0x7ECEE460,0xA804,0x11d3,{0xA3,0x98,0x00,0xC0,0x4F,0x57,0x0E,0x2C}};

BEGIN_INTERFACE_MAP(CWzdAgSvr, CCmdTarget)
	INTERFACE_PART(CWzdAgSvr, IID_IWzdAgSvr, Dispatch)
	INTERFACE_PART(CWzdAgSvr, IID_IWzdAgg, WzdClass) 
END_INTERFACE_MAP()

// {603F1E0C-A7D8-11D3-A398-00C04F570E2C}
IMPLEMENT_OLECREATE(CWzdAgSvr, "AggSvr.WzdAgSvr", 0x603f1e0c, 0xa7d8, 0x11d3, 0xa3, 0x98, 0x0, 0xc0, 0x4f, 0x57, 0xe, 0x2c)

/////////////////////////////////////////////////////////////////////////////
// CWzdAgSvr message handlers

//////////////////////////////////////////////////////////////
/// XWzdClass Implementation
ULONG FAR EXPORT CWzdAgSvr::XWzdClass::AddRef()
{
	METHOD_PROLOGUE(CWzdAgSvr, WzdClass);
	return pThis->ExternalAddRef();//pThis accesses enclosing class's this pointer
}

ULONG FAR EXPORT CWzdAgSvr::XWzdClass::Release()
{
	METHOD_PROLOGUE(CWzdAgSvr, WzdClass);
	return pThis->ExternalRelease();
}

HRESULT FAR EXPORT CWzdAgSvr::XWzdClass::QueryInterface(REFIID iid, void FAR* FAR* ppvObj)
{
	METHOD_PROLOGUE(CWzdAgSvr, WzdClass);
    return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP CWzdAgSvr::XWzdClass::Method1(long lArg1, long *plArg2)
{
	METHOD_PROLOGUE(CWzdAgSvr, WzdClass);

	return S_OK;
}
