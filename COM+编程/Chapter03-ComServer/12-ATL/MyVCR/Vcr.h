// Vcr.h: Definition of the CVcr class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VCR_H__C7AF344E_D1BB_41C9_B664_1D3E1DFA6713__INCLUDED_)
#define AFX_VCR_H__C7AF344E_D1BB_41C9_B664_1D3E1DFA6713__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "..\ComponentVCR\ComponentVCR.h"
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CVcr

class CVcr : 
	public IVideo,
	public ISVideo,
	public CComObjectRoot,
	public CComCoClass<CVcr,&CLSID_Vcr>
{
public:
	CVcr();

DECLARE_GET_CONTROLLING_UNKNOWN ()

BEGIN_COM_MAP(CVcr)
	COM_INTERFACE_ENTRY(IVideo)
	COM_INTERFACE_ENTRY(ISVideo)
	COM_INTERFACE_ENTRY_AUTOAGGREGATE(__uuidof(IComponentVideo), m_spUnkInner.p, __uuidof(ComponentVCR))
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CVcr) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_Vcr)

// IVideo

// ISVideo
public:
	STDMETHOD(GetSVideoSignalValue)(/*[out, retval]*/ long* pRetVal);
	STDMETHOD(GetSignalValue)(/*[out, retval]*/ long* pRetVal);

public:
	CComPtr<IUnknown> m_spUnkInner;
	long m_lCurValue;
	int m_nCurCount;
};

#endif // !defined(AFX_VCR_H__C7AF344E_D1BB_41C9_B664_1D3E1DFA6713__INCLUDED_)
