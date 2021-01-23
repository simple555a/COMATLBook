// File vcr.h

#include "Video.h"

class CVcr : public IVideo, public ISVideo
{
public:
	CVcr(void);
	~CVcr();

	// IUnknown interface
	STDMETHOD(QueryInterface)(REFIID iid, void** pp);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	// IVideo interface
	STDMETHOD(GetSignalValue)(long* plVal);

	// ISVideo interface
	STDMETHOD(GetSVideoSignalValue)(long* plVal);

private:
	long m_lCurValue;
	int m_nCurCount;
	long m_lRefCount;
};


