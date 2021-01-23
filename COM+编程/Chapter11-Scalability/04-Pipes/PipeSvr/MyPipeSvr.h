// MyPipeSvr.h: Definition of the CMyPipeSvr class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYPIPESVR_H__67BED036_0024_40DD_8A3E_517004E4B88D__INCLUDED_)
#define AFX_MYPIPESVR_H__67BED036_0024_40DD_8A3E_517004E4B88D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyPipeSvr

class CMyPipeSvr : 
	public IMyPipeSvr,
	public IPipeLong,
	public CComObjectRoot,
	public CComCoClass<CMyPipeSvr,&CLSID_MyPipeSvr>
{
public:
	CMyPipeSvr() {}
BEGIN_COM_MAP(CMyPipeSvr)
	COM_INTERFACE_ENTRY(IMyPipeSvr)
	COM_INTERFACE_ENTRY(IPipeLong)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyPipeSvr) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyPipeSvr)

// IPipeLong
    STDMETHOD(Pull)( 
        /* [length_is][size_is][out] */ LONG *buf,
        /* [in] */ ULONG cRequest,
        /* [out] */ ULONG *pcReturned);
    
    STDMETHOD(Push)( 
        /* [size_is][in] */ LONG *buf,
        /* [in] */ ULONG cSent);

// IMyPipeSvr
public:
};

#endif // !defined(AFX_MYPIPESVR_H__67BED036_0024_40DD_8A3E_517004E4B88D__INCLUDED_)
