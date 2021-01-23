// Video.h - Definition of interface IVideo

class IVideo  
{
public:
	virtual long _stdcall GetSignalValue() = 0;
};

extern "C" IVideo* _stdcall CreateVCR();


