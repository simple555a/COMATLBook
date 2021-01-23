set StockMgr = CreateObject("StockExchange.StockMgr")
TotalCost = StockMgr.BuyStock("MSFT", 10)
msgbox TotalCost



