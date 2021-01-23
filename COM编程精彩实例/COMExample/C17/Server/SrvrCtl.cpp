// SrvrCtl.cpp : Implementation of the CServerCtrl ActiveX Control class.

#include "stdafx.h"
#include "Server.h"
#include "SrvrCtl.h"
#include "SrvrPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CServerCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CServerCtrl, COleControl)
	//{{AFX_MSG_MAP(CServerCtrl)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	ON_MESSAGE(OCM_COMMAND, OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CServerCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CServerCtrl)
	DISP_PROPERTY_NOTIFY(CServerCtrl, "Property2", m_property2, OnProperty2Changed, VT_R4)
	DISP_PROPERTY_EX(CServerCtrl, "Property1", GetProperty1, SetProperty1, VT_I4)
	DISP_FUNCTION(CServerCtrl, "Method1", Method1, VT_I4, VTS_I4)
	DISP_STOCKFUNC_REFRESH()
	DISP_STOCKPROP_APPEARANCE()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CServerCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CServerCtrl, COleControl)
	//{{AFX_EVENT_MAP(CServerCtrl)
	EVENT_CUSTOM("Event1", FireEvent1, VTS_I4)
	EVENT_STOCK_CLICK()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CServerCtrl, 1)
	PROPPAGEID(CServerPropPage::guid)
END_PROPPAGEIDS(CServerCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CServerCtrl, "SERVER.ServerCtrl.1",
	0xa039cb67, 0xae33, 0x11d3, 0x80, 0x88, 0, 0, 0, 0, 0, 0)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CServerCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DServer =
		{ 0xa039cb65, 0xae33, 0x11d3, { 0x80, 0x88, 0, 0, 0, 0, 0, 0 } };
const IID BASED_CODE IID_DServerEvents =
		{ 0xa039cb66, 0xae33, 0x11d3, { 0x80, 0x88, 0, 0, 0, 0, 0, 0 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwServerOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CServerCtrl, IDS_SERVER, _dwServerOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::CServerCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CServerCtrl

BOOL CServerCtrl::CServerCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_SERVER,
			IDB_SERVER,
			afxRegApartmentThreading,
			_dwServerOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::CServerCtrl - Constructor

CServerCtrl::CServerCtrl()
{
	InitializeIIDs(&IID_DServer, &IID_DServerEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::~CServerCtrl - Destructor

CServerCtrl::~CServerCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::OnDraw - Drawing function

void CServerCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	DoSuperclassPaint(pdc, rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::DoPropExchange - Persistence support

void CServerCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	PX_Long( pPX, "Property2", m_property2, 1234 );

}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::OnResetState - Reset control to default state

void CServerCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::AboutBox - Display an "About" box to the user

void CServerCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_SERVER);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::PreCreateWindow - Modify parameters for CreateWindowEx

BOOL CServerCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	return COleControl::PreCreateWindow(cs);
}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::IsSubclassedControl - This is a subclassed control

BOOL CServerCtrl::IsSubclassedControl()
{
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl::OnOcmCommand - Handle command messages

LRESULT CServerCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
#ifdef _WIN32
	WORD wNotifyCode = HIWORD(wParam);
#else
	WORD wNotifyCode = HIWORD(lParam);
#endif

	// TODO: Switch on wNotifyCode here.

	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CServerCtrl message handlers

long CServerCtrl::Method1(long lArg) 
{
	// TODO: Add your dispatch handler code here

	return 0;
}

long CServerCtrl::GetProperty1() 
{
	// TODO: Add your property handler here

	return 0;
}

void CServerCtrl::SetProperty1(long nNewValue) 
{
	// TODO: Add your property handler here

	SetModifiedFlag();
}

void CServerCtrl::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	AfxMessageBox("Doubleclick");	
	COleControl::OnLButtonDblClk(nFlags, point);
}

void CServerCtrl::OnProperty2Changed() 
{
	// TODO: Add notification handler code

	SetModifiedFlag();
}
