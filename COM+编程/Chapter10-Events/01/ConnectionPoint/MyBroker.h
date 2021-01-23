// MyBroker.h: Definition of the CMyBroker class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYBROKER_H__2293C66A_AEE7_4C97_8939_9A1ED956E2EF__INCLUDED_)
#define AFX_MYBROKER_H__2293C66A_AEE7_4C97_8939_9A1ED956E2EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols
#include "ConnectionPointCP.h"

/////////////////////////////////////////////////////////////////////////////
// CMyBroker

class CMyBroker : 
	public IDispatchImpl<IMyBroker, &IID_IMyBroker, &LIBID_CONNECTIONPOINTLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CMyBroker,&CLSID_MyBroker>,
	public CProxyIStockPriceUpdate< CMyBroker >,
	public IConnectionPointContainerImpl<CMyBroker>,
	public CCPLWinThread
{
public:
	CMyBroker();
	HRESULT FinalConstruct();
	~CMyBroker();

BEGIN_COM_MAP(CMyBroker)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IMyBroker)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CMyBroker) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_MyBroker)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IMyBroker
public:
	STDMETHOD(Disable)();
	STDMETHOD(Enable)();
public :

BEGIN_CONNECTION_POINT_MAP(CMyBroker)
	CONNECTION_POINT_ENTRY(IID_IStockPriceUpdate)
END_CONNECTION_POINT_MAP()


private:
	void Proc();
};

#endif // !defined(AFX_MYBROKER_H__2293C66A_AEE7_4C97_8939_9A1ED956E2EF__INCLUDED_)
