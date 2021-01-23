// MyTestB.h: Definition of the CMyTestB class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTESTB_H__75ED54A8_93EE_4229_BCC9_18A62FA14188__INCLUDED_)
#define AFX_MYTESTB_H__75ED54A8_93EE_4229_BCC9_18A62FA14188__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyTestB

class CMyTestB : 
	public IMyTestB,
	public CComObjectRoot,
	public CComCoClass<CMyTestB,&CLSID_MyTestB>
{
public:
	CMyTestB() {}
BEGIN_COM_MAP(CMyTestB)
	COM_INTERFACE_ENTRY(IMyTestB)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyTestB) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyTestB)

// IMyTestB
public:
	STDMETHOD(DoIt)();
};

#endif // !defined(AFX_MYTESTB_H__75ED54A8_93EE_4229_BCC9_18A62FA14188__INCLUDED_)
