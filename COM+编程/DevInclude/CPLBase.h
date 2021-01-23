//****************************************************************************
//
// Com+ Utility Library - Header file
//
// @doc ComPlus
//
// Copyright (C) Pradeep Tapadiya 1999.
// All rights reserved.
//
// $Revision$
// $Log$
//
//****************************************************************************

#ifndef CPLBASE_INCLUDED
#define CPLBASE_INCLUDED

#pragma once

#include <CPLDef.h>
#include <comdef.h>
#include <crtdbg.h> // defines ASSERT
#include <tchar.h>
#include <vector>


class CCPLComInitializer
{
public:
	CCPLComInitializer(DWORD dwCoInit = COINIT_MULTITHREADED)
	{
		m_bInitialized = true;
		HRESULT hr = ::CoInitializeEx(NULL, dwCoInit);
		if (SUCCEEDED(hr)) {
			return;
		}
		m_bInitialized = false;
		::OutputDebugString(_T("COM Initialization failed"));
	}
	~CCPLComInitializer()
	{
		if (true == m_bInitialized) {
			::CoUninitialize();
		}
	}
private:
	bool m_bInitialized;
};

		

class CCPLWinHandle
{
public:
	CCPLWinHandle(HANDLE h) 
	{
		m_h = h;
	}

	CCPLWinHandle() 
	{
		m_h = INVALID_HANDLE_VALUE;
	}
	~CCPLWinHandle()
	{
		CloseHandle();
	}

	bool IsValid()
	{
		return ((INVALID_HANDLE_VALUE == m_h) || (NULL == m_h)) ? false : true;
	}

	void operator=(HANDLE h)
	{
		CloseHandle();
		m_h = h;
	}
	void CloseHandle()
	{
		if ((INVALID_HANDLE_VALUE == m_h) || (NULL == m_h)) {
			return;
		}
		::CloseHandle(m_h);
		m_h = INVALID_HANDLE_VALUE;
	}

	HANDLE Detach()
	{
		HANDLE hRetVal = m_h;
		m_h = INVALID_HANDLE_VALUE;
		return hRetVal;
	}

	operator HANDLE ()
	{
		return m_h;
	}

private:
	HANDLE m_h;
};

class CCPLWinAutolockCriticalSection
{
public:
	CCPLWinAutolockCriticalSection(CRITICAL_SECTION& cs) : m_cs(cs)
	{
		::EnterCriticalSection(&m_cs);
	}
	~CCPLWinAutolockCriticalSection()
	{
		::LeaveCriticalSection(&m_cs);
	}
private:
	CRITICAL_SECTION& m_cs;
};


class CCPLWinEvent
{
public:
	CCPLWinEvent()
	{
	}
	HRESULT Init(bool bAutoReset = true)
	{
		HANDLE hEvent = ::CreateEvent(
			NULL,
			bAutoReset ? FALSE : TRUE,
			FALSE,
			NULL);
		if (NULL == hEvent) {
			return HRESULT_FROM_WIN32(::GetLastError());
		}
		m_hEvent = hEvent;
		return S_OK;
	}
	~CCPLWinEvent()
	{
		m_hEvent = NULL;
	}

	HRESULT Signal()
	{
		_ASSERT (true == m_hEvent.IsValid());
		BOOL bRetVal = ::SetEvent(m_hEvent);
		if (FALSE == bRetVal) {
			return HRESULT_FROM_WIN32(::GetLastError());
		}
		return S_OK;
	}

	bool Wait(DWORD dwTimeout = INFINITE)
	{
		_ASSERT (true == m_hEvent.IsValid());
		DWORD dwRetVal = ::WaitForSingleObject(m_hEvent, dwTimeout);
		return (WAIT_OBJECT_0 == dwRetVal) ? true : false;
	}

	operator HANDLE()
	{
		return m_hEvent;
	}


	CCPLWinHandle& GetHandle()
	{
		return m_hEvent;
	}


private:
	CCPLWinHandle m_hEvent;
};

class CCPLWinAtomicCounter
{
public:
	CCPLWinAtomicCounter();

	operator LONG () const;
	LONG operator=(LONG rhs);
	LONG operator++();
	LONG operator--();
	LONG operator++(int);
	LONG operator--(int);
	LONG operator+=(LONG rhs);
	LONG operator-=(LONG rhs);
	LONG Exchange(LONG rhs);

private:
	mutable LONG m_lCount;
};


inline CCPLWinAtomicCounter::CCPLWinAtomicCounter()
{
	m_lCount = 0;
}

inline LONG CCPLWinAtomicCounter::operator++()
{
	return ::InterlockedIncrement(&m_lCount);
}

inline LONG CCPLWinAtomicCounter::operator--()
{
	return ::InterlockedDecrement(&m_lCount);
}

inline LONG CCPLWinAtomicCounter::operator=(LONG rhs)
{
	return ::InterlockedExchange(&m_lCount, rhs);
}

inline LONG CCPLWinAtomicCounter::operator++(int)
{
	return ::InterlockedExchangeAdd(&m_lCount, 1);
}

inline CCPLWinAtomicCounter::operator LONG() const
{
	return m_lCount;
}

inline LONG CCPLWinAtomicCounter::operator--(int)
{
	return ::InterlockedExchangeAdd(&m_lCount, -1);
}

inline LONG CCPLWinAtomicCounter::operator+=(LONG rhs)
{
	return ::InterlockedExchangeAdd(&m_lCount, rhs) + rhs;
}

inline LONG CCPLWinAtomicCounter::Exchange(LONG rhs)
{
	return ::InterlockedExchange(&m_lCount, rhs);
}


class CCPLWinCriticalSection
{
public:
	CCPLWinCriticalSection()
	{
		::InitializeCriticalSection(&m_CS);
	}

	~CCPLWinCriticalSection()
	{
		::DeleteCriticalSection(&m_CS);
	}

	class GUARD
	{
	public:
		GUARD(CCPLWinCriticalSection& cs) : m_NTCS (cs)
		{
			::EnterCriticalSection(&m_NTCS.m_CS);
		}

		~GUARD()
		{
			::LeaveCriticalSection(&m_NTCS.m_CS);
		}

	private:
		CCPLWinCriticalSection& m_NTCS;
	};

private:
	friend class CCPLWinCriticalSection::GUARD;
	CRITICAL_SECTION m_CS;
};

template <class T> class CCPLWinSharedResource
{
public:
   CCPLWinSharedResource() {}
   ~CCPLWinSharedResource() {}

   class GUARD
   {
   public:
	  GUARD(CCPLWinSharedResource<T>& t) : 
		 m_SharedResource (t),
		 m_Guard (t.m_NTCS)
	  {
	  }

	  ~GUARD()
	  {
	  }

	  operator  T& () 
	  {
		 return m_SharedResource.m_t;
	  }

   private:
	  CCPLWinSharedResource<T>& m_SharedResource;
	  CCPLWinCriticalSection::GUARD m_Guard;
   };
private:
	 T m_t;
	 CCPLWinCriticalSection m_NTCS; 

	 friend class CCPLWinSharedResource<T>::GUARD;
	 void operator=(const CCPLWinSharedResource<T>& t) {}; // equal operation illegal
	 CCPLWinSharedResource<T>(const CCPLWinSharedResource<T>& t) {};  // copy constructor illegal
};

#define COINIT_NOAPARTMENT -1

class CCPLWinThread
{
public:
	CCPLWinThread();			// Constructor
	HRESULT Init();			// Initializer
	virtual ~CCPLWinThread();	// Destructor

	// Set the apartment the thread should enter
	// Parameter: COINIT_NOAPARTMENT, COINIT_[APARTMENT|MULTI_THREADED]
	bool SetApartmentToEnter(DWORD dwApt = COINIT_MULTITHREADED);

	HRESULT StartThread();	// Start the thread
	bool IsThreadActive();	// Check if the thread is running
	void StopThread();		// Stop the thread

	// Wait for the thread to quit within the
	// specified timeout interval.
	bool WaitForCompletion(DWORD dwTimeOut = INFINITE);

	// Additional handles for waiting on multiple objects
	void AddHandleToWaitGroup(HANDLE h);

protected:
	virtual void Proc() = 0;        // The thread entry point
	virtual void OnTermination() {} // override if you wish to do any cleanup

	//Wait for any handle to raise an event
	HANDLE Wait(DWORD dwTimeOut = INFINITE);

protected:
	static unsigned int _stdcall ThreadProc(void* pData);
	CCPLWinEvent m_hStopEvent; // doesn't change once initialized
  
private:
	CCPLWinHandle m_hThread;   // doesn't change once a thread is created
	DWORD m_dwAptToEnter;    // cannot be changed while a thread is running
	std::vector<HANDLE> m_WaitGroup; // cannot be changed while a thread is running
};

//
// Functions
//
HRESULT
CPLCreateInstance(
   LPCOLESTR pwszMach, // @parm [in] Remote machine
   const CLSID& clsId, // @parm [in] Class ID
   IUnknown** ppOut,   // @parm [out, retval] IUnknown instance handle
   DWORD dwClsCtx = CLSCTX_SERVER // @parm [in] CLSCTX values
);

_bstr_t CPLGetError(_com_error& e);

#endif // CPLBASE_INCLUDED
