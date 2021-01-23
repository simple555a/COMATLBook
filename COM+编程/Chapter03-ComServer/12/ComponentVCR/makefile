
ALL: ComponentVcr.dll 

CLFLAGS=-Zi -Od -W4
LINKFLAGS=-Debug

.cpp.obj:
	cl -c $*.cpp $(CLFLAGS)

ComponentVcr.dll : \
	StdAfx.obj \
	ComponentVcrDLL.obj \
	ComponentVcr.obj \
	ComponentVcrClassObject.obj \
	ComponentVcr.def
	link -dll -out:ComponentVcr.dll \
		-def:ComponentVcr.def \
		StdAfx.obj \
		ComponentVcrDLL.obj \
		ComponentVcrClassObject.obj \
		ComponentVcr.obj advapi32.lib $(LINKFLAGS)

ComponentVcr.obj : ComponentVcr.cpp ComponentVcr.h ComponentVideo.h StdAfx.h

ComponentVcrDLL.obj : ComponentVcrDLL.cpp ComponentVcr.h ComponentVideo.h StdAfx.h

ComponentVcrClassObject.obj : ComponentVcrClassObject.cpp ComponentVcr.h ComponentVideo.h StdAfx.h

StdAfx.obj : StdAfx.cpp StdAfx.h MyModule.h

ComponentVideo.h : ComponentVideo.idl
	midl ComponentVideo.idl

clean :
	erase ComponentVideo.h
	erase DllData.c
	erase ComponentVideo.tlb
	erase ComponentVideo_i.c
	erase ComponentVideo_p.c
	erase ComponentVcrDLL.obj
	erase ComponentVcr.obj
	erase ComponentVcr.dll
	erase ComponentVcr.ilk
	erase ComponentVcr.pdb
	erase ComponentVcr.exp
	erase ComponentVcr.lib
	erase ComponentVcrClassObject.obj
    erase VC60.pdb
	erase StdAfx.obj


