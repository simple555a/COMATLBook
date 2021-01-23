VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   4785
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   6240
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   12
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "Form1"
   ScaleHeight     =   4785
   ScaleWidth      =   6240
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command2 
      Caption         =   "Dismiss"
      Height          =   735
      Left            =   1920
      TabIndex        =   1
      Top             =   3600
      Width           =   2415
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Test"
      Height          =   1215
      Left            =   1920
      TabIndex        =   0
      Top             =   2160
      Width           =   2415
   End
   Begin VB.Label Label1 
      Caption         =   $"Tester.frx":0000
      Height          =   1815
      Left            =   240
      TabIndex        =   2
      Top             =   120
      Width           =   5775
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
    Dim IWzdSrv As Object
    Set IWzdSrv = CreateObject("Server.Wzd")
    Dim rVal As Integer
    Dim MyCollection As WzdCollection
    Dim MyObject
    Dim MyNewObject

    rVal = IWzdSrv.GetCollection(MyCollection)
             
    MyObject = MyCollection.Item(0)

    For Each MyObject In MyCollection
        MyNewObject = MyObject
    Next
End Sub

Private Sub Command2_Click()
    End
End Sub
