// AccountMgr.h: Definition of the CAccountMgr class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACCOUNTMGR_H__A08A7EBA_2FA8_4A6C_A900_3B604AD1623C__INCLUDED_)
#define AFX_ACCOUNTMGR_H__A08A7EBA_2FA8_4A6C_A900_3B604AD1623C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "Resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAccountMgr

class CAccountMgr : 
	public IDispatchImpl<IAccountMgr, &IID_IAccountMgr, &LIBID_ACCOUNTMGMTLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CAccountMgr,&CLSID_AccountMgr>
{
public:
	CAccountMgr();
	~CAccountMgr();

BEGIN_COM_MAP(CAccountMgr)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IAccountMgr)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CAccountMgr) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_AccountMgr)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IAccountMgr
public:
	STDMETHOD(Debit)(/*[in]*/ BSTR bsClient, /*[in]*/ long lAmount);

private:
	ADOConnectionPtr OpenAccountsDB();
	long GetBalance(ADOConnectionPtr spConn, BSTR bsClient);
	void UpdateBalance(ADOConnectionPtr spConn, BSTR bsClient, long lBalance);
};

#endif // !defined(AFX_ACCOUNTMGR_H__A08A7EBA_2FA8_4A6C_A900_3B604AD1623C__INCLUDED_)
