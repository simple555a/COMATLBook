// SrvrPpg.cpp : Implementation of the CServerPropPage property page class.

#include "stdafx.h"
#include "Server.h"
#include "SrvrPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CServerPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CServerPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CServerPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CServerPropPage, "SERVER.ServerPropPage.1",
	0xa039cb68, 0xae33, 0x11d3, 0x80, 0x88, 0, 0, 0, 0, 0, 0)


/////////////////////////////////////////////////////////////////////////////
// CServerPropPage::CServerPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CServerPropPage

BOOL CServerPropPage::CServerPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_SERVER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CServerPropPage::CServerPropPage - Constructor

CServerPropPage::CServerPropPage() :
	COlePropertyPage(IDD, IDS_SERVER_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CServerPropPage)
	m_Appearance = _T("");
	m_Property1 = _T("");
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CServerPropPage::DoDataExchange - Moves data between page and properties

void CServerPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CServerPropPage)
	DDP_Text(pDX, IDC_EDIT1, m_Appearance, _T("Appearance") );
	DDX_Text(pDX, IDC_EDIT1, m_Appearance);
	DDP_Text(pDX, IDC_EDIT2, m_Property1, _T("Property1") );
	DDX_Text(pDX, IDC_EDIT2, m_Property1);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CServerPropPage message handlers
