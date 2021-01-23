
AggSvrps.dll: dlldata.obj AggSvr_p.obj AggSvr_i.obj
	link /dll /out:AggSvrps.dll /def:AggSvrps.def /entry:DllMain dlldata.obj AggSvr_p.obj AggSvr_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del AggSvrps.dll
	@del AggSvrps.lib
	@del AggSvrps.exp
	@del dlldata.obj
	@del AggSvr_p.obj
	@del AggSvr_i.obj
