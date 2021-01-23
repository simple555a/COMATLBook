
ALL: TV.exe

CLFLAGS=-Zi -Od -W4
LINKFLAGS=-Debug

.cpp.obj:
	cl -c $*.cpp $(CLFLAGS)

tv.exe : tv.cpp
	cl tv.cpp ole32.lib
	
clean :
	erase tv.obj
	erase tv.exe
