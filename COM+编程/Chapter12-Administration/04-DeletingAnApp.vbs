
option explicit

Dim applicationName 
applicationName = "My Test Application"

' Create the catalog object
Dim catalog
Set catalog = CreateObject("COMAdmin.COMAdminCatalog")

' Get the applications collection
Dim applications
Set applications = catalog.GetCollection("Applications")
applications.Populate

' Remove any applications that has the same name as the new one
Dim i, numPackages, bChanged
bChanged = False
numPackages = applications.Count
For i = numPackages - 1 To 0 Step -1
	If applications.Item(i).Value("Name") = applicationName Then
		applications.Remove (i)
		bChanged = True
	End If
Next

' Commit our deletions
If (bChanged = true) Then
	applications.SaveChanges
End If

MsgBox "Done"
