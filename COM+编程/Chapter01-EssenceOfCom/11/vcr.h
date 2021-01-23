// File vcr.h

#include "Video.h"

class CVcr : public IVideo, public ISVideo
{
public:
	CVcr(void);
	~CVcr();

	// IGeneral interface
	VRESULT _stdcall Probe(char* pszType, IGeneral** ppRetVal);
	void _stdcall AddReference();
	void _stdcall Delete();

	// IVideo interface
	VRESULT _stdcall GetSignalValue(long* pRetVal);

	// ISVideo interface
	VRESULT _stdcall GetSVideoSignalValue(long* pRetVal);

private:
	long m_lCurValue;
	int m_nCurCount;
	long m_lRefCount;
};


