// Person.h: Definition of the CPerson class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSON_H__A58EFC5A_AE51_4081_8977_F8487ABC133A__INCLUDED_)
#define AFX_PERSON_H__A58EFC5A_AE51_4081_8977_F8487ABC133A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPerson

class CPerson : 
	public IDispatchImpl<IPerson, &IID_IPerson, &LIBID_SYNCTESTLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CPerson,&CLSID_Person>
{
public:
	CPerson() {}
	~CPerson() {}

BEGIN_COM_MAP(CPerson)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IPerson)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CPerson) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_Person)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IPerson
public:
	STDMETHOD(GetName)(/*[out]*/ BSTR* pbsFirstName, /*[out]*/ BSTR* pbsLastName);
	STDMETHOD(LockAccess)();
	STDMETHOD(SetFirstName)(/*[in]*/ BSTR bsFirstName);
	STDMETHOD(SetLastName)(/*[in]*/ BSTR bsLastName);
	STDMETHOD(UnlockAccess)();

private:
	CComAutoCriticalSection m_CS;
	CComBSTR m_bsFirstName;
	CComBSTR m_bsLastName;
};

#endif // !defined(AFX_PERSON_H__A58EFC5A_AE51_4081_8977_F8487ABC133A__INCLUDED_)
