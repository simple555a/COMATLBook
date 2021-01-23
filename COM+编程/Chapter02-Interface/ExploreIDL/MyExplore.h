// MyExplore.h: Definition of the CMyExplore class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYEXPLORE_H__2B930581_0C8D_11D3_9B66_0080C8E11F14__INCLUDED_)
#define AFX_MYEXPLORE_H__2B930581_0C8D_11D3_9B66_0080C8E11F14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyExplore

class CMyExplore : 
	public IMyExplore,
	public CComObjectRoot,
	public CComCoClass<CMyExplore,&CLSID_MyExplore>
{
public:
	CMyExplore() {}
BEGIN_COM_MAP(CMyExplore)
	COM_INTERFACE_ENTRY(IMyExplore)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyExplore) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyExplore)

// IMyExplore
public:
	STDMETHOD(GetMyLeaders)(/*[out]*/ MYLEADERS* pDataArray);
	STDMETHOD(MyCircularList)(/*[in, ptr]*/ MYCIRCULARLIST* pList);
	STDMETHOD(MyLinkList)(/*[in]*/ MYLONGLIST* pList);
	STDMETHOD(GetGrades6)(/*[out]*/ long* plCount, /*[out, size_is(,*plCount)]*/ long** palVal);
	STDMETHOD(GetGrades5)(/*[in]*/ long lSize, /*[in, out]*/ long* plActual, /*[in, out]*/ long* plFirst, /*[in, out, size_is(lSize), length_is(*plActual), first_is(*plFirst)]*/ long alGrades[]);
	STDMETHOD(GetGrades4)(/*[in]*/ long lSize, /*[out]*/ long* plActual, /*[out]*/ long* plFirst, /*[out, size_is(lSize), length_is(*plActual), first_is(*plFirst)]*/ long alGrades[]);
	STDMETHOD(GetGrades3)(/*[in]*/ long lSize, /*[out]*/ long* plActual, /*[out, size_is(lSize), length_is(*plActual)]*/ long alGrades[]);
	STDMETHOD(GetGrades2)(/*[in]*/ long lSize, /*[out]*/ long* plActual, /*[out, size_is(lSize)]*/ long alGrades[]);
	STDMETHOD(GetGrades1)(/*[in]*/ long lSize, /*[out, size_is(lSize)]*/ long alGrades[]);
	STDMETHOD(ConformantArrayOut)(/*[in]*/ long lCount, /*[out, size_is(lCount)]*/ long alVal[]);
	STDMETHOD(ConformantArrayIn2)(/*[in]*/ long lCount, /*[in, max_is(nCount)]*/ long* aVal);
	STDMETHOD(ConformantArrayIn)(/*[in]*/ long lCount, /*[in, size_is(nCount)]*/ long* aVal);
	STDMETHOD(EncapsulatedUnionIn)(/*[in]*/ MYENUMBER num);
	STDMETHOD(SimpleUnionIn)(/*[in]*/ MYVALUETYPE i, /*[in, switch_is(i)]*/ MYNUMBER num);
	STDMETHOD(SimpleArrayDemoOut)(/*[out, retval]*/ long alVal[100]);
	STDMETHOD(SimpleArrayDemoIn)(/*[in]*/ long alVal[100]);
	STDMETHOD(StructDemo)(/*[out, retval]*/ MYPOINT* pVal);
	STDMETHOD(ArrayDemo)(/*[in]*/ long nCount, /*[in, size_is(nCount)]*/ long* pVal);
	STDMETHOD(EmbeddedDemo)(/*[in]*/ MYITEM* val);
	STDMETHOD(SendCircularBuf)(/*[in]*/ CIRCULARBUF* pBuf);
	STDMETHOD(AliasDemoInParam)(/*[in]*/ long* pVal1, /*[in]*/ long* pVal2);
	STDMETHOD(AliasDemo)(/*[out]*/ long* val1, /*[out]*/ long* val2, /*[out]*/ long* val3);
	STDMETHOD(GetEnum)(/*[out]*/  MYCOLOR* pVal);
	STDMETHOD(GetString)(/*[out]*/ BSTR* pVal);
	STDMETHOD(RevisedStringParam)(/*[in]*/ BSTR bstrVal);
	STDMETHOD(StringParam)(/*[in, string]*/ OLECHAR* pwszName);
	STDMETHOD(DirectionDemo)(/*[in]*/ long val1, /*[out]*/ long* pVal2, /*[in, out]*/ long* pVal3,  /*[out]*/ long* pVal4, /*[in]*/ long val5);
	STDMETHOD(GetRandomValue)(/*[out]*/ long* pVal);
};

#endif // !defined(AFX_MYEXPLORE_H__2B930581_0C8D_11D3_9B66_0080C8E11F14__INCLUDED_)
