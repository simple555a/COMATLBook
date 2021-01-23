
ComponentVCRps.dll: dlldata.obj ComponentVCR_p.obj ComponentVCR_i.obj
	link /dll /out:ComponentVCRps.dll /def:ComponentVCRps.def /entry:DllMain dlldata.obj ComponentVCR_p.obj ComponentVCR_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ComponentVCRps.dll
	@del ComponentVCRps.lib
	@del ComponentVCRps.exp
	@del dlldata.obj
	@del ComponentVCR_p.obj
	@del ComponentVCR_i.obj
