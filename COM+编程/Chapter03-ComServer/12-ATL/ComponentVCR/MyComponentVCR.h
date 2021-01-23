// MyComponentVCR.h: Definition of the CComponentVCR class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCOMPONENTVCR_H__2A7F52EB_301B_4770_94F3_23606B7A442A__INCLUDED_)
#define AFX_MYCOMPONENTVCR_H__2A7F52EB_301B_4770_94F3_23606B7A442A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CComponentVCR

class CComponentVCR : 
	public IComponentVideo,
	public CComObjectRoot,
	public CComCoClass<CComponentVCR,&CLSID_ComponentVCR>
{
public:
	CComponentVCR();

BEGIN_COM_MAP(CComponentVCR)
	COM_INTERFACE_ENTRY(IComponentVideo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CComponentVCR) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_ComponentVCR)

// IComponentVideo
public:
	STDMETHOD(GetCVideoSignalValue)(/*[out, retval]*/ long* val);

private:
	long m_lCurValue;
	int m_nCurCount;

};

#endif // !defined(AFX_MYCOMPONENTVCR_H__2A7F52EB_301B_4770_94F3_23606B7A442A__INCLUDED_)
