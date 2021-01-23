Set aConn = CreateObject("ADODB.Connection")
aConn.Open "Provider=SQLOLEDB;database=AccountsDB;UID=sa;PWD=;"
Set aRS = aConn.Execute("Select Balance from Accounts")
MsgBox aRS("Balance")



