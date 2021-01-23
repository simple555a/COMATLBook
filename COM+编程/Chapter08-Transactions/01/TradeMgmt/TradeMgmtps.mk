
TradeMgmtps.dll: dlldata.obj TradeMgmt_p.obj TradeMgmt_i.obj
	link /dll /out:TradeMgmtps.dll /def:TradeMgmtps.def /entry:DllMain dlldata.obj TradeMgmt_p.obj TradeMgmt_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del TradeMgmtps.dll
	@del TradeMgmtps.lib
	@del TradeMgmtps.exp
	@del dlldata.obj
	@del TradeMgmt_p.obj
	@del TradeMgmt_i.obj
