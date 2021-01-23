
SyncTestps.dll: dlldata.obj SyncTest_p.obj SyncTest_i.obj
	link /dll /out:SyncTestps.dll /def:SyncTestps.def /entry:DllMain dlldata.obj SyncTest_p.obj SyncTest_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del SyncTestps.dll
	@del SyncTestps.lib
	@del SyncTestps.exp
	@del dlldata.obj
	@del SyncTest_p.obj
	@del SyncTest_i.obj
