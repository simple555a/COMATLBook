// File MyModule.h

#pragma once

class CVcrClassObject; // forward declaration

struct MYMODULEINFO
{
	MYMODULEINFO()
	{
		hInstance = NULL;
		pVCRClassObject = NULL;
		lCount = 0;
	}

	HINSTANCE hInstance;
	CVcrClassObject* pVCRClassObject;
	ULONG lCount;
};

extern MYMODULEINFO g_MyModule;

