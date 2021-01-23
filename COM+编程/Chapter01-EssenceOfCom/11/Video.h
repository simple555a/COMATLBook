// Video.h - Definition of interface IVideo

// Errors
typedef int VRESULT;

#define V_OK              0
#define V_OUTOFMEMORY     1
#define V_NOINTERFACE     2
#define V_INTERNALERROR   3

#define V_SUCCEEDED(P1)  ((P1) == V_OK)
#define V_FAILED(P1)     ((P1) != V_OK)

class IGeneral
{
public:
	virtual VRESULT _stdcall Probe(char* pszType, IGeneral** ppRetVal)  = 0;
	virtual void _stdcall AddReference() = 0;
	virtual void _stdcall Delete() = 0;
};


class IVideo  : public IGeneral
{
public:
	virtual VRESULT _stdcall GetSignalValue(long* pRetVal) = 0;

};

class ISVideo : public IGeneral
{
public:
	virtual VRESULT _stdcall GetSVideoSignalValue(long* pRetVal) = 0;
};



extern "C" VRESULT _stdcall CreateVCR(char* pszType, IGeneral** ppRetVal);


