// MyTestA.h: Definition of the CMyTestA class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTESTA_H__0B43E2CB_1E57_4B06_A9FB_6BE85AAEDD07__INCLUDED_)
#define AFX_MYTESTA_H__0B43E2CB_1E57_4B06_A9FB_6BE85AAEDD07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyTestA

class CMyTestA : 
	public IMyTestA,
	public CComObjectRoot,
	public CComCoClass<CMyTestA,&CLSID_MyTestA>
{
public:
	CMyTestA() {}
BEGIN_COM_MAP(CMyTestA)
	COM_INTERFACE_ENTRY(IMyTestA)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyTestA) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyTestA)

// IMyTestA
public:
	STDMETHOD(DoIt)();
};

#endif // !defined(AFX_MYTESTA_H__0B43E2CB_1E57_4B06_A9FB_6BE85AAEDD07__INCLUDED_)
