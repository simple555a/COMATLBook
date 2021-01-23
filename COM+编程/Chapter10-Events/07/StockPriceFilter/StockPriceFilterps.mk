
StockPriceFilterps.dll: dlldata.obj StockPriceFilter_p.obj StockPriceFilter_i.obj
	link /dll /out:StockPriceFilterps.dll /def:StockPriceFilterps.def /entry:DllMain dlldata.obj StockPriceFilter_p.obj StockPriceFilter_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del StockPriceFilterps.dll
	@del StockPriceFilterps.lib
	@del StockPriceFilterps.exp
	@del dlldata.obj
	@del StockPriceFilter_p.obj
	@del StockPriceFilter_i.obj
