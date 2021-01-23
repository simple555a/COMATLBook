// File vcr.h

#include "Resource.h"
#include "Video.h"

class CVcr :
	public IVideo,
	public ISVideo,
	public CComObjectRoot,
	public CComCoClass<CVcr, &CLSID_VCR>
{
public:
	CVcr();
	~CVcr();

DECLARE_REGISTRY_RESOURCEID(IDR_VCR)

BEGIN_COM_MAP(CVcr)
	COM_INTERFACE_ENTRY(IVideo)
	COM_INTERFACE_ENTRY(ISVideo)
END_COM_MAP()

	// IVideo interface
	STDMETHOD(GetSignalValue)(long* plVal);

	// ISVideo interface
	STDMETHOD(GetSVideoSignalValue)(long* plVal);

private:
	long m_lCurValue;
	int m_nCurCount;
};


