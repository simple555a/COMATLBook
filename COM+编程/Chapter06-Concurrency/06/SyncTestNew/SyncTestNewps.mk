
SyncTestNewps.dll: dlldata.obj SyncTestNew_p.obj SyncTestNew_i.obj
	link /dll /out:SyncTestNewps.dll /def:SyncTestNewps.def /entry:DllMain dlldata.obj SyncTestNew_p.obj SyncTestNew_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del SyncTestNewps.dll
	@del SyncTestNewps.lib
	@del SyncTestNewps.exp
	@del dlldata.obj
	@del SyncTestNew_p.obj
	@del SyncTestNew_i.obj
