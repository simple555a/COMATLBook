#include "Video.h"
#include <windows.h>
#include <iostream.h>

void UseVideo(IVideo* pVideo);
void UseSVideo(ISVideo* pSVideo);

IGeneral* CreateInstance(char* pszDll)
{
   typedef IGeneral* (_stdcall *CREATEVCRPROC)(void);

   HINSTANCE h = LoadLibrary(pszDll);
   CREATEVCRPROC proc =
     reinterpret_cast<CREATEVCRPROC>(GetProcAddress(h, "CreateVCR"));
   return (*proc)();
}
    
int main(int argc, char* argv[])
{
	IGeneral* pVCR = CreateInstance("vcr.dll");

	// Use S-Video if available
	IGeneral* pGeneral = pVCR->Probe("svideo");
	if (NULL != pGeneral) {
		ISVideo* pSVideo = reinterpret_cast<ISVideo*>(pGeneral);
		UseSVideo(pSVideo);
		pSVideo->Delete();
		return 0;
	}

	// S-Video not available. Try old "video" type
	pGeneral = pVCR->Probe("video");
	if (NULL != pGeneral) {
		IVideo* pVideo = reinterpret_cast<IVideo*>(pGeneral);
		UseVideo(pVideo);
		pVideo->Delete();
		return 0;
	}

	// Neither S-Video nor Video
	cout << "This VCR does not have the signals we support" << endl;
	pVCR->Delete(); // Done with interface pVCR
	return 1;
}

void UseVideo(IVideo* pVideo)
{
	for(int i=0; i<10; i++) {
		long val = pVideo->GetSignalValue();
		cout << "Round: " << i << " - Value: " << val << endl;
	}

}

void UseSVideo(ISVideo* pSVideo)
{
	for(int i=0; i<10; i++) {
		long val = pSVideo->GetSVideoSignalValue();
		cout << "Round: " << i << " - Value: " << val << endl;
	}
}

