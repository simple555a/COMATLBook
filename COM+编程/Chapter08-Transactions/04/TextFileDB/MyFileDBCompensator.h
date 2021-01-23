// MyFileDBCompensator.h: Definition of the CMyFileDBCompensator class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFILEDBCOMPENSATOR_H__6EC52C9C_7664_49EB_97F0_8C1F703921A7__INCLUDED_)
#define AFX_MYFILEDBCOMPENSATOR_H__6EC52C9C_7664_49EB_97F0_8C1F703921A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Resource.h"       // main symbols
#include "MyFile.h"

enum DBACTIONTYPE {dbOpen = 0x10,	dbUpdate = 0x20	};

#pragma warning(disable : 4200) // do not warn on zero-sized arrays

#pragma pack(1) // Pack the following structures tightly

struct DBACTION {
	DBACTIONTYPE actionType;
};

struct DBACTIONOPEN : public DBACTION
{
	DBACTIONOPEN()
	{
		actionType = dbOpen;
	}
	WCHAR pszFileName[0];
};

struct DBACTIONUPDATE : public DBACTION
{
	DBACTIONUPDATE()
	{
		actionType = dbUpdate;
	}
	long lNewBalance;
	WCHAR pszClient[0];
};

#pragma pack() // back to default packing
#pragma warning(default : 4200) // back to default warning

/////////////////////////////////////////////////////////////////////////////
// CMyFileDBCompensator

class CMyFileDBCompensator : 
	public IMyFileDBCompensator,
	public ICrmCompensator,
	public CComObjectRoot,
	public CComCoClass<CMyFileDBCompensator,&CLSID_MyFileDBCompensator>
{
public:
	CMyFileDBCompensator();
	~CMyFileDBCompensator();


BEGIN_COM_MAP(CMyFileDBCompensator)
	COM_INTERFACE_ENTRY(IMyFileDBCompensator)
	COM_INTERFACE_ENTRY(ICrmCompensator)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyFileDBCompensator) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyFileDBCompensator)

// IMyFileDBCompensator
public:

// ICrmCompensator
public:
    STDMETHOD(SetLogControl)( 
        /* [in] */ ICrmLogControl __RPC_FAR *pLogControl);
    
    STDMETHOD(BeginPrepare)( void);
    
    STDMETHOD(PrepareRecord)( 
        /* [in] */ CrmLogRecordRead crmLogRec,
        /* [retval][out] */ BOOL __RPC_FAR *pfForget);
    
    STDMETHOD(EndPrepare)( 
        /* [retval][out] */ BOOL __RPC_FAR *pfOkToPrepare);
    
    STDMETHOD(BeginCommit)( 
        /* [in] */ BOOL fRecovery);
    
    STDMETHOD(CommitRecord)( 
        /* [in] */ CrmLogRecordRead crmLogRec,
        /* [retval][out] */ BOOL __RPC_FAR *pfForget);
    
    STDMETHOD(EndCommit)( void);
    
    STDMETHOD(BeginAbort)( 
        /* [in] */ BOOL fRecovery);
    
    STDMETHOD(AbortRecord)( 
        /* [in] */ CrmLogRecordRead crmLogRec,
        /* [retval][out] */ BOOL __RPC_FAR *pfForget);
    
    STDMETHOD(EndAbort)( void);

private:
	CComBSTR m_bsFilePath;
	MYACCOUNTDB m_AccountDB;
};

#endif // !defined(AFX_MYFILEDBCOMPENSATOR_H__6EC52C9C_7664_49EB_97F0_8C1F703921A7__INCLUDED_)
