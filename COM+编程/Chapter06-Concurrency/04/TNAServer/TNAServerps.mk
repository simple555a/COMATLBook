
TNAServerps.dll: dlldata.obj TNAServer_p.obj TNAServer_i.obj
	link /dll /out:TNAServerps.dll /def:TNAServerps.def /entry:DllMain dlldata.obj TNAServer_p.obj TNAServer_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del TNAServerps.dll
	@del TNAServerps.lib
	@del TNAServerps.exp
	@del dlldata.obj
	@del TNAServer_p.obj
	@del TNAServer_i.obj
