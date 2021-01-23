// MyServerX.h: Definition of the CMyServerX class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSERVERX_H__1CE930F3_B4CE_45AF_98E2_5DDD9612B0B2__INCLUDED_)
#define AFX_MYSERVERX_H__1CE930F3_B4CE_45AF_98E2_5DDD9612B0B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyServerX

class CMyServerX : 
	public IDispatchImpl<IMyServerX, &IID_IMyServerX, &LIBID_SERVERXLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyServerX,&CLSID_MyServerX>
{
public:
	CMyServerX() {}
BEGIN_COM_MAP(CMyServerX)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyServerX)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyServerX) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyServerX)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyServerX
public:
	STDMETHOD(Advise)(/*[in]*/ ICallMe* pCallMe);
};

#endif // !defined(AFX_MYSERVERX_H__1CE930F3_B4CE_45AF_98E2_5DDD9612B0B2__INCLUDED_)
