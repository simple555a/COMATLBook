// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Tester.h"
#include "TestDlg.h"

#import "c:\Program files\Common files\System\ADO\MSADO15.dll" rename("EOF", "_EOF")
using namespace ADODB;

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
////////////////     CREATE THE ADO COM OBJECT    ////////////////////////
//////////////////////////////////////////////////////////////////////////
	_CommandPtr command(__uuidof(Command));
	_ConnectionPtr connection(__uuidof(Connection));	
	try
	{
//////////////////////////////////////////////////////////////////////////
////////////////     OPEN THE DATABASE    ////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// initialize connection object
	connection->PutConnectionTimeout(
				1000		//default is DEFAULT_DBCONNECTPROP
				);

// open connection to db	
	connection->Open(
				L"WZDDB",			// connection string DSN (other ex:"MSOracle8") 
				L"",				// user id
				L"",				// password
				adCmdUnspecified
				); 	

// initialize command object
	command->PutRefActiveConnection(connection);
			
//////////////////////////////////////////////////////////////////////////
////////////////     GET A RECORD SET (w/SQL)  ///////////////////////////
//////////////////////////////////////////////////////////////////////////
	_RecordsetPtr rs(__uuidof(Recordset));

// specify SQL command
	// *NOTE: SQL will not retrieve blobs--must use Stored Procedure
	command->PutCommandText(L"SELECT * FROM CUSTOMERS");
	command->PutCommandType(adCmdText);	// what text in command specifies. also:
									  // adCmdStoredProc - stored procedure
							   		  // adCmdTable - table name
							   		  // adCmdFile - file name
							   		  // adCmdTableDirect - 
							   		  // adCmdUnknown - unknown

// open record set
	rs->Open((_Command*)command, 				// source of record set--can be a SQL statement, etc.--see last param
			vtMissing, 				// active connection object (optional)
			adOpenForwardOnly,		// cursor type. also:
										 // adOpenForwardOnly 
										 //	adOpenKeyset Opens a keyset-type cursor. 
										 //	adOpenDynamic Opens a dynamic-type cursor. 
										 //	adOpenStatic Opens a static type cursor. 
			adLockOptimistic, 		// record set locking type. also:
										// adLockReadOnly -- read only
										// adLockPessimistic --lock records at the data source when editing
										// adLockOptimistic -- lock records only when you call the Update method. 
										// adLockBatchOptimistic -- same as above, used with batch mode
			adCmdUnspecified		// define source param--here we can use a command object. also:
											// adCmdText indicates source is a SQL statement
											// adCmdTable indicates source is a table name. 
											// adCmdStoredProc indicates source as a stored procedure. 
											// adCmdUnknown indicates source argument is not known. 
			);

//////////////////////////////////////////////////////////////////////////
////////////////  SCROLL THROUGH RECORDSET (COLUMNS & ROWS) //////////////
//////////////////////////////////////////////////////////////////////////

	while (!rs->Get_EOF())
	{
		_variant_t CustomerID=rs->GetCollect(L"CustomerID");
		_variant_t CompanyName=rs->GetCollect(L"CompanyName");
		_variant_t ContactName=rs->GetCollect(L"ContactName");
		rs->Move(1);					//# of records to move (can be negative if adOpenDynamic in Open())
	}
	rs->MoveFirst();


//////////////////////////////////////////////////////////////////////////
////////////////  ADD A RECORD TO A DATABASE /////////////////////////////
//////////////////////////////////////////////////////////////////////////
	// will allow these depending on the locking mode the record set was open with
	if (rs->Supports(adAddNew) && rs->Supports(adUpdate))
	{

	rs->AddNew();
	rs->PutCollect(L"CustomerID",L"BONCO");
	rs->PutCollect(L"CompanyName",L"Franks");
	rs->PutCollect(L"ContactName",L"Runk");
	rs->Update();
	

//////////////////////////////////////////////////////////////////////////
////////////////  EDIT A RECORD IN A DATABASE /////////////////////////////
//////////////////////////////////////////////////////////////////////////
	rs->PutCollect(L"ContactName",L"Smith");
	rs->Update();

//////////////////////////////////////////////////////////////////////////
////////////////  DELETE A RECORD FROM THE DATABASE //////////////////////
//////////////////////////////////////////////////////////////////////////
	rs->Delete(
		adAffectCurrent	//can also be adAffectGroup which deletes all rows in Filter object
		);
	}
//////////////////////////////////////////////////////////////////////////
////////////////  CLOSE RECORDSET ////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
	rs->Close();

//////////////////////////////////////////////////////////////////////////
////////////////  EXECUTE A STORED PROCEDURE /////////////////////////////
//////////////////////////////////////////////////////////////////////////

	// specify timeout (optional)
	command->PutCommandTimeout(
				1000				//default is DEFAULT_DBCONNECTPROP
				);

	// specify stored procedure
	command->PutCommandText(L"Customers Query");
	command->PutCommandType(adCmdStoredProc);

	// in order and one-by-one, add the calling parameter(s) required by the stored procedure
	command->GetParameters()->Append(command->CreateParameter(
			_bstr_t(""),		 		// a user assigned parameter name (optional)
			adInteger,					// data type. other common ones:
											 //	adUnsignedInt
											 //	adBSTR 
											 //	adArray|adBinary -- blob
			adParamInput,				// direction. also:
											 //	adParamOutput
											 //	adParamInputOutput
											 //	adParamReturnValue
			5,							// database column size for this parameter required by SP (must be a long)
			_variant_t(1234L) 			//if adParamInput or adParamInputOutput, the input value as a variant
			));

	// execute stored procedure
	command->Execute(
			NULL, 						// returned number of records affected
			NULL, 						// an array of variants that can be used with command
										//  (in lieu of appending above)
			adCmdStoredProc				// what text in command specifies. also:
										  // adCmdText - SQL statement
										  // adCmdTable - table name
										  // adCmdFile - file name
										  // adCmdTableDirect - 
										  // adCmdUnknown - unknown
			);		

	// retrieve an out parameter (if parameter direction is adParamOutput, adParamInputOutput or adParamReturnValue)
	// retrieve a long from the zeroth parameter
	long vt=command->GetParameters()->GetItem(_variant_t(0L))->GetValue().vt; //retrieve the 0 parameter
	// retrieve a variant the zeroth parameter
	_variant_t vart=command->GetParameters()->GetItem(_variant_t(0L))->GetValue().Detach();
	

//////////////////////////////////////////////////////////////////////////
///////////  EXECUTE A STORED PROCEDURE THAT RETURNS A RECORDSET /////////
//////////////////////////////////////////////////////////////////////////

// specify stored procedure with spot where recordset will be returned marked with "resultset"
	command->PutCommandText(L"{ call Wzd.Package.SP(?,?,?,?,{resultset 1024, my_out})}");	
	command->PutCommandType(adCmdText);		

// add input parameters only, one for each "?" in stored procedure call above
	command->GetParameters()->Append(command->CreateParameter(
			_bstr_t(""),		 		// a user assigned parameter name (optional)
			adInteger,					// data type. other common ones:
											 //	adUnsignedInt
											 //	adBSTR 
											 //	adArray|adBinary -- blob
			adParamInput,
			5,							// database column size for this parameter required by SP (must be a long)
			_variant_t(1234L) 			//if adParamInput or adParamInputOutput, the input value as a variant
			));


// open, scroll through and close record set as above
	rs->Open((_Command*)command,vtMissing,adOpenForwardOnly,adLockReadOnly,adCmdUnspecified);
	rs->Close();

//////////////////////////////////////////////////////////////////////////
////////////////////  USE TRANSACTIONS  //////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// or just use MTS/COM+ objects
	connection->BeginTrans();

	connection->CommitTrans();

//	connection->RollbackTrans();


//////////////////////////////////////////////////////////////////////////
////////////////////  DISCONNECT FROM DATABASE ///////////////////////////
//////////////////////////////////////////////////////////////////////////
	connection->Close();


//////////////////////////////////////////////////////////////////////////
////////////////////  SCROLL THROUGH ADO ERRORS //////////////////////////
//////////////////////////////////////////////////////////////////////////
	}
	catch(_com_error& e)
	{
		ErrorsPtr pErrors=connection->GetErrors();
		if (pErrors->GetCount()==0)
		{
			AfxMessageBox(e.ErrorMessage());
		}
		else
		{
			for (int i=0;i<pErrors->GetCount();i++)
			{
				_bstr_t desc=pErrors->GetItem((long)i)->GetDescription();
				AfxMessageBox(desc);
			}
		}
	}
	catch(...)
	{
	}
	
}
