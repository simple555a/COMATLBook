option explicit

Function CreateApplication(catalog, applications, applicationName)

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

	' Commit new application and refresh the list once again
	applications.SaveChanges
	applications.Populate

	numPackages = applications.Count
	For i = 0 To (numPackages - 1)
		If applications.Item(i).Value("Name") = applicationName Then
			Set CreateApplication = applications.Item(i)
			Exit Function
		End If
	Next
End Function


Dim applicationName 
applicationName = "Stock Price Event Demo"

' Create the catalog object
Dim catalog
Set catalog = CreateObject("COMAdmin.COMAdminCatalog")

' Get the applications collection
Dim applications
Set applications = catalog.GetCollection("Applications")
applications.Populate

' Create a new application
Dim application, appKey
Set application = CreateApplication(catalog, applications, applicationName)
appKey = application.Value("ID")

' Install the event class in the application
catalog.InstallEventClass appKey, ".\StockPrice\Debug\StockPrice.dll", "", ""

Dim components
Set components = applications.GetCollection("Components", appKey)
components.Populate

Dim component
for each component in components
   if component.Value("ProgID") = "StockPrice.MyStockPriceEvent.1" then
	component.Value("MultiInterfacePublisherFilterCLSID") = "{7F90EF4A-549C-4D55-8F00-C274456B1075}"
   end if
next
components.SaveChanges

MsgBox "Done"
