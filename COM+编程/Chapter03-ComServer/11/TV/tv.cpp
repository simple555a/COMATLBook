#include <windows.h>
#include <iostream.h>
#include "../MyVcr/Video.h"
#include "../MyVcr/Video_i.c"
#include "../ComponentVcr/ComponentVideo.h"
#include "../ComponentVcr/ComponentVideo_i.c"

void UseCVideo(IComponentVideo* pSVideo);

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
	IComponentVideo* pCVideo = NULL;
	HRESULT hr = ::CoCreateInstance(CLSID_VCR, NULL, CLSCTX_ALL, IID_IComponentVideo,
		reinterpret_cast<void**>(&pCVideo));
	if (FAILED(hr)) {
		DumpError(hr);
		::CoUninitialize();
		return 1;
	}

	UseCVideo(pCVideo);

	pCVideo->Release();

	::CoUninitialize();
	return 0;
}

void UseCVideo(IComponentVideo* pCVideo)
{
	long val;
	HRESULT hr;
	for(int i=0; i<10; i++) {
		hr = pCVideo->GetCVideoSignalValue(&val);
		if (FAILED(hr)) {
			DumpError(hr);
			continue;
		}
		cout << "Round: " << i << " - Value: " << val << endl;
	}
}

