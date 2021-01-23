// MyPhoneEntry.h: Definition of the CMyPhoneEntry class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPHONEENTRY_H__C600B3F9_6EDD_456C_9DB8_A278AC03E68A__INCLUDED_)
#define AFX_MYPHONEENTRY_H__C600B3F9_6EDD_456C_9DB8_A278AC03E68A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyPhoneEntry

class CMyPhoneEntry : 
	public IDispatchImpl<IMyPhoneEntry, &IID_IMyPhoneEntry, &LIBID_PHONEBOOKLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyPhoneEntry,&CLSID_MyPhoneEntry>
{
public:
	CMyPhoneEntry() {}
BEGIN_COM_MAP(CMyPhoneEntry)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyPhoneEntry)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyPhoneEntry) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyPhoneEntry)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyPhoneEntry
public:
	STDMETHOD(UpdateWithResponse)(/*[in]*/ BSTR bsClientMachine);
	STDMETHOD(Response)(/*[in]*/ BSTR bsDesc);
	STDMETHOD(Update)();
	STDMETHOD(put_PhoneNumber)(/*[in]*/ BSTR newVal);
	STDMETHOD(put_LastName)(/*[in]*/ BSTR newVal);
	STDMETHOD(put_FirstName)(/*[in]*/ BSTR newVal);

private:
	CComBSTR m_bsLastName;
	CComBSTR m_bsFirstName;
	CComBSTR m_bsPhoneNumber;
};

#endif // !defined(AFX_MYPHONEENTRY_H__C600B3F9_6EDD_456C_9DB8_A278AC03E68A__INCLUDED_)
