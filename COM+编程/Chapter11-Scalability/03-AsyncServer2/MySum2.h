// MySum2.h: Definition of the CMySum2 class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSUM2_H__572F2969_E2D5_48E7_9412_09E6D63DD608__INCLUDED_)
#define AFX_MYSUM2_H__572F2969_E2D5_48E7_9412_09E6D63DD608__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMySum2

class CMySum2 : 
	public IMySum2,
	public ICallFactory,
	public CComObjectRoot,
	public CComCoClass<CMySum2,&CLSID_MySum2>
{
public:
	CMySum2() {}
BEGIN_COM_MAP(CMySum2)
	COM_INTERFACE_ENTRY(IMySum2)
	COM_INTERFACE_ENTRY(ICallFactory)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMySum2) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MySum2)

// IMySum2
public:
	STDMETHOD(GetSum)(/*[in]*/ long lVal1, /*[in]*/ long lVal2, /*[out, retval]*/ long* plSum);

// ICallFactory
public:
	STDMETHOD(CreateCall)(REFIID riid1, IUnknown* pUnk, REFIID riid2, IUnknown** ppv);
};

#endif // !defined(AFX_MYSUM2_H__572F2969_E2D5_48E7_9412_09E6D63DD608__INCLUDED_)
