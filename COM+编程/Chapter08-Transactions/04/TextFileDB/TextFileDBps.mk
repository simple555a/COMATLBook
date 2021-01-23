
TextFileDBps.dll: dlldata.obj TextFileDB_p.obj TextFileDB_i.obj
	link /dll /out:TextFileDBps.dll /def:TextFileDBps.def /entry:DllMain dlldata.obj TextFileDB_p.obj TextFileDB_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del TextFileDBps.dll
	@del TextFileDBps.lib
	@del TextFileDBps.exp
	@del dlldata.obj
	@del TextFileDB_p.obj
	@del TextFileDB_i.obj
