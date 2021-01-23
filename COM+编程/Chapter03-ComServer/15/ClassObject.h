// File ClassObject.h

class CVcrClassObject : public IClassFactory
{
public:
	CVcrClassObject();
	~CVcrClassObject();

	// IUnknown interface
	STDMETHOD(QueryInterface)(REFIID iid, void** pp);
	STDMETHOD_(ULONG, AddRef)();
	STDMETHOD_(ULONG, Release)();

	// IClassFactory interface
	STDMETHOD(CreateInstance)(IUnknown* pUnkOuter, REFIID riid, void** ppV);
	STDMETHOD(LockServer)(BOOL fLock);

	// Helper
	IUnknown* GetUnknown()
	{
		return static_cast<IClassFactory*>(this);
	}

private:
	long m_lRefCount;
};


