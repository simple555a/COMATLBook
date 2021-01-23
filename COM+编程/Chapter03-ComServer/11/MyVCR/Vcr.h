// File vcr.h

#include "Video.h"
#include "../ComponentVcr/ComponentVideo.h"

class CVcr : public IVideo, public ISVideo, IComponentVideo
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

	// IComponentVideo interface
	STDMETHOD(GetCVideoSignalValue)(long* plVal);

private:
	long m_lCurValue;
	int m_nCurCount;
	long m_lRefCount;
	IComponentVideo* m_pComponentVideo;
};


