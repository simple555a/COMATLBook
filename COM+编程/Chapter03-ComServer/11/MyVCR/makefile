
ALL: MyVcr.dll 

CLFLAGS=-Zi -Od -W4
LINKFLAGS=-Debug

.cpp.obj:
	cl -c $*.cpp $(CLFLAGS)

MyVcr.dll : StdAfx.obj VcrDLL.obj Vcr.obj ClassObject.obj Vcr.def
	link -dll -out:MyVcr.dll -def:Vcr.def StdAfx.obj VcrDLL.obj ClassObject.obj Vcr.obj advapi32.lib ole32.lib $(LINKFLAGS)

Vcr.obj : Vcr.cpp Vcr.h Video.h StdAfx.h

VcrDLL.obj : VcrDLL.cpp Vcr.h Video.h StdAfx.h

ClassObject.obj : ClassObject.cpp Vcr.h Video.h StdAfx.h

StdAfx.obj : StdAfx.cpp StdAfx.h MyModule.h

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
	erase MyVcr.ilk
	erase MyVcr.pdb
	erase MyVcr.exp
	erase MyVcr.lib
	erase ClassObject.obj
    erase VC60.pdb
	erase StdAfx.obj


