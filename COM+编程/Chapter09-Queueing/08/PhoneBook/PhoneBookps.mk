
PhoneBookps.dll: dlldata.obj PhoneBook_p.obj PhoneBook_i.obj
	link /dll /out:PhoneBookps.dll /def:PhoneBookps.def /entry:DllMain dlldata.obj PhoneBook_p.obj PhoneBook_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del PhoneBookps.dll
	@del PhoneBookps.lib
	@del PhoneBookps.exp
	@del dlldata.obj
	@del PhoneBook_p.obj
	@del PhoneBook_i.obj
