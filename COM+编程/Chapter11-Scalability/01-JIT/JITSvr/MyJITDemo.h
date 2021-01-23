// MyJITDemo.h: Definition of the CMyJITDemo class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYJITDEMO_H__47130FA5_2365_4A30_A55D_BCADB8C9FFFE__INCLUDED_)
#define AFX_MYJITDEMO_H__47130FA5_2365_4A30_A55D_BCADB8C9FFFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyJITDemo

class CMyJITDemo : 
	public IDispatchImpl<IMyJITDemo, &IID_IMyJITDemo, &LIBID_JITSVRLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public IObjectControl,
	public CComCoClass<CMyJITDemo,&CLSID_MyJITDemo>
{
public:
	CMyJITDemo();
	~CMyJITDemo();

BEGIN_COM_MAP(CMyJITDemo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyJITDemo)
	COM_INTERFACE_ENTRY(IObjectControl)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
    // DECLARE_NOT_AGGREGATABLE(CMyJITDemo) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyJITDemo)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IObjectControl
	STDMETHOD(Activate)();
	STDMETHOD_(VOID, Deactivate)();
	STDMETHOD_(BOOL, CanBePooled)();
  	
// IMyJITDemo
public:
	STDMETHOD(SetEmployee)(/*[in]*/ BSTR bsEmployeeName);
	STDMETHOD(GetSalary)(/*[out, retval]*/ long* pVal);
};

#endif // !defined(AFX_MYJITDEMO_H__47130FA5_2365_4A30_A55D_BCADB8C9FFFE__INCLUDED_)
