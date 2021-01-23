#include "Video.h"
#include <windows.h>
#include <iostream.h>

bool UseVideoIfAvailable(IGeneral* pVCR);
bool UseSVideoIfAvailable(IGeneral* pVCR);
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

	bool bRetVal = UseSVideoIfAvailable(pVCR);
	if (false == bRetVal) {
		bRetVal = UseVideoIfAvailable(pVCR);
	}

	if (false == bRetVal) {
		// Neither S-Video nor Video
		cout << "This VCR does not have the signals we support" << endl;
	}

	pVCR->Delete(); // Done with pVCR
	return 0;
}

bool UseSVideoIfAvailable(IGeneral* pVCR)
{
	IGeneral* pGeneral = pVCR->Probe("svideo");
	if (NULL == pGeneral) {
		return false;
	}

	ISVideo* pSVideo = reinterpret_cast<ISVideo*>(pGeneral);
	UseSVideo(pSVideo);
	pSVideo->Delete();
	return true;
}

bool UseVideoIfAvailable(IGeneral* pVCR)
{
	IGeneral* pGeneral = pVCR->Probe("video");
	if (NULL == pGeneral) {
		return false;
	}

	IVideo* pVideo = reinterpret_cast<IVideo*>(pGeneral);
	UseVideo(pVideo);
	pVideo->Delete();
	return true;
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

