
ServerBps.dll: dlldata.obj ServerB_p.obj ServerB_i.obj
	link /dll /out:ServerBps.dll /def:ServerBps.def /entry:DllMain dlldata.obj ServerB_p.obj ServerB_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ServerBps.dll
	@del ServerBps.lib
	@del ServerBps.exp
	@del dlldata.obj
	@del ServerB_p.obj
	@del ServerB_i.obj
