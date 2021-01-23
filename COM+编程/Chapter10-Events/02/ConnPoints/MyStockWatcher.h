// MyStockWatcher.h: Definition of the CMyStockWatcher class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSTOCKWATCHER_H__2436DD21_240B_4405_9122_9BBAF3677760__INCLUDED_)
#define AFX_MYSTOCKWATCHER_H__2436DD21_240B_4405_9122_9BBAF3677760__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols
#include "ConnPointsCP.h"

/////////////////////////////////////////////////////////////////////////////
// CMyStockWatcher

class CMyStockWatcher : 
	public IDispatchImpl<IMyStockWatcher, &IID_IMyStockWatcher, &LIBID_CONNPOINTSLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyStockWatcher,&CLSID_MyStockWatcher>,
	public CCPLWinThread,
	public IProvideClassInfo2Impl<&CLSID_MyStockWatcher, &DIID_DIMyStockWatcherSink, &LIBID_CONNPOINTSLib>,
	public CProxyDIMyStockWatcherSink< CMyStockWatcher >,
	public IConnectionPointContainerImpl<CMyStockWatcher>
{
public:
	CMyStockWatcher();
	HRESULT FinalConstruct();
	~CMyStockWatcher();

BEGIN_COM_MAP(CMyStockWatcher)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyStockWatcher)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyStockWatcher) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyStockWatcher)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyStockWatcher
public:
	STDMETHOD(Disable)();
	STDMETHOD(Enable)();
public :

private:
	void Proc();
public :

BEGIN_CONNECTION_POINT_MAP(CMyStockWatcher)
	CONNECTION_POINT_ENTRY(DIID_DIMyStockWatcherSink)
END_CONNECTION_POINT_MAP()

};

#endif // !defined(AFX_MYSTOCKWATCHER_H__2436DD21_240B_4405_9122_9BBAF3677760__INCLUDED_)
