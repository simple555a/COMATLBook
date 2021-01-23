// Wzd.cpp : Implementation of CWzd
#include "stdafx.h"
#include "comdef.h"
#include "Server.h"
#include "Wzd.h"

#import "..\CollSrv\CollSrv.tlb" no_namespace

/////////////////////////////////////////////////////////////////////////////
// CWzd


//////////////////////////////////////////////////////////////////////////
////////////////     PASSING COLLECTIONS    ///////////////////////////
//////////////////////////////////////////////////////////////////////////

STDMETHODIMP CWzd::GetCollection(LPUNKNOWN *pCollection)
{
	// create collection and initialize it
	IWzdCollectionPtr pPtr;
	pPtr.CreateInstance(__uuidof(WzdCollection));
	pPtr->Init(
			3		// number of objects to add
			);

	// create and add those objects
	for (int i=0;i<3;i++)
	{
		LPBYTE lpByte;
		SAFEARRAY *pSA=::SafeArrayCreateVector(VT_UI1,0,10);
		::SafeArrayAccessData(pSA,(LPVOID*)&lpByte);
		lpByte[0]=(BYTE)i;
		::SafeArrayUnaccessData(pSA);
		pPtr->Add(&pSA);
	}

	// return created COM object that contains the collection
	*pCollection=pPtr.Detach();

	return S_OK;
}

