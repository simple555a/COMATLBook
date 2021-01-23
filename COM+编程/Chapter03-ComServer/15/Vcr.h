// File vcr.h

#include "Video.h"

class CVcr : 
	public IVideo, 
	public ISVideo, 
	public ISupportErrorInfo
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

	// ISupportErrorInfo interface
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID iid);

	// Helpers
	IUnknown* GetUnknown()
	{
		return static_cast<IVideo*>(this);
	}

	void Error(REFIID iid, LPOLESTR pszDesc);

private:
	long m_lCurValue;
	int m_nCurCount;
	long m_lRefCount;
};


