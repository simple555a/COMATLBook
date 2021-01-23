
SingletonExampleps.dll: dlldata.obj SingletonExample_p.obj SingletonExample_i.obj
	link /dll /out:SingletonExampleps.dll /def:SingletonExampleps.def /entry:DllMain dlldata.obj SingletonExample_p.obj SingletonExample_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del SingletonExampleps.dll
	@del SingletonExampleps.lib
	@del SingletonExampleps.exp
	@del dlldata.obj
	@del SingletonExample_p.obj
	@del SingletonExample_i.obj
