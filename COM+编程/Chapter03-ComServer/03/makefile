
ALL: MyVcr.dll TV.exe

CLFLAGS=-Zi -Od -W4
LINKFLAGS=-Debug

.cpp.obj:
	cl -c $*.cpp $(CLFLAGS)


MyVcr.dll : VcrDLL.obj Vcr.obj ClassObject.obj Vcr.def
	link -dll -out:MyVcr.dll -def:Vcr.def VcrDLL.obj ClassObject.obj Vcr.obj $(LINKFLAGS)

tv.exe : tv.cpp
	cl tv.cpp ole32.lib
	
Vcr.obj : Vcr.cpp Vcr.h Video.h

VcrDLL.obj : VcrDLL.cpp Vcr.h Video.h

ClassObject.obj : ClassObject.cpp Vcr.h Video.h

Video.h : Video.idl
	midl Video.idl

register: MyVcr.reg
	regedit /i MyVcr.reg

clean :
	erase Video.h
	erase DllData.c
	erase Video.tlb
	erase Video_i.c
	erase Video_p.c
	erase VcrDLL.obj
	erase Vcr.obj
	erase MyVcr.dll
	erase tv.obj
	erase tv.exe
	erase MyVcr.ilk
	erase MyVcr.pdb
	erase MyVcr.exp
	erase MyVcr.lib
    erase VC60.pdb


