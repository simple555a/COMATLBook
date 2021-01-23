
ColSrvps.dll: dlldata.obj CollSrv_p.obj CollSrv_i.obj
	link /dll /out:ColSrvps.dll /def:ColSrvps.def /entry:DllMain dlldata.obj CollSrv_p.obj CollSrv_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ColSrvps.dll
	@del ColSrvps.lib
	@del ColSrvps.exp
	@del dlldata.obj
	@del CollSrv_p.obj
	@del CollSrv_i.obj
