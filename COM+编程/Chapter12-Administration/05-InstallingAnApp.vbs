
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

' Add the new appliction
Dim newApplication
Set newApplication = applications.Add
newApplication.Value("Name") = applicationName
newApplication.Value("Activation") = 0 ' Inproc=0, Local=1

' Commit new application and reload the list
applications.SaveChanges
applications.Populate

' Get the application key
dim appKey
numPackages = applications.Count
For i = 0 To (numPackages - 1)
	If applications.Item(i).Value("Name") = applicationName Then
		appKey = applications.Item(i).Key
	End If
Next

' Add a role called "Managers"
Dim roles
Set roles = applications.GetCollection("Roles", appKey)
roles.populate

Dim newRole
Set newRole = roles.Add
newRole.Value("Name") = "Managers"
roles.SaveChanges

' Install a component
' catalog.InstallComponent appKey, "E:\Dev\Chapter06-Concurrency\05\MTAServer\Debug\MTAServer.dll" , "", ""
catalog.InstallComponent applicationName, "D:\Pradeep\Com+\Dev\Chapter08-Transactions\05\AccountMgmt\Debug\AccountMgmt.dll", "", ""


Dim components
Set components = applications.GetCollection("Components", appKey)
components.Populate

dim numComponents
numComponents = components.Count
for i = numComponents-1 to 0 step -1
	if components.Item(i).Value("ProgID") = "MTAServer.MyTest.1" then
		components.Item(i).Value("Synchronization") = 3
		components.Item(i).Value("Transaction") = 3
		components.Item(i).Value("JustInTimeActivation") = true
	end if
next
components.SaveChanges

MsgBox "Done"
