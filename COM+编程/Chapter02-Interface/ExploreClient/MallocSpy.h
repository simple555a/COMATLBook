class CMallocSpy : public IMallocSpy
{
public:
    // IUnknown methods
    STDMETHOD(QueryInterface) (REFIID riid, LPVOID *ppUnk);
    STDMETHOD_(ULONG, AddRef) (void);
    STDMETHOD_(ULONG, Release) (void);


    // IMallocSpy methods
    STDMETHOD_(ULONG, PreAlloc) (ULONG cbRequest);
    STDMETHOD_(void *, PostAlloc) (void *pActual);

    STDMETHOD_(void *, PreFree) (void *pRequest, BOOL fSpyed);
    STDMETHOD_(void, PostFree) (BOOL fSpyed);

    STDMETHOD_(ULONG, PreRealloc) (void *pRequest, ULONG cbRequest,
                                   void **ppNewRequest, BOOL fSpyed);
    STDMETHOD_(void *, PostRealloc) (void *pActual, BOOL fSpyed);

    STDMETHOD_(void *, PreGetSize) (void *pRequest, BOOL fSpyed);
    STDMETHOD_(ULONG, PostGetSize) (ULONG cbActual, BOOL fSpyed);

    STDMETHOD_(void *, PreDidAlloc) (void *pRequest, BOOL fSpyed);
    STDMETHOD_(BOOL, PostDidAlloc) (void *pRequest, BOOL fSpyed, BOOL fActual);

    STDMETHOD_(void, PreHeapMinimize) (void);
    STDMETHOD_(void, PostHeapMinimize) (void);

    CMallocSpy(void);
    ~CMallocSpy(void);

private:
    ULONG    m_cRef;
    ULONG    m_cbRequest;
};

class CMallocSpyHook
{
public:
	CMallocSpyHook()
	{
		m_pSpy = NULL;
		m_bRegistered = false;
	}

	~CMallocSpyHook()
	{
		Reset();
	}

	void Init()
	{
		m_pSpy = new CMallocSpy;
		m_pSpy->AddRef();
		HRESULT hr = CoRegisterMallocSpy(m_pSpy);
		if (FAILED(hr)) {
			return;
		}

		m_bRegistered = true;
	}

	void Reset()
	{
		if (m_bRegistered) {
			CoRevokeMallocSpy();
			m_bRegistered = false;
		}

		if (m_pSpy) {
			m_pSpy->Release();
			m_pSpy = 0;
		}
	}
private:
	CMallocSpy* m_pSpy;
	bool m_bRegistered;
};


