ALL : vcr.dll tv.exe

!ifdef DEBUG
CLFLAGS=-Zi -Od
LINKFLAGS=-DEBUG
!else
CLFLAGS=
LINKFLAGS=
!endif

vcr.obj : vcr.cpp vcr.h 
	cl -c vcr.cpp $(CLFLAGS)

vcr.dll : vcr.obj vcr.def
	link -dll -def:vcr.def vcr.obj $(LINKFLAGS)

tv.exe : 
	copy ..\01\tv.exe

CLEAN:
	erase vcr.obj
	erase vcr.lib
	erase vcr.exp
	erase vcr.dll
	erase tv.exe
	erase *.ilk
	erase *.pdb

