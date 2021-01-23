// Video.h - Definition of interface IVideo

// Forward declaration of CVcr class
class CVcr;

class IVideo  
{
public:
	IVideo();
	~IVideo();
	long GetSignalValue();

private:
	CVcr* m_pActualVideo;
};

