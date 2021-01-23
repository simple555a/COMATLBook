
serverps.dll: dlldata.obj server_p.obj server_i.obj
	link /dll /out:serverps.dll /def:serverps.def /entry:DllMain dlldata.obj server_p.obj server_i.obj \
		mtxih.lib mtx.lib mtxguid.lib \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
		ole32.lib advapi32.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		/MD \
		$<

clean:
	@del serverps.dll
	@del serverps.lib
	@del serverps.exp
	@del dlldata.obj
	@del server_p.obj
	@del server_i.obj
