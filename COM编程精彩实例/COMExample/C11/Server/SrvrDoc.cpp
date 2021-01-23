// SrvrDoc.cpp : implementation of the CServerDoc class
//

#include "stdafx.h"
#include "Server.h"

#include "SrvrDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerDoc

IMPLEMENT_DYNCREATE(CServerDoc, CDocument)

BEGIN_MESSAGE_MAP(CServerDoc, CDocument)
	//{{AFX_MSG_MAP(CServerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CServerDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CServerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IServer to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {37D93329-A706-11D3-A398-00C04F570E2C}
static const IID IID_IServer =
{ 0x37d93329, 0xa706, 0x11d3, { 0xa3, 0x98, 0x0, 0xc0, 0x4f, 0x57, 0xe, 0x2c } };

BEGIN_INTERFACE_MAP(CServerDoc, CDocument)
	INTERFACE_PART(CServerDoc, IID_IServer, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerDoc construction/destruction

CServerDoc::CServerDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CServerDoc::~CServerDoc()
{
	AfxOleUnlockApp();
}

BOOL CServerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CServerDoc serialization

void CServerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CServerDoc diagnostics

#ifdef _DEBUG
void CServerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CServerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CServerDoc commands
