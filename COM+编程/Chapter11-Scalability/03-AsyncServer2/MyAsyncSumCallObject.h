// MyAsyncSum.h: interface for the CMyAsyncSumCallObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYASYNCSUM_H__F63B924F_5937_47E6_BB96_397E02A9A99E__INCLUDED_)
#define AFX_MYASYNCSUM_H__F63B924F_5937_47E6_BB96_397E02A9A99E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AsyncServer2.h"

class CMyAsyncSumCallObject;

class CMyThread : public CCPLWinThread
{
public:
	CMyThread();
	HRESULT Init(CMyAsyncSumCallObject* p);
	~CMyThread();

private:
	void Proc();

private:
	CMyAsyncSumCallObject* m_pCallObject;
};

class CMyAsyncSumCallObject  :
	public AsyncIMySum2,
	public CComObjectRoot
{
public:
	CMyAsyncSumCallObject();
	HRESULT FinalConstruct();
	~CMyAsyncSumCallObject();

DECLARE_GET_CONTROLLING_UNKNOWN ()

BEGIN_COM_MAP(CMyAsyncSumCallObject)
	COM_INTERFACE_ENTRY(AsyncIMySum2)
	COM_INTERFACE_ENTRY_AUTOAGGREGATE(IID_ISynchronize, m_spUnkInner.p, CLSID_ManualResetEvent)
END_COM_MAP()

// AsyncIMySum2
public:
	STDMETHOD(Begin_GetSum)(/*[in]*/ long lVal1, /*[in]*/ long lVal2);
	STDMETHOD(Finish_GetSum)(/*[out, retval]*/ long* plSum);

	CComPtr<IUnknown> m_spUnkInner;

private:
	friend class CMyThread;
	CMyThread m_Thread;
	long m_lVal1;
	long m_lVal2;
	long m_lSum;

	typedef CCPLWinSharedResource<bool> SAFEBOOL;
	SAFEBOOL m_bCallInProgress;
};

#endif // !defined(AFX_MYASYNCSUM_H__F63B924F_5937_47E6_BB96_397E02A9A99E__INCLUDED_)
