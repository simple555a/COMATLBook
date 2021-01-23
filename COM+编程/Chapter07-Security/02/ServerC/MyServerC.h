// MyServerC.h: Definition of the CMyServerC class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSERVERC_H__47E9EEDD_92A2_4D83_B812_5B8AC833684F__INCLUDED_)
#define AFX_MYSERVERC_H__47E9EEDD_92A2_4D83_B812_5B8AC833684F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyServerC

class CMyServerC : 
	public IDispatchImpl<IMyServerC, &IID_IMyServerC, &LIBID_SERVERCLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyServerC,&CLSID_MyServerC>
{
public:
	CMyServerC() {}
BEGIN_COM_MAP(CMyServerC)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyServerC)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyServerC) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyServerC)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyServerC
public:
	STDMETHOD(DoIt)(/*[out, retval]*/ BSTR* pbsRetVal);
};

#endif // !defined(AFX_MYSERVERC_H__47E9EEDD_92A2_4D83_B812_5B8AC833684F__INCLUDED_)
