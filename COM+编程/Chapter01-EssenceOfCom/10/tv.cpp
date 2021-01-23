#include "Video.h"
#include <windows.h>
#include <iostream.h>

void UseSVideo(ISVideo* pSVideo);

IGeneral* CreateInstance(char* pszDll, char* pszType)
{
   typedef IGeneral* (_stdcall *CREATEVCRPROC)(char* pszType);

   HINSTANCE h = LoadLibrary(pszDll);
   CREATEVCRPROC proc =
     reinterpret_cast<CREATEVCRPROC>(GetProcAddress(h, "CreateVCR"));
   return (*proc)(pszType);
}
    
int main(int argc, char* argv[])
{
	IGeneral* pGeneral = CreateInstance("vcr.dll", "svideo");
	if (NULL == pGeneral) {
		cout << "This VCR does not have the signal we support" << endl;
		return 1;
	}

	UseSVideo(reinterpret_cast<ISVideo*>(pGeneral));
	pGeneral->Delete();
	return 0;
}

void UseSVideo(ISVideo* pSVideo)
{
	for(int i=0; i<10; i++) {
		long val = pSVideo->GetSVideoSignalValue();
			cout << "Round: " << i << " - Value: " << val << endl;
	}
}

