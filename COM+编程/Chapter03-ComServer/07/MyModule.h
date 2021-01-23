// File MyModule.h

#pragma once

class CVcrClassObject; // forward declaration

struct MYMODULEINFO
{
	MYMODULEINFO()
	{
		hInstance = NULL;
		pVCRClassObject = NULL;
	}

	HINSTANCE hInstance;
	CVcrClassObject* pVCRClassObject;
};

extern MYMODULEINFO g_MyModule;

