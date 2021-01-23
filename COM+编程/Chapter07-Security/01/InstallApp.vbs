
option explicit

Dim applicationName 
applicationName = "My Salary Application"

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
newApplication.Value("Activation") = 1 ' Inproc=0, Local=1

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

' Add two roles - "Managers" and "Employees"
Dim roles
Set roles = applications.GetCollection("Roles", appKey)
roles.populate

Dim newRole
Set newRole = roles.Add
newRole.Value("Name") = "Managers"
Set newRole = roles.Add
newRole.Value("Name") = "Employees"
roles.SaveChanges

' Install a component
catalog.InstallComponent appKey, ".\MyCompanySalary\Debug\MyCompanySalary.dll" , "", ""

MsgBox "Done"
