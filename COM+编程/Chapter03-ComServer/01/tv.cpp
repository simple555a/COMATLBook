#include "Video.h"
#include <windows.h>
#include <iostream.h>
#include "Video_i.c"

void UseSVideo(ISVideo* pSVideo);

void DumpError(HRESULT hr)
{
	LPTSTR pszErrorDesc = NULL;

	DWORD dwCount  = ::FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM,
		NULL,
		hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		reinterpret_cast<LPTSTR>(&pszErrorDesc),
		0,
		NULL);

	if (0 == dwCount) {
		cout << "Unknown HRESULT: " << hex << hr << endl;
		return;
	}

	cout << pszErrorDesc << " (0X" << hex << hr << ")" << endl;
	LocalFree(pszErrorDesc);
}
	
int main(int argc, char* argv[])
{
	::CoInitialize(NULL);
	ISVideo* pSVideo = NULL;
	HRESULT hr = ::CoGetClassObject(CLSID_VCR, CLSCTX_ALL, NULL, IID_ISVideo,
		reinterpret_cast<void**>(&pSVideo));
	if (FAILED(hr)) {
		DumpError(hr);
		::CoUninitialize();
		return 1;
	}

	UseSVideo(pSVideo);
	pSVideo->Release();
	::CoUninitialize();
	return 0;
}

void UseSVideo(ISVideo* pSVideo)
{
	long val;
	HRESULT hr;
	for(int i=0; i<10; i++) {
		hr = pSVideo->GetSVideoSignalValue(&val);
		if (FAILED(hr)) {
			DumpError(hr);
			continue;
		}
		cout << "Round: " << i << " - Value: " << val << endl;
	}
}

