#include "StdAfx.h"

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
