set TradeMgr = CreateObject("TradeMgmt.TradeMgr")
TradeMgr.BuyStocks "Don", "INTC", 100
msgbox "Don"
TradeMgr.BuyStocks "Chris", "MSFT", 1000
msgbox "Chris"