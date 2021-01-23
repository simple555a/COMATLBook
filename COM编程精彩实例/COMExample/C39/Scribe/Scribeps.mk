
Scribeps.dll: dlldata.obj Scribe_p.obj Scribe_i.obj
	link /dll /out:Scribeps.dll /def:Scribeps.def /entry:DllMain dlldata.obj Scribe_p.obj Scribe_i.obj \
		mtxih.lib mtx.lib mtxguid.lib \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \
		ole32.lib advapi32.lib 

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		/MD \
		$<

clean:
	@del Scribeps.dll
	@del Scribeps.lib
	@del Scribeps.exp
	@del dlldata.obj
	@del Scribe_p.obj
	@del Scribe_i.obj
