
JITSvrps.dll: dlldata.obj JITSvr_p.obj JITSvr_i.obj
	link /dll /out:JITSvrps.dll /def:JITSvrps.def /entry:DllMain dlldata.obj JITSvr_p.obj JITSvr_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del JITSvrps.dll
	@del JITSvrps.lib
	@del JITSvrps.exp
	@del dlldata.obj
	@del JITSvr_p.obj
	@del JITSvr_i.obj
