#include "VCR.h"
#include <iostream.h>

int main(int argc, char* argv[])
{
	int i;
	CVcr vcr;

	for(i=0; i<10; i++) {
		long val = vcr.GetSignalValue();
		cout << "Round: " << i << " - Value: " << val << endl;
	}

	return 0;
}

