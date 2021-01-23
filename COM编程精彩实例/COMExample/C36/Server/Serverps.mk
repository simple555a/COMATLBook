
Serverps.dll: dlldata.obj Server_p.obj Server_i.obj
	link /dll /out:Serverps.dll /def:Serverps.def /entry:DllMain dlldata.obj Server_p.obj Server_i.obj \
		mtxih.lib mtx.lib mtxguid.lib \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
		ole32.lib advapi32.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		/MD \
		$<

clean:
	@del Serverps.dll
	@del Serverps.lib
	@del Serverps.exp
	@del dlldata.obj
	@del Server_p.obj
	@del Server_i.obj
