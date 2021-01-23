Set stockPriceEvent = GetObject("queue:ComputerName=PVDEV/new:StockPrice.MyStockPriceEvent")
stockPriceEvent.NewQuote "MSFT", 100.0
stockPriceEvent = NULL

msgbox "Done"


