// MyTestC.h: Definition of the CMyTestC class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTESTC_H__5755F64F_DF1B_4A54_ADFE_08991BDB0B41__INCLUDED_)
#define AFX_MYTESTC_H__5755F64F_DF1B_4A54_ADFE_08991BDB0B41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyTestC

class CMyTestC : 
	public IDispatchImpl<IMyTestC, &IID_IMyTestC, &LIBID_TESTCLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyTestC,&CLSID_MyTestC>
{
public:
	CMyTestC() {}
BEGIN_COM_MAP(CMyTestC)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyTestC)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyTestC) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyTestC)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyTestC
public:
	STDMETHOD(DoIt)(/*[out, retval]*/ BSTR* pbVal);
};

#endif // !defined(AFX_MYTESTC_H__5755F64F_DF1B_4A54_ADFE_08991BDB0B41__INCLUDED_)
