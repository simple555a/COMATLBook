Videops.dll: DllData.obj Video_p.obj Video_i.obj
	link /dll /out:Videops.dll /def:Videops.def /entry:DllMain DllData.obj Video_p.obj Video_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del Videops.dll
	@del Videops.lib
	@del Videops.exp
	@del DllData.obj
	@del Video_p.obj
	@del Video_i.obj
