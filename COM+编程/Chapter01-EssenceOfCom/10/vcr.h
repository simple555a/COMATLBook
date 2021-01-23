// File vcr.h

#include "Video.h"

class CVcr : public IVideo, public ISVideo
{
public:
	CVcr(void);
	~CVcr();

	// IGeneral interface
	IGeneral* _stdcall Probe(char* pszType);
	void _stdcall AddReference();
	void _stdcall Delete();

	// IVideo interface
	long _stdcall GetSignalValue();

	// ISVideo interface
	long _stdcall GetSVideoSignalValue();

private:
	long m_lCurValue;
	int m_nCurCount;
	long m_lRefCount;
};


