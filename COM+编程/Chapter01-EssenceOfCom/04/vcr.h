// File vcr.h

#include "Video.h"

class CVcr : public IVideo
{
public:
	CVcr(void);

	long _stdcall GetSignalValue();

private:
	long m_lCurValue;
	int m_nCurCount;
};

