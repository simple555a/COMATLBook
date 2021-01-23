option explicit

Dim txCtx
Set txCtx = _
    CreateObject("TxCtx.TransactionContext")

Dim sConnection, sUser
sConnection = "provider=sqloledb;database=AccountsDB"
sUser = "sa"

Dim aConn
Set aConn = txCtx.CreateInstance("ADODB.Connection")
aConn.Open sConnection, sUser

Dim sCmd
sCmd = "UPDATE Accounts SET Balance=Balance-1000 " _
    &  "WHERE [Client] = 'Don'"

aConn.Execute sCmd

txCtx.Abort

msgbox "Done"
