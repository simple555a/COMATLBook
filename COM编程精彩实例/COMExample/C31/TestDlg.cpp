// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "atlconv.h"
#include "Tester.h"
#include "TestDlg.h"

#import "server\server.tlb" no_namespace

#define ARRAYSIZE 27

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
////////////////     CREATE THE COM OBJECT    ///////////////////////////
//////////////////////////////////////////////////////////////////////////
	IWzdPtr pPtr;
	HRESULT hr=pPtr.CreateInstance(__uuidof(Wzd));
	if (FAILED(hr))
	{
		_com_error err(hr);
		AfxMessageBox(err.ErrorMessage());
		return;
	}

//////////////////////////////////////////////////////////////////////////
////////////////     PASSING SIMPLE DATA    ///////////////////////////
//////////////////////////////////////////////////////////////////////////
	// passing bytes, shorts and enums
	char cArg='A'; //assumed to be unsigned
	short sArg=1234;
	unsigned short usArg=40000;
	workday enumArg=Wednesday;

	pPtr->Simple1(cArg,sArg, usArg, enumArg);


	// passing large integers
	long lArg=12345678L;
	unsigned long ulArg=4026531840L;

	pPtr->Simple2(lArg, ulArg);

	// passing floating point data
	float fArg=1234.0f;
	double dArg=12345678.0;

	pPtr->Simple3(fArg, dArg);

	// arguments that won't work with late binding
	bool bArg=TRUE;
	BYTE byArg=12;
	hyper yArg=1234567890123456;  //(int64)
	unsigned hyper uyArg=1234567890123;

	pPtr->Simple4(bArg, byArg, yArg, uyArg );

	// playing with in and out attributes
	long lArg1=123;	// 123 will be passed to method but lArg1 will not receive anything back
	long lArg2=456; // 456 will be not be passed to method, but will be overwritten by method on return
	long lArg3=789; // 789 will be passed to method and will also be overwritten by value returned by method

	pPtr->Simple5(lArg1,&lArg2,&lArg3); //note that returned arguments must pass their addresses

//////////////////////////////////////////////////////////////////////////
////////////////     PASSING ARRAYS       ///////////////////////////
//////////////////////////////////////////////////////////////////////////
// simple arrays don't work with late binding--use safearrays instead

	//simple array
	long aArg[ARRAYSIZE];

	pPtr->Array1(aArg);

	// variable sized (one dimension only)(variable length specified with [] or [*])
	long lSize=ARRAYSIZE;
	long vArg[ARRAYSIZE][5];

	pPtr->Array2(
			lSize,		// size of second row of array
			(long **)vArg		// array
			);


	// to specify only a certian part of array needs to be xmitted/received (whole array still allocated in destination)
	long lFirst=20;
	long lLast=23;
	pPtr->Array3(
			lFirst, 	// first element to transmit
			lLast, 		// last element to transmit
			lSize,
			aArg);		// array to transmit

	long lLength=4;
	pPtr->Array4(
			lFirst,		// first element to transmit
			lLength,	// number of elements to transmit starting at lFirst
			lSize,
			aArg);		// array to transmit


//////////////////////////////////////////////////////////////////////////
////////////////     PASSING STRUCTURES AND CLASSES /////////////////////
//////////////////////////////////////////////////////////////////////////
// structures don't work with late binding
	MYSTRUCT myStruct;

	myStruct.pPointer=new long[12]; // All embedded pointers must receive a valid
									// pointer or a NULL before it can be transmitted
	myStruct.pPointer[3]=1234;
	pPtr->Structs1(myStruct,pPtr.GetInterfacePtr());

//////////////////////////////////////////////////////////////////////////
////////////////     PASSING ENCAPSULATED UNIONS /////////////////////
//////////////////////////////////////////////////////////////////////////
// encapsulated unions don't work with late binding--use variants instead

	MYEUNION myEUnion;
	long lType=1;
	myEUnion.fFloat[0]=123.0f;
	
	pPtr->EUnions1(lType,myEUnion);

//////////////////////////////////////////////////////////////////////////
////////////////     PASSING MEMORY POINTERS /////////////////////
//////////////////////////////////////////////////////////////////////////
// NOTE: Memory allocated with ::CoTaskMemAlloc() can be safely deallocated 
//	by any COM server using ::CoTaskMemDealloc(). It's also thread safe (no two 
//  threads can write to its pointer at the same time.

	// allocate a structure
	// NOTE: Cannot use LPVOID--proxy will need to know exactly how big the
	//		data item is that this pointer points to.
	MYSTRUCT *pMyStruct=(MYSTRUCT*)::CoTaskMemAlloc(
								sizeof(MYSTRUCT)		//number of bytes to allocate
							 	);

	// Fastest COM access to a pointer: 
	// the server may change the contents of pMyStruct, but promises not to dealloc 
	// or otherwise change the pointer so COM doesn't have to keep track of it
	pPtr->MemPtr1(pMyStruct);

	// Medium COM access to a pointer: 
	// the server can deallocate the memory this pointer points to, but there is only 
	// one pointer to this particular memory in this call
	pPtr->MemPtr2(&pMyStruct);

	// Slowest COM access to a pointer: 
	// there are two pointers into pMyStruct, and the server can use either 
	// to modify its contents
	MYSTRUCT *pMyStruct2=pMyStruct;
	pPtr->MemPtr3(&pMyStruct,&pMyStruct2);

	MYSTRUCT *pReturned;
	pPtr->MemPtr4(
			NULL,			// all input and/or output pointers must be 
			&pReturned);	// assigned a valid pointer or NULL!


//////////////////////////////////////////////////////////////////////////
////////////////     PASSING VISUAL BASIC DATA ///////////////////////////
//////////////////////////////////////////////////////////////////////////

// BSTR type (binary string) equivalent to Visual Basic string
	// convert asciiz to BSTR using C++ class "_bstr_t"
	_bstr_t bstrtMyString1("MyString");
	BSTR bstrMyString2=NULL;

	// make the call
	pPtr->VBVars1(bstrtMyString1,&bstrMyString2);

	// convert BSTR from unicode to asciiz using W2A() macro
	USES_CONVERSION;
	char *pStr = (char*)W2A(bstrMyString2);

	// make same conversion using %S printf format
	CString str;
	str.Format("%S",bstrMyString2);

// SAFEARRAY type equivalent to a Visual Basic array
	// create safearray and initialize with data
	SAFEARRAY *saMySafeArray=
		::SafeArrayCreateVector( 
					VT_UI1,	// type (VT_UI1 == one byte unsigned integers (bytes)
					0,		// lower index of array (can be negative)
					100);	// size
	LPBYTE lpByte=NULL;
	::SafeArrayAccessData(
			saMySafeArray,	//safearray vector from above
			(LPVOID*)&lpByte);		//pointer
	lpByte[0]=12;
	lpByte[1]=34;
	::SafeArrayUnaccessData(
			saMySafeArray);	//safearray vector from above

	// make the call
	pPtr->VBVars2(&saMySafeArray);

	// retrieve the data
	::SafeArrayAccessData(
			saMySafeArray,	//safearray vector from above
			(LPVOID*)&lpByte);		//pointer
	BYTE by=lpByte[0];
	::SafeArrayUnaccessData(
			saMySafeArray);	//safearray vector from above

	// destroy the safe array
	::SafeArrayDestroy(saMySafeArray);


// VARIANT type equivalent to an untyped Visual Basic variable
	// convert a variable to a variant using the C++ class "_variant_t"
	long lLong=14;
	bstrtMyString1=L"test"; //reusing a _bstr_t class
	_variant_t vartMyVariant1(lLong);
	_variant_t vartMyVariant2(bstrtMyString1);

	// convert a safearray to a variant using V_xxx macros (other types can be found in OLEAUTO.H)
	saMySafeArray=::SafeArrayCreateVector( VT_UI1,0,100);
	VARIANT varMyVariant3;
	VariantInit(&varMyVariant3); //initialize to no type
	V_VT(&varMyVariant3)= VT_ARRAY | VT_UI1;
	V_ARRAY(&varMyVariant3)=saMySafeArray;

	// make the call
	pPtr->VBVars3(&vartMyVariant1,&vartMyVariant2,&varMyVariant3);

	// convert a variant back to a variable using "_variant_t"
	lLong=long(vartMyVariant1);
	bstrtMyString1=_bstr_t(vartMyVariant2);

	// convert safearrays using V_xxx macros (other types can be found in OLEAUTO.H)
	if (V_VT(&varMyVariant3)==(VT_ARRAY | VT_UI1))
		saMySafeArray=V_ARRAY(&varMyVariant3);
	::SafeArrayDestroy(saMySafeArray);

// RETVAL type equivalent to the value returned by a function.
	// (the retval in the following example:  retval=func(val1,val2);)
	// (the trick is in the "retval" variable attribute in the IDL file and the wrapper
	//   that #import puts around IWzdPtr method calls)
	long val=pPtr->VBVars4();

	// same exact method call without the IWzdPtr wrapper method
	pPtr->raw_VBVars4(&val);
}
