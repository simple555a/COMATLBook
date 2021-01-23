
StockPriceps.dll: dlldata.obj StockPrice_p.obj StockPrice_i.obj
	link /dll /out:StockPriceps.dll /def:StockPriceps.def /entry:DllMain dlldata.obj StockPrice_p.obj StockPrice_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del StockPriceps.dll
	@del StockPriceps.lib
	@del StockPriceps.exp
	@del dlldata.obj
	@del StockPrice_p.obj
	@del StockPrice_i.obj
