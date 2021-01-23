
AsyncServer2ps.dll: dlldata.obj AsyncServer2_p.obj AsyncServer2_i.obj
	link /dll /out:AsyncServer2ps.dll /def:AsyncServer2ps.def /entry:DllMain dlldata.obj AsyncServer2_p.obj AsyncServer2_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0500 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del AsyncServer2ps.dll
	@del AsyncServer2ps.lib
	@del AsyncServer2ps.exp
	@del dlldata.obj
	@del AsyncServer2_p.obj
	@del AsyncServer2_i.obj
