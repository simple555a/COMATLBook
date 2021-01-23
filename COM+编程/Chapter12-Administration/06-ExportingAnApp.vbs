
option explicit

Dim applicationName 
applicationName = "My Test Application"

' Create the catalog object
Dim catalog
Set catalog = CreateObject("COMAdmin.COMAdminCatalog")

' Export the app to a file
catalog.ExportApplication applicationName,  ".\MyApp.MSI", 0

MsgBox "Done"
