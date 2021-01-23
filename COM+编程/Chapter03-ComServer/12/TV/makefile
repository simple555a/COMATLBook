
ALL: TV.exe

CLFLAGS=-Zi -Od -W4
LINKFLAGS=-Debug

.cpp.obj:
	cl -c $*.cpp $(CLFLAGS)

tv.exe : tv.obj
	link tv.obj ole32.lib $(LINKFLAGS)
	
clean :
	erase tv.obj
	erase tv.exe
	erase *.pdb
