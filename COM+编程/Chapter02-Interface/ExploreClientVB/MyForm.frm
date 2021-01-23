VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Test IDL"
   ClientHeight    =   3195
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   4680
   LinkTopic       =   "Form1"
   ScaleHeight     =   3195
   ScaleWidth      =   4680
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton OK 
      Caption         =   "OK"
      Height          =   615
      Left            =   1560
      TabIndex        =   0
      Top             =   1320
      Width           =   1335
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub OK_Click()
Dim x As New EXPLOREIDLLib.MyExplore
Dim y As Long

y = x.GetRandomValue
y = y + 10
MsgBox y
End Sub
