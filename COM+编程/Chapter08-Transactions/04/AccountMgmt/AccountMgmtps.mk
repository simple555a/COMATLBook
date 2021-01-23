
AccountMgmtps.dll: dlldata.obj AccountMgmt_p.obj AccountMgmt_i.obj
	link /dll /out:AccountMgmtps.dll /def:AccountMgmtps.def /entry:DllMain dlldata.obj AccountMgmt_p.obj AccountMgmt_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del AccountMgmtps.dll
	@del AccountMgmtps.lib
	@del AccountMgmtps.exp
	@del dlldata.obj
	@del AccountMgmt_p.obj
	@del AccountMgmt_i.obj
