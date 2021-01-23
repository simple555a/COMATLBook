IFACE = IWzdAgg

$(IFACE).dll: dlldata.obj $(IFACE)_p.obj $(IFACE)_i.obj
	link /dll /out:$(IFACE).dll /def:$(IFACE).def /entry:DllMain dlldata.obj $(IFACE)_p.obj \
	 $(IFACE)_i.obj kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib 
	regsvr32 /s $(IFACE).dll

dlldata.c $(IFACE)_p.c $(IFACE)_i.c $(IFACE).h : $(IFACE).idl
	midl $(IFACE).idl

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<

clean:
	@del $(IFACE).dll
	@del $(IFACE).lib
	@del $(IFACE).exp
	@del dlldata.obj
	@del $(IFACE)_p.obj
	@del $(IFACE)_i.obj
