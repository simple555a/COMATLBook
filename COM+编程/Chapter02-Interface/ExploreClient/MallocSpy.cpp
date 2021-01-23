#include "StdAfx.h"
#include "MallocSpy.h"

#define HEADERSIZE 0

CMallocSpy::CMallocSpy(void)
{
    m_cRef = 0;
}

CMallocSpy::~CMallocSpy(void)
{
    // Nothing to do here
}

HRESULT CMallocSpy::QueryInterface(REFIID riid, LPVOID *ppUnk)
{
    HRESULT hr = S_OK;

    if (IsEqualIID(riid, IID_IUnknown))
    {
        *ppUnk = (IUnknown *) this;
    }
    else if (IsEqualIID(riid, IID_IMallocSpy))
    {
        *ppUnk =  (IMalloc *) this;
    }
    else
    {
        *ppUnk = NULL;
        hr =  E_NOINTERFACE;
    }
    AddRef();
    return hr;
}


ULONG CMallocSpy::AddRef(void)
{
    return ++m_cRef;
}

ULONG CMallocSpy::Release(void)
{
    ULONG cRef;

    cRef = --m_cRef;
    if (cRef == 0)
    {
        delete this;
    }
    return cRef;
}
 
ULONG CMallocSpy::PreAlloc(ULONG cbRequest)
{
    m_cbRequest = cbRequest;
    return cbRequest + HEADERSIZE;
}

void *CMallocSpy::PostAlloc(void *pActual)
{
    // Store interesting information in the first HEADERSIZE bytes
    // of the allcation
    // ...
	cout << "Alloc: " << hex << pActual << " of size: " << m_cbRequest << endl;

    // Return the allocation plus offset
    return (void *) (((BYTE *) pActual) + HEADERSIZE);
}

void *CMallocSpy::PreFree(void *pRequest, BOOL fSpyed)
{
    // Use the stored information
    // ...
	if (fSpyed) {
		cout << "Free: " << hex << pRequest << endl;
	}

    // Check for NULL
    if (pRequest == NULL)
    {
        return NULL;
    }

    // Undo the offset
    if (fSpyed)
    {
        return (void *) (((BYTE *) pRequest) - HEADERSIZE);
    }
    else
    {
        return pRequest;
    }
}

void CMallocSpy::PostFree(BOOL fSpyed)
{
    // Note the free or whatever

    return;
}

ULONG CMallocSpy::PreRealloc(void *pRequest, ULONG cbRequest,
                             void **ppNewRequest, BOOL fSpyed)
{
    // Typically we don't need to extend/distend the header
    if (fSpyed)
    {
	    m_cbRequest = cbRequest;
        *ppNewRequest = (void *) (((BYTE *) pRequest) - HEADERSIZE);
        return cbRequest + HEADERSIZE;
    }
    else
    {
        *ppNewRequest = pRequest;
        return cbRequest;
    }
}

void *CMallocSpy::PostRealloc(void *pActual, BOOL fSpyed)
{
    // Return the buffer with the header offset
    if (fSpyed)
    {
		cout << "Realloc: " << hex << pActual << " of size: " << m_cbRequest << endl;
        return (void *) (((BYTE *) pActual) + HEADERSIZE);
    }
    else
    {
        return pActual;
    }

    // If we extend/distend the header for a reallocation, then we'd
    // have to do some more work here
}

void *CMallocSpy::PreGetSize(void *pRequest, BOOL fSpyed)
{
    if (fSpyed)
    {
        return (void *) (((BYTE *) pRequest) - HEADERSIZE);
    }else
    {
        return pRequest;
    }
}

ULONG CMallocSpy::PostGetSize(ULONG cbActual, BOOL fSpyed)
{
    if (fSpyed)
    {
        return cbActual - HEADERSIZE;
    }
    else
    {
        return cbActual;
    }
}

void *CMallocSpy::PreDidAlloc(void *pRequest, BOOL fSpyed)
{
    if (fSpyed)
    {
        return (void *) (((BYTE *) pRequest) - HEADERSIZE);
    }
    else
    {
        return pRequest;
    }
}

BOOL CMallocSpy::PostDidAlloc(void *pRequest, BOOL fSpyed, BOOL fActual)
{
    return fActual;
}

void CMallocSpy::PreHeapMinimize(void)
{
    // We don't do anything here
    return;
}

void CMallocSpy::PostHeapMinimize(void)
{
    // We don't do anything here
    return;
}
