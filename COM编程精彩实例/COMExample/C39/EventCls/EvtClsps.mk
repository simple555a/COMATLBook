
EvtClsps.dll: dlldata.obj EventCls_p.obj EventCls_i.obj
	link /dll /out:EvtClsps.dll /def:EvtClsps.def /entry:DllMain dlldata.obj EventCls_p.obj EventCls_i.obj \
		mtxih.lib mtx.lib mtxguid.lib \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
		ole32.lib advapi32.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		/MD \
		$<

clean:
	@del EvtClsps.dll
	@del EvtClsps.lib
	@del EvtClsps.exp
	@del dlldata.obj
	@del EventCls_p.obj
	@del EventCls_i.obj
