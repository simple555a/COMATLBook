
ActivityTestps.dll: dlldata.obj ActivityTest_p.obj ActivityTest_i.obj
	link -DEBUG /dll /out:ActivityTestps.dll /def:ActivityTestps.def /entry:DllMain dlldata.obj ActivityTest_p.obj ActivityTest_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c -Zi -Od  /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ActivityTestps.dll
	@del ActivityTestps.lib
	@del ActivityTestps.exp
	@del dlldata.obj
	@del ActivityTest_p.obj
	@del ActivityTest_i.obj
