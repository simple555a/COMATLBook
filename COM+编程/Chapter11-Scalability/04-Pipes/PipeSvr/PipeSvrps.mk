
PipeSvrps.dll: dlldata.obj PipeSvr_p.obj PipeSvr_i.obj
	link /dll /out:PipeSvrps.dll /def:PipeSvrps.def /entry:DllMain dlldata.obj PipeSvr_p.obj PipeSvr_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del PipeSvrps.dll
	@del PipeSvrps.lib
	@del PipeSvrps.exp
	@del dlldata.obj
	@del PipeSvr_p.obj
	@del PipeSvr_i.obj
