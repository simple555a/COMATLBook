#include "Video.h"
#include <iostream.h>

int main(int argc, char* argv[])
{
	int i;
	IVideo* pVideo = CreateVCR();

	for(i=0; i<10; i++) {
		long val = pVideo->GetSignalValue();
		cout << "Round: " << i << " - Value: " << val << endl;
	}

	pVideo->Delete();

	return 0;
}

