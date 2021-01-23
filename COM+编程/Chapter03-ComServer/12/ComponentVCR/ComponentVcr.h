// File vcr.h

#include "ComponentVideo.h"
#include <stddef.h>

class CComponentVcr : public IComponentVideo
{
public:
	CComponentVcr(void);
	HRESULT Init(IUnknown* pUnkOuter);
	~CComponentVcr();

	// IUnknown interface (delegating IUnknown)
	STDMETHOD(QueryInterface)(REFIID iid, void** ppv)
	{
		return m_pUnkActual->QueryInterface(iid, ppv);
	}

	STDMETHOD_(ULONG, AddRef)()
	{
		return m_pUnkActual->AddRef();
	}

	STDMETHOD_(ULONG, Release)()
	{
		return m_pUnkActual->Release();
	}

	// IComponentVideo interface
	STDMETHOD(GetCVideoSignalValue)(long* plVal);

	// Non-delegating IUnknown calls
	STDMETHOD(InternalQueryInterface)(REFIID iid, void** ppv);
	STDMETHOD_(ULONG, InternalAddRef)();
	STDMETHOD_(ULONG, InternalRelease)();

	// Construct vtbl for non-delegating IUnknown
    class CNDUnknown : public IUnknown
	{
	public:
		CComponentVcr* Object()
		{
			return reinterpret_cast<CComponentVcr*>(
				reinterpret_cast<BYTE*>(this) -
					offsetof(CComponentVcr, m_NDUnknown));
		}
	
		STDMETHOD(QueryInterface)(REFIID iid, void** ppv)
		{
			return Object()->InternalQueryInterface(iid, ppv);
		}
		STDMETHOD_(ULONG, AddRef)()
		{
			return Object()->InternalAddRef();
		}
		STDMETHOD_(ULONG, Release)()
		{
			return Object()->InternalRelease();
		}
	};
	CNDUnknown m_NDUnknown;
		
private:
	long m_lCurValue;
	int m_nCurCount;
	long m_lRefCount;
	IUnknown* m_pUnkActual; // actual unknown to call
};


