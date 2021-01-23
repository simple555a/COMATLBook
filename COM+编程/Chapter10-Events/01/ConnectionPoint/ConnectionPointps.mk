
ConnectionPointps.dll: dlldata.obj ConnectionPoint_p.obj ConnectionPoint_i.obj
	link /dll /out:ConnectionPointps.dll /def:ConnectionPointps.def /entry:DllMain dlldata.obj ConnectionPoint_p.obj ConnectionPoint_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ConnectionPointps.dll
	@del ConnectionPointps.lib
	@del ConnectionPointps.exp
	@del dlldata.obj
	@del ConnectionPoint_p.obj
	@del ConnectionPoint_i.obj
