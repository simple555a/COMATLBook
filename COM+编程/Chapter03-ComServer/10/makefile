
ALL: MyVcr.exe TV.exe

CLFLAGS=-Zi -Od -W4 -DDEBUG
LINKFLAGS=-Debug

.cpp.obj:
	cl -c $*.cpp $(CLFLAGS)

OBJLIST=StdAfx.obj Main.obj Vcr.obj ClassObject.obj MyModule.obj
LIBLIST=advapi32.lib user32.lib ole32.lib

MyVcr.exe : $(OBJLIST) 
	link -out:MyVcr.exe $(OBJLIST) $(LIBLIST) $(LINKFLAGS)

tv.exe : tv.cpp
	cl $(CLFLAGS) tv.cpp ole32.lib
 
Vcr.obj : Vcr.cpp Vcr.h Video.h StdAfx.h

Main.obj : Main.cpp Video.h Vcr.h StdAfx.h

ClassObject.obj : ClassObject.cpp Vcr.h Video.h StdAfx.h

StdAfx.obj : StdAfx.cpp StdAfx.h MyModule.h

Video.h : Video.idl
	midl Video.idl

clean :
	erase *.ilk
	erase *.obj
	erase *.exe
	erase *.dll
	erase *.lib
	erase *.pdb
	erase *.ilk
	erase *.exp
	erase *.opt
	erase Video.h
	erase DllData.c
	erase Video.tlb
	erase Video_i.c
	erase Video_p.c
