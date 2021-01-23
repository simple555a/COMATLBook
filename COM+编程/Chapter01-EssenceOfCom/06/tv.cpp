#include "Video.h"
#include <windows.h>
#include <iostream.h>

IVideo* CreateInstance(char* pszDll)
{
   typedef IVideo* (_stdcall *CREATEVIDEOPROC)(void);

   HINSTANCE h = LoadLibrary(pszDll);
   CREATEVIDEOPROC proc =
     reinterpret_cast<CREATEVIDEOPROC>(GetProcAddress(h, "CreateVCR"));
   return (*proc)();
}
    
int main(int argc, char* argv[])
{
	int i;
	IVideo* pVideo = CreateInstance("vcr.dll");

	for(i=0; i<10; i++) {
		long val = pVideo->GetSignalValue();
		cout << "Round: " << i << " - Value: " << val << endl;
	}

	pVideo->Delete();

	return 0;
}

