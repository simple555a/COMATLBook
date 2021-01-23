
set qi = CreateObject ("MSMQ.MSMQQueueInfo")

' Set Queue Information
qi.PathName = ".\PRIVATE$\TestQueue"
qi.Label = "Test Queue"

' Create the queue
qi.Create

' Display the format name for the newly created queue
msgbox qi.FormatName

