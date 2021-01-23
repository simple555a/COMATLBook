// File vcr.h

#include "Video.h"

class CVcr : public IVideo, public ISVideo
{
public:
	CVcr(void);
	HRESULT Init();
	~CVcr();

	// IUnknown interface
	STDMETHOD(QueryInterface)(REFIID iid, void** pp);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	// IVideo interface
	STDMETHOD(GetSignalValue)(long* plVal);

	// ISVideo interface
	STDMETHOD(GetSVideoSignalValue)(long* plVal);

	// Helper method
	IUnknown* GetRawUnknown()
	{
		return static_cast<IVideo*>(this);
	}


private:
	long m_lCurValue;
	int m_nCurCount;
	long m_lRefCount;
	IUnknown* m_pUnkInner;
};


