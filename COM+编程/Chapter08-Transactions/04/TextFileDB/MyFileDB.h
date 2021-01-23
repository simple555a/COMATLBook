// MyFileDB.h: Definition of the CMyFileDB class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFILEDB_H__64981ACF_BF90_4DA4_8C9E_FFEED9A21C49__INCLUDED_)
#define AFX_MYFILEDB_H__64981ACF_BF90_4DA4_8C9E_FFEED9A21C49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols
#include "MyFile.h"

/////////////////////////////////////////////////////////////////////////////
// CMyFileDB

class CMyFileDB : 
	public IDispatchImpl<IMyFileDB, &IID_IMyFileDB, &LIBID_TEXTFILEDBLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyFileDB,&CLSID_MyFileDB>
{
public:
	CMyFileDB();
	~CMyFileDB();

BEGIN_COM_MAP(CMyFileDB)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyFileDB)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyFileDB) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyFileDB)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyFileDB
public:
	STDMETHOD(UpdateBalance)(/*[in]*/ BSTR bsClient, /*[in]*/ long lNewBalance);
	STDMETHOD(GetBalance)(/*[in]*/ BSTR bsClient, /*[out, retval]*/ long* plBalance);
	STDMETHOD(Open)(/*[in]*/ BSTR bsFilePath);

private:
	HRESULT InitCRM();

private:
	CComPtr<ICrmLogControl> m_spCrmLC;
	MYACCOUNTDB m_AccountDB;
};

#endif // !defined(AFX_MYFILEDB_H__64981ACF_BF90_4DA4_8C9E_FFEED9A21C49__INCLUDED_)
