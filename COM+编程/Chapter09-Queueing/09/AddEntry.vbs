Set phoneEntry = GetObject("queue:ComputerName=PVDEV/new:PhoneBook.MyPhoneEntry")
phoneEntry.FirstName = "Pradeep"
phoneEntry.LastName = "Tapadiya"
phoneEntry.PhoneNumber = "(222) 333-4444"
phoneEntry.UpdateWithResponse "ROS84157TAP"
