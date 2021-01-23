#ifndef _CONNECTIONPOINTCP_H_
#define _CONNECTIONPOINTCP_H_

template <class T>
class CProxyIStockPriceUpdate : public IConnectionPointImpl<T, &IID_IStockPriceUpdate, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:
	HRESULT Fire_NewQuote(BSTR bsSymbol, DOUBLE dPrice)
	{
		HRESULT ret;
		T* pT = static_cast<T*>(this);
		int nConnectionIndex;
		int nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			pT->Lock();
			CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
			pT->Unlock();
			IStockPriceUpdate* pIStockPriceUpdate = reinterpret_cast<IStockPriceUpdate*>(sp.p);
			if (pIStockPriceUpdate != NULL)
				ret = pIStockPriceUpdate->NewQuote(bsSymbol, dPrice);
		}	return ret;
	
	}
};
#endif