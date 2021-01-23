	option explicit
	Dim MyRequestEvent, MyQueueInfo, MyRequestQueue

	Sub MyStartButton_onclick
		set MyRequestEvent = WScript.CreateObject("MSMQ.MSMQEvent", "MyRequestEvent_")
		set MyQueueInfo = CreateObject("MSMQ.MSMQQueueInfo")
		MyQueueInfo.PathName = ".\MyPubQueue"
		Set MyRequestQueue = MyQueueInfo.Open(1, 0)
		MyRequestQueue.EnableNotification MyRequestEvent
	End Sub

	Sub MyRequestEvent_Arrived(ByVal queue, ByVal Cursor)
		Dim MyMsg
		Set MyMsg = queue.Receive(0)
		if Not (MyMsg is Nothing) then
			MsgBox MyMsg.Body
		end if
		queue.EnableNotification MyRequestEvent
	End Sub

	call MyStartButton_onclick
	Msgbox "Waiting"

