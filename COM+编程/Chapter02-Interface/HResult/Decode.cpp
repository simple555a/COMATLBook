#include <windows.h>
#include <iostream.h>
#include <stdio.h>
#include <comdef.h>

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

	cout << pszErrorDesc << endl;
	LocalFree(pszErrorDesc);
}

void DumpError2(HRESULT hr)
{
	cout << _com_error(hr).ErrorMessage() << endl;
}


int main(int argc, char* argv[])
{
	if (2 != argc) {
		return 1;
	}

	HRESULT hr;
	int n = sscanf(argv[1], "%x", &hr);
	if (1 != n) {
		cout << "Could not scan: " << argv[1] << endl;
		return 1;
	}

	cout << "Formatting: 0x" << hex << hr << endl;
	DumpError(hr);
	DumpError2(hr);
	return 0;
}


