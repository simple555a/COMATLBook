// MySum.h: Definition of the CMySum class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSUM_H__9315CD81_6FCA_4A28_94EE_93DDDEE5E253__INCLUDED_)
#define AFX_MYSUM_H__9315CD81_6FCA_4A28_94EE_93DDDEE5E253__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMySum

class CMySum : 
	public IMySum,
	public CComObjectRoot,
	public CComCoClass<CMySum,&CLSID_MySum>
{
public:
	CMySum() {}
BEGIN_COM_MAP(CMySum)
	COM_INTERFACE_ENTRY(IMySum)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMySum) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MySum)

// IMySum
public:
	STDMETHOD(GetSum)(/*[in]*/ long lVal1, /*[in]*/ long lVal2, /*[out, retval]*/ long* plSum);
};

#endif // !defined(AFX_MYSUM_H__9315CD81_6FCA_4A28_94EE_93DDDEE5E253__INCLUDED_)
