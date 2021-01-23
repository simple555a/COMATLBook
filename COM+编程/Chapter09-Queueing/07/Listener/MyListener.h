// MyListener.h: Definition of the CMyListener class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYLISTENER_H__3EA5DC6B_9609_4873_8F09_D966AABE53D9__INCLUDED_)
#define AFX_MYLISTENER_H__3EA5DC6B_9609_4873_8F09_D966AABE53D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyListener

class CMyListener : 
	public IDispatchImpl<IMyListener, &IID_IMyListener, &LIBID_LISTENERLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyListener,&CLSID_MyListener>
{
public:
	CMyListener() {}
BEGIN_COM_MAP(CMyListener)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyListener)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyListener) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyListener)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyListener
public:
	STDMETHOD(Send)();
	STDMETHOD(Listen)();

private:
	HRESULT ListenEx();

};

#endif // !defined(AFX_MYLISTENER_H__3EA5DC6B_9609_4873_8F09_D966AABE53D9__INCLUDED_)
