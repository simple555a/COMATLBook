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
   Begin VB.PictureBox Server1 
      Height          =   1575
      Left            =   1920
      ScaleHeight     =   1515
      ScaleWidth      =   2355
      TabIndex        =   2
      Top             =   1920
      Width           =   2415
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Dismiss"
      Height          =   735
      Left            =   1920
      TabIndex        =   0
      Top             =   3720
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
    Dim IWzdSrv1 As New SERVERLib.Wzd
    IWzdSrv1.Method1 (1234)
        
    ' if IWzdSrv's object type isn't known initially
    Dim IWzdSrv2 As Object
    Set IWzdSrv2 = New SERVERLib.Wzd
    IWzdSrv2.Method1 (4321)
    
    ' to create from a ProgID
    Dim IWzdSrv3 As Object
    Set IWzdSrv3 = CreateObject("Server.Wzd")
    IWzdSrv3.Method1 (9876)
    

End Sub

Private Sub Command2_Click()
    End
End Sub
