// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "server.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// IWzd properties

long IWzd::GetProperty1()
{
	long result;
	GetProperty(0x1, VT_I4, (void*)&result);
	return result;
}

void IWzd::SetProperty1(long propVal)
{
	SetProperty(0x1, VT_I4, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// IWzd operations

void IWzd::Method1(long lArg)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 lArg);
}
