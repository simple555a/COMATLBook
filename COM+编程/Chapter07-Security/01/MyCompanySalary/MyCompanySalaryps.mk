
MyCompanySalaryps.dll: dlldata.obj MyCompanySalary_p.obj MyCompanySalary_i.obj
	link /dll /out:MyCompanySalaryps.dll /def:MyCompanySalaryps.def /entry:DllMain dlldata.obj MyCompanySalary_p.obj MyCompanySalary_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del MyCompanySalaryps.dll
	@del MyCompanySalaryps.lib
	@del MyCompanySalaryps.exp
	@del dlldata.obj
	@del MyCompanySalary_p.obj
	@del MyCompanySalary_i.obj
