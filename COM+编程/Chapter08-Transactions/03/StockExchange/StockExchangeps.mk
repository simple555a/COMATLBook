
StockExchangeps.dll: dlldata.obj StockExchange_p.obj StockExchange_i.obj
	link /dll /out:StockExchangeps.dll /def:StockExchangeps.def /entry:DllMain dlldata.obj StockExchange_p.obj StockExchange_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del StockExchangeps.dll
	@del StockExchangeps.lib
	@del StockExchangeps.exp
	@del dlldata.obj
	@del StockExchange_p.obj
	@del StockExchange_i.obj
