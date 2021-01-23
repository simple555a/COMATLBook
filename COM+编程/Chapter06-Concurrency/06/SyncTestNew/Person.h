// Person.h: Definition of the CPerson class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSON_H__E24B82AC_1E61_4EEC_B8FB_ED1907DD65ED__INCLUDED_)
#define AFX_PERSON_H__E24B82AC_1E61_4EEC_B8FB_ED1907DD65ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols



/////////////////////////////////////////////////////////////////////////////
// CPerson

class CPerson : 
	public IDispatchImpl<IPerson, &IID_IPerson, &LIBID_SYNCTESTNEWLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CPerson,&CLSID_Person>
{
public:
	CPerson() {}
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
	STDMETHOD(SetName)(/*[in]*/ BSTR bsFirstName, /*[in]*/ BSTR bsLastName);

	struct PERSONINFO {
		CComBSTR bsFirstName;
		CComBSTR bsLastName;
	};

	CCPLWinSharedResource<PERSONINFO> m_Info;
};

#endif // !defined(AFX_PERSON_H__E24B82AC_1E61_4EEC_B8FB_ED1907DD65ED__INCLUDED_)
