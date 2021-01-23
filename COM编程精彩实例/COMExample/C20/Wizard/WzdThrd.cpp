// WzdThrd.cpp: Implementation of WzdThrd thread

#include "stdafx.h"
#include <process.h>    /* _beginthread, _endthread */

/////////////////////////////////////////////////////////////////////////////
// event stuff
extern long lArg;
extern HANDLE ghNow, ghDie, ghDone;


// the thread
void WzdThrd(LPVOID param)
{
	// thread will work in background
	::SetThreadPriority(::GetCurrentThread(),THREAD_PRIORITY_BELOW_NORMAL);

	// forever		
	while (true)
	{
	// wait for termination, timeout or a now event
	int rVal;
	HANDLE hEventArray[2]  = {ghDie, ghNow};
	if ((rVal=WaitForMultipleObjects(2, hEventArray, FALSE, 30000))==WAIT_OBJECT_0)
		break; // terminate now!

	switch (rVal)
	{
/////////////////////////////////////////////////////////////////////////
////////////////////   NOW EVENT //////////////////////////////////
/////////////////////////////////////////////////////////////////////////
	case WAIT_OBJECT_0+1:
		ResetEvent(ghNow);


		break;
	}
	}

	// end thread
	SetEvent(ghDone);
	_endthread();	
}
