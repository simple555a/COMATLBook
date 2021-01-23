// Client.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#import "../TNAServer/TNAServer.tlb"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	CCPLComInitializer init(COINIT_APARTMENTTHREADED);

	try {
		TNASERVERLib::IMyTNAServerPtr spTNA(__uuidof(TNASERVERLib::MyTNAServer));

		spTNA->DoIt();
	}catch(_com_error& e) {
		::MessageBox(NULL, CPLGetError(e), NULL, MB_OK);
	}

	return 0;
}



