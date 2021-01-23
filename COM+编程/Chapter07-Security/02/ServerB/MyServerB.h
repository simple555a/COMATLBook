// MyServerB.h: Definition of the CMyServerB class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSERVERB_H__644E87D3_B333_4454_B41F_38B19EB49FB3__INCLUDED_)
#define AFX_MYSERVERB_H__644E87D3_B333_4454_B41F_38B19EB49FB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyServerB

class CMyServerB : 
	public IDispatchImpl<IMyServerB, &IID_IMyServerB, &LIBID_SERVERBLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyServerB,&CLSID_MyServerB>
{
public:
	CMyServerB() {}
BEGIN_COM_MAP(CMyServerB)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyServerB)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyServerB) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyServerB)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyServerB
public:
	STDMETHOD(DoIt)(/*[in]*/ long lDelegate, /*[out, retval]*/ BSTR* pbsRetVal);
};

#endif // !defined(AFX_MYSERVERB_H__644E87D3_B333_4454_B41F_38B19EB49FB3__INCLUDED_)
