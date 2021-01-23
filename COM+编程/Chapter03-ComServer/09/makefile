
ALL: MyVcr.dll TV.exe

CLFLAGS=-Zi -Od -W4
LINKFLAGS=-Debug

.cpp.obj:
	cl -c $*.cpp $(CLFLAGS)

OBJLIST=StdAfx.obj VcrDLL.obj Vcr.obj ClassObject.obj MyModule.obj
LIBLIST=advapi32.lib 

MyVcr.dll : $(OBJLIST) Vcr.def
	link -dll -out:MyVcr.dll -def:Vcr.def $(OBJLIST) $(LIBLIST) $(LINKFLAGS)

tv.exe : tv.cpp
	cl $(CLFLAGS) tv.cpp ole32.lib
 
Vcr.obj : Vcr.cpp Vcr.h Video.h StdAfx.h

VcrDLL.obj : VcrDLL.cpp Vcr.h Video.h StdAfx.h

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
