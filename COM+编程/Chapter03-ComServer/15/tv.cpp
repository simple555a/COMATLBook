#include "Video.h"
#include <windows.h>
#include <iostream.h>
#include "Video_i.c"
#include <atlbase.h>

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

void DoIt()
{
	CComPtr<ISVideo> spSVideo;
	HRESULT hr = ::CoCreateInstance(CLSID_VCR, NULL, CLSCTX_ALL, IID_ISVideo,
		reinterpret_cast<void**>(&spSVideo));
	if (FAILED(hr)) {
		DumpError(hr);
		return;
	}

	long val;
	hr = spSVideo->GetSVideoSignalValue(&val);
	if (SUCCEEDED(hr)) {
		cout << "Value: " << val << endl;
		return;
	}

	// The call failed
	if (HRESULT_FACILITY(hr) == FACILITY_ITF) {
		cout << "ISVideo specific error: 0x" << hex << hr << endl;
	}else {
		DumpError(hr);
	}

	// Check if the object supports extended error information
	CComPtr<ISupportErrorInfo> spSEI;
	hr = spSVideo->QueryInterface(IID_ISupportErrorInfo, (void**) &spSEI);
	if (FAILED(hr)) {
		return; // error info not supported
	}

	// Check if error info is available for ISVideo interface
	hr = spSEI->InterfaceSupportsErrorInfo(IID_ISVideo);
	if (S_OK != hr) {
		return; // error info not supported on ISVideo
	}

	// Get the error information and display
	CComPtr<IErrorInfo> spEI;
	hr = ::GetErrorInfo(0, &spEI);
	if (FAILED(hr)) {
		return; // failed for some obscure reason
	}
	
	CComBSTR bsDesc;
	hr = spEI->GetDescription(&bsDesc);
	if (FAILED(hr)) {
		return; // failed for some obscure reason
	}

	USES_CONVERSION;
	cout << "Extended error info: " << W2T(bsDesc) << endl;
}
	
int main(int /*argc*/, char* /*argv*/[])
{
	::CoInitialize(NULL);
	DoIt();
	::CoUninitialize();
	return 0;
}

