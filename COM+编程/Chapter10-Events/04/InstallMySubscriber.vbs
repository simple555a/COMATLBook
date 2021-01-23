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
applicationName = "Stock Price Event Subscriber Demo"

Dim componentName
componentName = "MySubscriber.MyStockEventSubscriber.1"

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

' Install a component
catalog.InstallComponent appKey, "E:\Dev\Chapter11-Events\04\MySubscriber\Debug\MySubscriber.dll" , "", ""

Dim components
Set components = applications.GetCollection("Components", appKey)
components.Populate

' Get the subscribers list
Dim subscribers
Set subscribers = components.GetCollection("SubscriptionsForComponent", componentName)
subscribers.Populate

' Add a new subscription
Dim newSubscription
Set newSubscription = subscribers.Add
newSubscription.Value("Name") = "My Subscription"
newSubscription.Value("Enabled") = True
newSubscription.Value("EventCLSID") = "{1F6F353D-5738-4C05-9DA1-A64E19370A0E}"
newSubscription.Value("InterfaceID") = "{A9E6D819-1891-462D-B32C-ED4AFD61B08B}"
newSubscription.Value("PerUser") = False
newSubscription.Value("Queued") = False

' Commit new subscription
subscribers.SaveChanges

MsgBox "Done"
