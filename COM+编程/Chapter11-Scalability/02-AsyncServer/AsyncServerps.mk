
AsyncServerps.dll: dlldata.obj AsyncServer_p.obj AsyncServer_i.obj
	link /dll /out:AsyncServerps.dll /def:AsyncServerps.def /entry:DllMain dlldata.obj AsyncServer_p.obj AsyncServer_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0500 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del AsyncServerps.dll
	@del AsyncServerps.lib
	@del AsyncServerps.exp
	@del dlldata.obj
	@del AsyncServer_p.obj
	@del AsyncServer_i.obj
