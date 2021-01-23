// MyTest.h: Definition of the CMyTest class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTEST_H__7586A839_D81F_46AF_AB73_986BD27EDC86__INCLUDED_)
#define AFX_MYTEST_H__7586A839_D81F_46AF_AB73_986BD27EDC86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyTest

class CMyTest : 
	public IDispatchImpl<IMyTest, &IID_IMyTest, &LIBID_ACTIVITYTESTLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyTest,&CLSID_MyTest>
{
public:
	CMyTest() {}
BEGIN_COM_MAP(CMyTest)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyTest)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyTest) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyTest)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyTest
public:
	STDMETHOD(DoIt)();
};

#endif // !defined(AFX_MYTEST_H__7586A839_D81F_46AF_AB73_986BD27EDC86__INCLUDED_)
