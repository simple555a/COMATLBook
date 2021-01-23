#include "Video.h"
#include <windows.h>
#include <iostream.h>

void UseSVideo(ISVideo* pSVideo);

void ReportError(VRESULT vr)
{
	char* pszError = NULL;
	switch(vr) {
	case V_OUTOFMEMORY:
		pszError = "Out of memory";
		break;
	case V_NOINTERFACE:
		pszError = "No such interface supported";
		break;
	case V_INTERNALERROR:
		pszError = "Internal error. Contact the VCR vendor";
		break;
	default:
		pszError = "Unknown error";
	}
	cout << pszError << endl;
}
	
VRESULT CreateInstance(char* pszDll, char* pszType, IGeneral** ppRetVal)
{
	typedef VRESULT (_stdcall *CREATEVCRPROC)(char* pszType, IGeneral** ppRetVal);

	HINSTANCE h = LoadLibrary(pszDll);
	CREATEVCRPROC proc =
		reinterpret_cast<CREATEVCRPROC>(GetProcAddress(h, "CreateVCR"));
	return  (*proc)(pszType, ppRetVal);
}
    
int main(int argc, char* argv[])
{
	IGeneral* pGeneral = NULL;
	VRESULT vr = CreateInstance("vcr.dll", "svideox", &pGeneral);
	if (V_FAILED(vr)) {
		ReportError(vr);
		return 1;
	}

	UseSVideo(reinterpret_cast<ISVideo*>(pGeneral));
	pGeneral->Delete();
	return 0;
}

void UseSVideo(ISVideo* pSVideo)
{
	long val;
	VRESULT vr;
	for(int i=0; i<10; i++) {
		vr = pSVideo->GetSVideoSignalValue(&val);
		if (V_FAILED(vr)) {
			ReportError(vr);
			continue;
		}
		cout << "Round: " << i << " - Value: " << val << endl;
	}
}

