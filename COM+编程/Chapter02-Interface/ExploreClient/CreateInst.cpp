#include "StdAfx.h"

HRESULT
PTCreateRemoteInstance(
   LPCOLESTR pwszMach, // @parm [in] Remote machine
   const CLSID& clsId, // @parm [in] Class ID
   IUnknown** ppOut)   // @parm [out, retval] IUnknown instance handle
{
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
		CLSCTX_SERVER,
		&serverInfo,
		1,
		&mqiEntry);

	if (FAILED(hr)) {
	   return hr;
	}

	*ppOut = mqiEntry.pItf;
	
	return hr;
}
