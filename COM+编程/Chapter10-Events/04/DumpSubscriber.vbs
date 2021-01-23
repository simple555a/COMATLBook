option explicit

Dim applicationName 
applicationName = "My Test App"

Dim componentName
componentName = "MySubscriber.MyStockEventSubscriber.1"

' Create the catalog object
Dim catalog
Set catalog = CreateObject("COMAdmin.COMAdminCatalog")

' Get the applications collection
Dim applications
Set applications = catalog.GetCollection("Applications")
applications.Populate

' Get the components collection
Dim components
Set components = GetComponents(applications, applicationName)
' set components = applications.GetCollection("Components", applicationName)
components.Populate

' Get the subscribers list
Dim subscribers
Set subscribers = components.GetCollection("SubscriptionsForComponent", componentName)
subscribers.Populate

Dim subscriber
for each subscriber in subscribers
   DumpSubscriberInfo subscriber
next



sub DumpSubscriberInfo(subscriber)
	Dim subscriberProperties
	subscriberProperties = Array( _
		"Description", _
		"Enabled", _
		"EventCLSID", _
		"FilterCriteria", _
		"ID", _
		"InterfaceID", _
		"MachineName", _
		"MethodName", _
		"Name", _
		"PerUser", _
		"PublisherID", _
		"Queued", _
		"SubscriberMoniker", _
		"UserName")

	Dim i, str
	for i = LBound(subscriberProperties) to UBound(subscriberProperties) - 1
		str = str & subscriberProperties(i) & ": " & subscriber.Value(subscriberProperties(i)) & vbCrLf
	next
	wscript.echo str
end sub

Function GetComponents(applications, applicationName)
	dim i, numPackages
	numPackages = applications.Count
	For i = 0 To (numPackages - 1)
		If applications.Item(i).Value("Name") = applicationName Then
			Set GetComponents = applications.GetCollection("Components", applications.Item(i).Key)
			Exit Function
		End If
	Next
End Function