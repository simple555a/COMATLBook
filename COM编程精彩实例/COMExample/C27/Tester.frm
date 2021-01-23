VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   5205
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
   ScaleHeight     =   5205
   ScaleWidth      =   6240
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "Test"
      Height          =   1695
      Left            =   1800
      TabIndex        =   2
      Top             =   2040
      Width           =   2535
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Dismiss"
      Height          =   735
      Left            =   1800
      TabIndex        =   0
      Top             =   3960
      Width           =   2415
   End
   Begin VB.Label Label1 
      Caption         =   $"Tester.frx":0000
      Height          =   1575
      Left            =   240
      TabIndex        =   1
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
    ' most efficient--can use dispatch id's directly
    Dim wzdClass1 As New Server.Class1
    Dim wzdClass2 As New Server.Class2
    Dim wzdClass3 As New Server.Class3
    
    wzdClass1.Method1 (1234)
    wzdClass2.Method2
    wzdClass3.Method3
    
End Sub

Private Sub Command2_Click()
    End
End Sub
