
ExploreIDLps.dll: dlldata.obj ExploreIDL_p.obj ExploreIDL_i.obj
	link /dll /out:ExploreIDLps.dll /def:ExploreIDLps.def /entry:DllMain dlldata.obj ExploreIDL_p.obj ExploreIDL_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 
	regsvr32 /s ExploreIDLps.dll

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del ExploreIDLps.dll
	@del ExploreIDLps.lib
	@del ExploreIDLps.exp
	@del dlldata.obj
	@del ExploreIDL_p.obj
	@del ExploreIDL_i.obj
