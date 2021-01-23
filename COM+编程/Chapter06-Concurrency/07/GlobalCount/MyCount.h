// MyCount.h: Definition of the CMyCount class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCOUNT_H__805A275E_6453_47F6_BA10_FACDCE87E97B__INCLUDED_)
#define AFX_MYCOUNT_H__805A275E_6453_47F6_BA10_FACDCE87E97B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyCount

class CMyCount : 
	public IDispatchImpl<IMyCount, &IID_IMyCount, &LIBID_GLOBALCOUNTLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyCount,&CLSID_MyCount>
{
public:
	CMyCount() {}
BEGIN_COM_MAP(CMyCount)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyCount)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyCount) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyCount)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyCount
public:
	STDMETHOD(IncrementCount)(/*[in]*/ long nValue);
	STDMETHOD(GetCount)(/*[out, retval]*/ long* plCount);
};

#endif // !defined(AFX_MYCOUNT_H__805A275E_6453_47F6_BA10_FACDCE87E97B__INCLUDED_)
