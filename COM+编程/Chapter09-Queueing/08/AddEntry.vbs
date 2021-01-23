' Set phoneEntry = CreateObject("PhoneBook.MyPhoneEntry")
Set phoneEntry = GetObject("queue:ComputerName=PVDEV/new:PhoneBook.MyPhoneEntry")
phoneEntry.FirstName = "Pradeep"
phoneEntry.LastName = "Tapadiya"
phoneEntry.PhoneNumber = "(222) 333-4444"
phoneEntry.Update
MsgBox "Added a new person to the hit-list"
