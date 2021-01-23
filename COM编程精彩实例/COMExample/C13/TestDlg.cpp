// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include <afxctl.h>
#include "Tester.h"
#include "TestDlg.h"
#include <comdef.h>

#include "IServer\IWzd.h"
#include "ISinkSrv\IWzdSink.h"
#include "guids.h"
#include <objbase.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// works because CDialog is eventually derived from CCmdTarget
BEGIN_INTERFACE_MAP (CTestDlg, CDialog)
    INTERFACE_PART (CTestDlg, IID_IWzdSink, WzdSinkClass)
END_INTERFACE_MAP ()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestDlg::OnTest() 
{
//////////////////////////////////////////////////////////////////////////
////////////////     CREATE THE COM OBJECT    ///////////////////////////
//////////////////////////////////////////////////////////////////////////

	IWzd *iWzd=NULL;
	HRESULT hr=::CoCreateInstance(
				CLSID_IWzdSrv,		// name of dll to load
				NULL,				// aggregated COM object (none)
				CLSCTX_INPROC_SERVER,// use dll
				IID_IWzd,			// class to create and object of
				(LPVOID*) &iWzd);	// returned object pointer
	if (FAILED(hr))
	{
		_com_error err(hr);
		AfxMessageBox(err.ErrorMessage());
		return;
	}

//////////////////////////////////////////////////////////////////////////
////////////////   GET POINTER TO OUR OWN SINK OBJECT  ///////////////////
//////////////////////////////////////////////////////////////////////////
	IWzdSink *iWzdSink=NULL;
    hr = m_xWzdSinkClass.QueryInterface (IID_IWzdSink, (void**) &iWzdSink);
    m_xWzdSinkClass.Release(); // undo AddRef() performed by QI, unneeded when server is us


//////////////////////////////////////////////////////////////////////////
/////////////     CONNECT OUR SINK OBJECT TO SERVER //////////////////////
//////////////////////////////////////////////////////////////////////////
	DWORD dwConnectID;
	AfxConnectionAdvise(
				iWzd,				// the real server
				IID_IWzdSink,		// our sink's IID
				iWzdSink,			// our sink's pointer
				FALSE,				// TRUE == increment our sink object's ref count
				&dwConnectID);		// identifier for AfxConnectionUnadvise()

//////////////////////////////////////////////////////////////////////////
/////////////     CALL METHODS  ////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

	long lArg;
	iWzd->Method1(1234,&lArg);
	
	long lArg2=12345678L;
	unsigned long ulArg=4026531840L;
	iWzd->Method2(lArg2, ulArg);

//////////////////////////////////////////////////////////////////////////
/////////////     UNCONNECT OUR SINK OBJECT FROM SERVER //////////////////
//////////////////////////////////////////////////////////////////////////
	AfxConnectionUnadvise(
				iWzd,				// the real server
				IID_IWzdSink,		// our sink's IID
				iWzdSink,			// our sink's pointer
				FALSE,				// TRUE == decrement our sink object's ref count
				dwConnectID);		// identifier from AfxConnectionAdvise()

	iWzd->Release();
}

/////////////////////////////////////////////////////////////////////////////
// Implement IWzdSink methods
ULONG FAR EXPORT CTestDlg::XWzdSinkClass::AddRef()
{
	METHOD_PROLOGUE(CTestDlg, WzdSinkClass);
	return pThis->ExternalAddRef();//pThis accesses enclosing class's this pointer
}

ULONG FAR EXPORT CTestDlg::XWzdSinkClass::Release()
{
	METHOD_PROLOGUE(CTestDlg, WzdSinkClass);
	return pThis->ExternalRelease();
}

HRESULT FAR EXPORT CTestDlg::XWzdSinkClass::QueryInterface(REFIID iid, void FAR* FAR* ppvObj)
{
	METHOD_PROLOGUE(CTestDlg, WzdSinkClass);
    return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj);
}

HRESULT __stdcall CTestDlg::XWzdSinkClass::Callback(long lArg)
{
	METHOD_PROLOGUE(CTestDlg, WzdSinkClass);

    return S_OK;
}