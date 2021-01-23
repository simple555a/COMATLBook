
Listenerps.dll: dlldata.obj Listener_p.obj Listener_i.obj
	link /dll /out:Listenerps.dll /def:Listenerps.def /entry:DllMain dlldata.obj Listener_p.obj Listener_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del Listenerps.dll
	@del Listenerps.lib
	@del Listenerps.exp
	@del dlldata.obj
	@del Listener_p.obj
	@del Listener_i.obj
