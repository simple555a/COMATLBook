// File ClassObject.h

class CComponentVcrClassObject : public IClassFactory
{
public:
	CComponentVcrClassObject();
	~CComponentVcrClassObject();

	// IUnknown interface
	STDMETHOD(QueryInterface)(REFIID iid, void** pp);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	// IClassFactory interface
	STDMETHOD(CreateInstance)(IUnknown* pUnkOuter, REFIID riid, void** ppV);
	STDMETHOD(LockServer)(BOOL fLock);

private:
	long m_lRefCount;
};


