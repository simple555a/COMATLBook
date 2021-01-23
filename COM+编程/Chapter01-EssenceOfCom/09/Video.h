// Video.h - Definition of interface IVideo

class IGeneral
{
public:
	virtual IGeneral* _stdcall Probe(char* pszType)  = 0;
	virtual void _stdcall AddReference() = 0;
	virtual void _stdcall Delete() = 0;
};


class IVideo  : public IGeneral
{
public:
	virtual long _stdcall GetSignalValue() = 0;

};

class ISVideo : public IGeneral
{
public:
	virtual long _stdcall GetSVideoSignalValue() = 0;
};



extern "C" IGeneral* _stdcall CreateVCR();


