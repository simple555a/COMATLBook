// WzdColl.cpp : Implementation of CWzdCollection
#include "stdafx.h"
#include "CollSrv.h"
#include "WzdColl.h"

/////////////////////////////////////////////////////////////////////////////
// CWzdCollection
typedef CComObject<CComEnum<IEnumVARIANT,&IID_IEnumVARIANT,VARIANT,_Copy<VARIANT> > > EnumVar;

// initilize number of safe arrays
STDMETHODIMP CWzdCollection::Init(long numObjs)
{
	m_inx=0;
	m_numObjs=numObjs;
	m_var=new VARIANT[numObjs];
	for (int i=0; i<numObjs; ++i)
		VariantInit(&m_var[i]);
	return S_OK;
}

// add another safe array
STDMETHODIMP CWzdCollection::Add(SAFEARRAY **ppNewObj)
{
	if (m_inx<m_numObjs)
	{
		m_var[m_inx].vt = VT_ARRAY | VT_UI1;
		m_var[m_inx].parray = *ppNewObj;
		m_inx++;
		return S_OK;
	}
	return E_FAIL;
}

// return count
STDMETHODIMP CWzdCollection::get_Count(long *pVal)
{
	*pVal=m_numObjs;
	return S_OK;
}

// return enum
STDMETHODIMP CWzdCollection::get__NewEnum(LPUNKNOWN *pEnumObjs)
{
	EnumVar *pVar=new EnumVar;
	pVar->Init(&m_var[0],&m_var[m_numObjs],NULL,AtlFlagCopy);
	pVar->QueryInterface(IID_IUnknown,(void**)pEnumObjs);
	return S_OK;
}

// return one item
STDMETHODIMP CWzdCollection::Item(VARIANT Index, LPVARIANT pItem)
{
	pItem->vt= VT_ARRAY | VT_UI1;
	pItem->parray = m_var[Index.lVal].parray;
	return S_OK;
}

// cleanup on destroy
void CWzdCollection::FinalRelease()
{
	if (m_var)
	{
		for (int i=0; i<m_inx; ++i)
		{ 
			SafeArrayDestroyData(m_var[i].parray);
			m_var[i].vt = VT_EMPTY;
		}
		delete []m_var;
	}
}


