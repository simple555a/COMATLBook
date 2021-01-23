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
      Top             =   3720
      Width           =   2415
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Test"
      Height          =   1215
      Left            =   1920
      TabIndex        =   0
      Top             =   2280
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
    Dim cArg As Byte
    Dim sArg As Integer
    Dim lArg As Long
    Dim fArg As Single
    Dim dArg As Double
    Dim tArg As String
    Dim aArg(1 To 25) As Byte
    Dim aArgx() As Byte
    Dim vArg2 As Variant
    Dim vArg3 As Variant
    
    ' simple data
    cArg = 12
    sArg = 1234
    lArg = 1234567890
    fArg = 1.234
    dArg = 1.23456789
    rval = IWzdSrv.Simple1(cArg, sArg, lArg)
    rval = IWzdSrv.Simple2(fArg, dArg)
    
    ' strings (BSTR in C++)
    tArg = "Test"
    rval = IWzdSrv.VBVars1(tArg)
    
    ' arrays (SAFEARRAY in C++)
    aArg(1) = 2
    rval = IWzdSrv.VBVars2(aArg)
    
    ' variants
    vArg2 = tArg
    vArg3 = aArg
    rval = IWzdSrv.VBVars3(1234, vArg2, vArg3)
    tArg = vArg2
    ' NOTE: VB limitation prevents returning array back to original w/o a lot of work
    aArgx = vArg3
    
End Sub

Private Sub Command2_Click()
    End
End Sub
