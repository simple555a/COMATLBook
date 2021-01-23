
TestCps.dll: dlldata.obj TestC_p.obj TestC_i.obj
	link /dll /out:TestCps.dll /def:TestCps.def /entry:DllMain dlldata.obj TestC_p.obj TestC_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del TestCps.dll
	@del TestCps.lib
	@del TestCps.exp
	@del dlldata.obj
	@del TestC_p.obj
	@del TestC_i.obj
