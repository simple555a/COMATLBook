Set aConn = CreateObject("ADODB.Connection")
aConn.Open "DSN=LocalServer;database=AccountsDB;UID=sa;PWD=;"
Set aRS = aConn.Execute("Select Balance from Accounts")
MsgBox aRS("Balance")


