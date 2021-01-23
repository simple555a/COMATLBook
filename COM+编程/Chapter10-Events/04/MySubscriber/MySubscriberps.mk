
MySubscriberps.dll: dlldata.obj MySubscriber_p.obj MySubscriber_i.obj
	link /dll /out:MySubscriberps.dll /def:MySubscriberps.def /entry:DllMain dlldata.obj MySubscriber_p.obj MySubscriber_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del MySubscriberps.dll
	@del MySubscriberps.lib
	@del MySubscriberps.exp
	@del dlldata.obj
	@del MySubscriber_p.obj
	@del MySubscriber_i.obj
