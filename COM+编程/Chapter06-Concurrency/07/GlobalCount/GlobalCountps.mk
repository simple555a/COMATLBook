
GlobalCountps.dll: dlldata.obj GlobalCount_p.obj GlobalCount_i.obj
	link /dll /out:GlobalCountps.dll /def:GlobalCountps.def /entry:DllMain dlldata.obj GlobalCount_p.obj GlobalCount_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del GlobalCountps.dll
	@del GlobalCountps.lib
	@del GlobalCountps.exp
	@del dlldata.obj
	@del GlobalCount_p.obj
	@del GlobalCount_i.obj
