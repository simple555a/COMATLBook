
WzdSrvps.dll: dlldata.obj WzdSrv_p.obj WzdSrv_i.obj
	link /dll /out:WzdSrvps.dll /def:WzdSrvps.def /entry:DllMain dlldata.obj WzdSrv_p.obj WzdSrv_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del WzdSrvps.dll
	@del WzdSrvps.lib
	@del WzdSrvps.exp
	@del dlldata.obj
	@del WzdSrv_p.obj
	@del WzdSrv_i.obj
