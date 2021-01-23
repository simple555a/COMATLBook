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

video.obj : video.cpp video.h 
	cl -c video.cpp $(CLFLAGS)

vcr.dll : vcr.obj video.obj vcr.def
	link -dll -def:vcr.def vcr.obj video.obj $(LINKFLAGS)

tv.exe : tv.cpp vcr.h vcr.lib
	cl tv.cpp $(CLFLAGS) vcr.lib

CLEAN:
	erase vcr.obj
	erase vcr.lib
	erase vcr.exp
	erase vcr.dll
	erase Video.obj
	erase tv.obj
	erase tv.exe
	erase *.ilk
	erase *.pdb

