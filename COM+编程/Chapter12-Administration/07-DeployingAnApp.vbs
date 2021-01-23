
option explicit

' Create the catalog object
Dim catalog
Set catalog = CreateObject("COMAdmin.COMAdminCatalog")
catalog.Connect "pvdc"

' Install the app from the file
catalog.InstallApplication "\\pvdev\MyNetShare\MyApp.MSI"

MsgBox "Done"
