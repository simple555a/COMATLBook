// MyTNAServer.h: Definition of the CMyTNAServer class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTNASERVER_H__5ACFD94A_7933_4A79_A8DA_D99F0F78D39E__INCLUDED_)
#define AFX_MYTNASERVER_H__5ACFD94A_7933_4A79_A8DA_D99F0F78D39E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyTNAServer

class CMyTNAServer : 
	public IMyTNAServer,
	public CComObjectRoot,
	public CComCoClass<CMyTNAServer,&CLSID_MyTNAServer>
{
public:
	CMyTNAServer() {}
BEGIN_COM_MAP(CMyTNAServer)
	COM_INTERFACE_ENTRY(IMyTNAServer)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyTNAServer) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyTNAServer)

// IMyTNAServer
public:
	STDMETHOD(DoIt)();
};

#endif // !defined(AFX_MYTNASERVER_H__5ACFD94A_7933_4A79_A8DA_D99F0F78D39E__INCLUDED_)
