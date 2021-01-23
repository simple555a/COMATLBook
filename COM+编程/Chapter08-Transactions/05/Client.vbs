option explicit

Dim txCtx
Set txCtx = _
    CreateObject("TxCtx.TransactionContext")

Dim Accounts
set Accounts = txCtx.CreateInstance("AccountMgmt.AccountMgr")
Accounts.Debit "Don", 10

txCtx.Commit

msgbox "Done"
