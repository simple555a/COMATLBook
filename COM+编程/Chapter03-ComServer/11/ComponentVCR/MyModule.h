// File MyModule.h

#pragma once

class CComponentVcrClassObject; // forward declaration

struct MYMODULEINFO
{
	MYMODULEINFO()
	{
		hInstance = NULL;
		pVCRClassObject = NULL;
		lCount = 0;
	}

	HINSTANCE hInstance;
	CComponentVcrClassObject* pVCRClassObject;
	ULONG lCount;
};

extern MYMODULEINFO g_MyModule;

