
TestDps.dll: dlldata.obj TestD_p.obj TestD_i.obj
	link /dll /out:TestDps.dll /def:TestDps.def /entry:DllMain dlldata.obj TestD_p.obj TestD_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del TestDps.dll
	@del TestDps.lib
	@del TestDps.exp
	@del dlldata.obj
	@del TestD_p.obj
	@del TestD_i.obj
