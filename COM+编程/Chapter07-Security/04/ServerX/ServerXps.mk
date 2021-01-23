
ServerXps.dll: dlldata.obj ServerX_p.obj ServerX_i.obj
	link /dll /out:ServerXps.dll /def:ServerXps.def /entry:DllMain dlldata.obj ServerX_p.obj ServerX_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ServerXps.dll
	@del ServerXps.lib
	@del ServerXps.exp
	@del dlldata.obj
	@del ServerX_p.obj
	@del ServerX_i.obj
