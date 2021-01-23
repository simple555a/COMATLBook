// MyServer.h: Definition of the CMyServer class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSERVER_H__BAA91416_C911_4878_8F12_936477441A2B__INCLUDED_)
#define AFX_MYSERVER_H__BAA91416_C911_4878_8F12_936477441A2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyServer

class CMyServer : 
	public IDispatchImpl<IMyServer, &IID_IMyServer, &LIBID_TESTOBJECTCONSTRUCTLib>, 
	public ISupportErrorInfo,
	public IObjectConstruct,
	public CComObjectRoot,
	public CComCoClass<CMyServer,&CLSID_MyServer>
{
public:
	CMyServer() {}
BEGIN_COM_MAP(CMyServer)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyServer)
	COM_INTERFACE_ENTRY(IObjectConstruct)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyServer) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyServer)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:
// IObjectConstruct
	STDMETHOD(Construct)(IDispatch* pDisp);

// IMyServer
public:
	STDMETHOD(DoIt)(/*[out, retval]*/ BSTR* bsRetVal);

private:
	CComBSTR m_bsInitString;
};

#endif // !defined(AFX_MYSERVER_H__BAA91416_C911_4878_8F12_936477441A2B__INCLUDED_)
