
TestObjectConstructps.dll: dlldata.obj TestObjectConstruct_p.obj TestObjectConstruct_i.obj
	link /dll /out:TestObjectConstructps.dll /def:TestObjectConstructps.def /entry:DllMain dlldata.obj TestObjectConstruct_p.obj TestObjectConstruct_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del TestObjectConstructps.dll
	@del TestObjectConstructps.lib
	@del TestObjectConstructps.exp
	@del dlldata.obj
	@del TestObjectConstruct_p.obj
	@del TestObjectConstruct_i.obj
