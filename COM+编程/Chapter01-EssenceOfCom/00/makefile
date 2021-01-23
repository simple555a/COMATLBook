ALL : tv.exe

!ifdef DEBUG
CLFLAGS=-Zi -Od
LINKFLAGS=-DEBUG
!else
CLFLAGS=
LINKFLAGS=
!endif

vcr.obj : vcr.cpp vcr.h 
	cl -c vcr.cpp $(CLFLAGS)

tv.exe : tv.cpp vcr.h vcr.obj
	cl tv.cpp $(CLFLAGS) vcr.obj

CLEAN:
	erase vcr.obj
	erase tv.obj
	erase tv.exe
	erase *.ilk
	erase *.pdb

