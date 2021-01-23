Set fileDB = CreateObject("TextFileDB.MyFileDB")
fileDB.Open("E:\Dev\Chapter08-Transactions\04\TextFileDB\Test\Accounts.txt")
fileDB.UpdateBalance "Unknown", 50000
msgbox "Done"

