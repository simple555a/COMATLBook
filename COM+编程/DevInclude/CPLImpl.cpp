//****************************************************************************
//
// Com+ Utility Library - Source File
//
// This file should be included just once in the project.
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

#include <CPLBase.h>
#include <ole2.h>
#include <process.h> // _beginthreadex

CCPLWinThread::CCPLWinThread()
{
	m_dwAptToEnter = COINIT_NOAPARTMENT;
}

HRESULT CCPLWinThread::Init()
{
	HRESULT hRes = m_hStopEvent.Init();
	if (FAILED(hRes)) {
		return hRes;
	}
	m_WaitGroup.push_back(m_hStopEvent.GetHandle());

	return S_OK;
}

CCPLWinThread::~CCPLWinThread()
{
	StopThread();
}

void CCPLWinThread::AddHandleToWaitGroup(HANDLE h)
{
	_ASSERT (NULL != h);
	m_WaitGroup.push_back(h);
}


bool CCPLWinThread::SetApartmentToEnter(DWORD dwApt)
{
	if (true == IsThreadActive()) {
		// value cannot be change while a thread is active
		return false;
	}
	m_dwAptToEnter = dwApt;
	return true;
}

HRESULT CCPLWinThread::StartThread()
{
	_ASSERT (true == m_hStopEvent.GetHandle().IsValid());

	// if thread is already active, return
	if (true == IsThreadActive()){
		return S_OK;
	}

	unsigned int idThread;
	HANDLE hThread =
		(HANDLE) _beginthreadex(NULL, 0, ThreadProc, this, CREATE_SUSPENDED, &idThread);
    if (NULL == hThread) {
        return HRESULT_FROM_WIN32(::GetLastError());
    }
	m_hThread = hThread;

	::ResumeThread(hThread);
	return S_OK;
}

void CCPLWinThread::StopThread()
{
	if (false == IsThreadActive()) {
		return; // thread already stopped
	}

   // tell the thread to stop
   m_hStopEvent.Signal();

   // wait for the thread to stop
   ::WaitForSingleObject(m_hThread, INFINITE); 

   // clean up
   m_hThread = NULL; // CloseHandle called automatically
}

bool CCPLWinThread::IsThreadActive()
{
	if (false == m_hThread.IsValid()) {
		return false;
	}

	DWORD dwThreadStatus;
	BOOL bResult = ::GetExitCodeThread(m_hThread, &dwThreadStatus);
	bool bActive = (bResult && (STILL_ACTIVE == dwThreadStatus)) ? true : false;
	if (false == bActive) {
		// Detroy the thread handle
		m_hThread = NULL; // CloseHandle called automatically
	}
    return bActive;
}

bool CCPLWinThread::WaitForCompletion(DWORD dwTimeOut)
{
	if (false == IsThreadActive()) {
		return true; // thread already stopped
	}

	DWORD dwRetVal = ::WaitForSingleObject(m_hThread, dwTimeOut); 
	return (WAIT_TIMEOUT == dwRetVal) ? false : true;
	// NOTE: No real need to CloseHandle here. Will happen somewhere
	// later when IsThreadActive is called
}

HANDLE CCPLWinThread::Wait(DWORD dwTimeOut)
{
	DWORD dwNumHandles = m_WaitGroup.size();

	DWORD dwIndex = -1; // handle of the signaled object

	if (COINIT_NOAPARTMENT != m_dwAptToEnter) {
		// use COM API
		DWORD dwRetVal = ::CoWaitForMultipleHandles(
			0, 
			dwTimeOut,
			dwNumHandles,
			m_WaitGroup.begin(),
			&dwIndex);
		if (RPC_S_CALLPENDING == dwRetVal) {
			return NULL;
		}
	}else {
		// use non-COM API
		DWORD dwRetVal = ::WaitForMultipleObjects(
			dwNumHandles,
			m_WaitGroup.begin(),
			FALSE,
			dwTimeOut);

		if (WAIT_TIMEOUT == dwRetVal) {
			return NULL;
		}

		if( (dwRetVal >= WAIT_OBJECT_0) && (dwRetVal < (WAIT_OBJECT_0 + dwNumHandles))) {
			dwIndex = dwRetVal - WAIT_OBJECT_0;
		}else
		if( (dwRetVal >= WAIT_ABANDONED_0) && (dwRetVal < (WAIT_ABANDONED_0 + dwNumHandles))) {
			dwIndex = dwRetVal - WAIT_ABANDONED_0;
		}
	}

	_ASSERT (dwIndex >= 0);
	_ASSERT (dwIndex < m_WaitGroup.size());

	return m_WaitGroup[dwIndex];
}

unsigned int _stdcall
CCPLWinThread::ThreadProc(void* pData)
{
    _ASSERT (NULL != pData); 
    CCPLWinThread* pThread = reinterpret_cast<CCPLWinThread*>(pData);


	HRESULT hr = E_FAIL;
	if (COINIT_NOAPARTMENT != pThread->m_dwAptToEnter) {
		hr = ::CoInitializeEx(NULL, pThread->m_dwAptToEnter);
		_ASSERT (SUCCEEDED(hr));
	}

	pThread->Proc();
    pThread->OnTermination(); // thread specific cleanup

	if (SUCCEEDED(hr)) {
		::CoUninitialize();
	}

    return 0;
}

//@func Create an IUnknown instance from a local or remote machine
HRESULT
CPLCreateInstance(
   LPCOLESTR pwszMach, // @parm [in] Remote machine
   const CLSID& clsId, // @parm [in] Class ID
   IUnknown** ppOut,   // @parm [out, retval] IUnknown instance handle
   DWORD dwClsCtx /*= CLSCTX_SERVER*/ //@parm [in] CLSCTX values
   )
{
	*ppOut = NULL;
	if (NULL == pwszMach || (0 == lstrlenW(pwszMach))) {
		return ::CoCreateInstance(clsId, NULL, dwClsCtx, IID_IUnknown,
			reinterpret_cast<void**>(ppOut));
	}

	COSERVERINFO serverInfo;
	serverInfo.dwReserved1 = 0;
	serverInfo.pwszName = const_cast<LPOLESTR>(pwszMach);
	serverInfo.pAuthInfo = NULL;
	serverInfo.dwReserved2 = 0;

	MULTI_QI mqiEntry;
	mqiEntry.pIID = &IID_IUnknown;
	mqiEntry.pItf = NULL;
	mqiEntry.hr = 0;

	HRESULT hr = CoCreateInstanceEx(clsId,
		NULL,
		dwClsCtx,
		&serverInfo,
		1,
		&mqiEntry);

	if (FAILED(hr)) {
	   return hr;
	}

	_ASSERT (NULL != mqiEntry.pItf);
	*ppOut = mqiEntry.pItf;
	
	return hr;
}

_bstr_t CPLGetError(_com_error& e)
{
	_bstr_t retVal = "Error Msg: ";
	retVal += e.ErrorMessage();
	retVal += "\n";
	retVal += "Description: ";
	retVal += e.Description();
	return retVal;
}
