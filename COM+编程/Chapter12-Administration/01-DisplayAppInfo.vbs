'***************************************************************
'
' Display information on each application on the system
'
'***************************************************************

' Instantiate a COMAdminCatalog object
Set Catalog = CreateObject("ComAdmin.COMAdminCatalog")

' Get the "Applications" collection and populate it
set Applications = Catalog.GetCollection("Applications")
Applications.Populate

' Display the name of each application
for each AppObject in Applications
	DispString = AppObject.Name & " " & AppObject.Key
	if AppObject.Value("Activation") = 0 then
		DispString = DispString & " - INPROC"
	else
		DispString = DispString & " - LOCAL"
	end if
	wscript.Echo DispString
next


