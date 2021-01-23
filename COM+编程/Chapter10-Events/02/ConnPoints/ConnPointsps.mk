
ConnPointsps.dll: dlldata.obj ConnPoints_p.obj ConnPoints_i.obj
	link /dll /out:ConnPointsps.dll /def:ConnPointsps.def /entry:DllMain dlldata.obj ConnPoints_p.obj ConnPoints_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ConnPointsps.dll
	@del ConnPointsps.lib
	@del ConnPointsps.exp
	@del dlldata.obj
	@del ConnPoints_p.obj
	@del ConnPoints_i.obj
