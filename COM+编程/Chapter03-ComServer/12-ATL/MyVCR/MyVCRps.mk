
MyVCRps.dll: dlldata.obj MyVCR_p.obj MyVCR_i.obj
	link /dll /out:MyVCRps.dll /def:MyVCRps.def /entry:DllMain dlldata.obj MyVCR_p.obj MyVCR_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del MyVCRps.dll
	@del MyVCRps.lib
	@del MyVCRps.exp
	@del dlldata.obj
	@del MyVCR_p.obj
	@del MyVCR_i.obj
