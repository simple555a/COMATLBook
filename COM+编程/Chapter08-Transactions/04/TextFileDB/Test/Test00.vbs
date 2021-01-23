Set fileDB = CreateObject("TextFileDB.MyFileDB")
fileDB.Open("E:\Dev\Chapter08-Transactions\04\TextFileDB\Test\Accounts.txt")
lBalance = fileDB.GetBalance("Don")
msgbox lBalance
fileDB.UpdateBalance "Don", 50000
msgbox "Done"

