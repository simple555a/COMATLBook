VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "Class1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
Attribute VB_Ext_KEY = "Member0" ,"Class2"
'local variable(s) to hold property value(s)
Private mvarProperty1 As Long 'local copy
'To fire this event, use RaiseEvent with the following syntax:
'RaiseEvent Event1[(arg1, arg2, ... , argn)]
Public Event Event1(lArg As Integer)
Private mvarClass2 As Class2


Public Property Get Class2() As Class2
    Set Class2 = mvarClass2
End Property


Public Property Set Class2(vData As Class2)
    Set mvarClass2 = vData
End Property

Public Property Let Property1(ByVal vData As Long)
'used when assigning a value to the property, on the left side of an assignment.
'Syntax: X.Property1 = 5
    mvarProperty1 = vData
End Property


Public Property Get Property1() As Long
'used when retrieving value of a property, on the right side of an assignment.
'Syntax: Debug.Print X.Property1
    Property1 = mvarProperty1
End Property



Public Sub Method1(lArg As Long)
    Val1 = 1234
End Sub

Private Sub Class_Initialize()

  'create the mClass2 object when the Class1 class is created
  Set mvarClass2 = New Class2
End Sub

Private Sub Class_Terminate()
  Set mvarClass2 = Nothing

End Sub
