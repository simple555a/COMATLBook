#include <windows.h>
#include <iostream.h>
#import "Video.tlb" no_namespace

void DoIt()
{
	ISVideoPtr spSVideo(__uuidof(VCR));
	long val = spSVideo->GetSVideoSignalValue();
	cout << "Value: " << val << endl;
}

void DumpError(_com_error& e)
{
	if (HRESULT_FACILITY(e.Error()) == FACILITY_ITF) {
		cout << "ISVideo specific error: 0x" << hex << e.Error() << endl;
	}else {
		cout << e.ErrorMessage() << endl;
	}

	// Extended error, if any
	_bstr_t bsDesc = e.Description();
	if (NULL != (LPCTSTR) bsDesc) {
		cout << "Extended error info: " << (LPCTSTR) bsDesc << endl;
	}
}	

int main(int /*argc*/, char* /*argv*/[])
{
	::CoInitialize(NULL);
	try {
		DoIt();
	}catch(_com_error& e) {
		DumpError(e);
	}
		
	::CoUninitialize();
	return 0;
}

