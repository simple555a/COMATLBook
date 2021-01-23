#include <atlbase.h>
#include <windows.h>
#include <iostream.h>

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


ostream& operator << (ostream& os, const wchar_t* pwszString)
{
	USES_CONVERSION;
	LPTSTR pszString = W2A(pwszString);
	os << pszString;
	return os;
}



int main()
{
	// Generate a GUID
	GUID guid;

	HRESULT hr = ::CoCreateGuid(&guid);

	if (FAILED(hr)) {
		DumpError(hr);
		return 1;
	}

	OLECHAR szGuid[40]; 
	::StringFromGUID2(guid, szGuid, 40);
	cout << "GUID: " << szGuid << endl;

	return 0;
}

