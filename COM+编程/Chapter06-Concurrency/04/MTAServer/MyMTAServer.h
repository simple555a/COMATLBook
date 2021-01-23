// MyMTAServer.h: Definition of the CMyMTAServer class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMTASERVER_H__CFA27373_F760_489A_A932_E47E82248B33__INCLUDED_)
#define AFX_MYMTASERVER_H__CFA27373_F760_489A_A932_E47E82248B33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyMTAServer

class CMyMTAServer : 
	public IMyMTAServer,
	public CComObjectRoot,
	public CComCoClass<CMyMTAServer,&CLSID_MyMTAServer>
{
public:
	CMyMTAServer() {}
BEGIN_COM_MAP(CMyMTAServer)
	COM_INTERFACE_ENTRY(IMyMTAServer)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyMTAServer) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyMTAServer)

// IMyMTAServer
public:
	STDMETHOD(DoIt)();
};

#endif // !defined(AFX_MYMTASERVER_H__CFA27373_F760_489A_A932_E47E82248B33__INCLUDED_)
