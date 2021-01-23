
TestBps.dll: dlldata.obj TestB_p.obj TestB_i.obj
	link /dll /out:TestBps.dll /def:TestBps.def /entry:DllMain dlldata.obj TestB_p.obj TestB_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del TestBps.dll
	@del TestBps.lib
	@del TestBps.exp
	@del dlldata.obj
	@del TestB_p.obj
	@del TestB_i.obj
