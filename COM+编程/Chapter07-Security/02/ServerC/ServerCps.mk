
ServerCps.dll: dlldata.obj ServerC_p.obj ServerC_i.obj
	link /dll /out:ServerCps.dll /def:ServerCps.def /entry:DllMain dlldata.obj ServerC_p.obj ServerC_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ServerCps.dll
	@del ServerCps.lib
	@del ServerCps.exp
	@del dlldata.obj
	@del ServerC_p.obj
	@del ServerC_i.obj
