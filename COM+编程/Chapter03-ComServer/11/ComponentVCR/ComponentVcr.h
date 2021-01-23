// File vcr.h

#include "ComponentVideo.h"

class CComponentVcr : public IComponentVideo
{
public:
	CComponentVcr(void);
	~CComponentVcr();

	// IUnknown interface
	STDMETHOD(QueryInterface)(REFIID iid, void** pp);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	// IComponentVideo interface
	STDMETHOD(GetCVideoSignalValue)(long* plVal);

private:
	long m_lCurValue;
	int m_nCurCount;
	long m_lRefCount;
};


