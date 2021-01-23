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
      Top             =   3360
      Width           =   2415
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Test"
      Height          =   1215
      Left            =   1920
      TabIndex        =   0
      Top             =   1920
      Width           =   2415
   End
   Begin VB.Label Label1 
      Caption         =   $"Tester.frx":0000
      Height          =   1575
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
Dim cn As New ADODB.Connection
Dim cmd As New ADODB.Command
Dim rs As New ADODB.Recordset
Dim prm As ADODB.Parameter
On Error GoTo AdoError
'//////////////////////////////////////////////////////////////////////////
'////////////////     OPEN THE DATABASE    ////////////////////////////////
'//////////////////////////////////////////////////////////////////////////
    cn.ConnectionTimeout = 1000
' parameters are: connection string, user id, password,
    cn.Open "WZDDB", "", "", adCmdUnspecified
' initialize command object
    Set cmd.ActiveConnection = cn
  
'//////////////////////////////////////////////////////////////////////////
'////////////////     GET A RECORD SET (w/SQL)  ///////////////////////////
'//////////////////////////////////////////////////////////////////////////
' open record set
    rs.Open "SELECT * FROM CUSTOMERS", cn, adOpenForwardOnly, adLockPessimistic
    
   
'//////////////////////////////////////////////////////////////////////////
'////////////////  SCROLL THROUGH RECORDSET (COLUMNS & ROWS) //////////////
'//////////////////////////////////////////////////////////////////////////
    While (Not rs.EOF)
        CustomerID = rs("CustomerID")
        CompanyName = rs("CompanyName")
        ContactName = rs("ContactName")
        rs.MoveNext
    Wend
    rs.MoveFirst

'//////////////////////////////////////////////////////////////////////////
'////////////////  ADD A RECORD TO A DATABASE /////////////////////////////
'//////////////////////////////////////////////////////////////////////////
    rs.AddNew
    rs("CustomerID") = "BONCO"
    rs("CompanyName") = "Franks"
    rs("ContactName") = "Runk"
    rs.Update

'//////////////////////////////////////////////////////////////////////////
'////////////////  EDIT A RECORD IN A DATABASE /////////////////////////////
'//////////////////////////////////////////////////////////////////////////
' (edits the current record)
    rs(2) = "Smith"
    rs.Update

'//////////////////////////////////////////////////////////////////////////
'////////////////  DELETE A RECORD FROM THE DATABASE //////////////////////
'//////////////////////////////////////////////////////////////////////////
' (deletes the current record)
    rs.Delete

'//////////////////////////////////////////////////////////////////////////
'////////////////  CLOSE RECORDSET ////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////
    rs.Close
    
'//////////////////////////////////////////////////////////////////////////
'////////////////  EXECUTE A STORED PROCEDURE /////////////////////////////
'//////////////////////////////////////////////////////////////////////////

    'specify timeout (optional)
    cmd.CommandTimeout = 1000
    
    ' specify stored procedure
    cmd.CommandText = "Customers Query"
    cmd.CommandType = adCmdStoredProc

    ' in order and one-by-one, add the calling parameter(s) required by the stored procedure
    ' same parameters as C++ ADO
    Set prm = cmd.CreateParameter("", adInteger, adParamInput, 5, 1234)
    cmd.Parameters.Append prm

    ' execute stored procedure
    res = cmd.Execute(0, 0, adCmdStoredProc)

    ' retrieve an out parameter (if parameter direction is adParamOutput, adParamInputOutput or adParamReturnValue)
    vt = rs(0)

'//////////////////////////////////////////////////////////////////////////
'///////////  EXECUTE A STORED PROCEDURE THAT RETURNS A RECORDSET /////////
'//////////////////////////////////////////////////////////////////////////

' specify stored procedure with spot where recordset will be returned marked with "resultset"
    cmd.CommandText = "{ call Wzd.Package.SP(?,?,?,?,{resultset 1024, my_out})}"
    cmd.CommandType = adCmdText

' add input parameters only, one for each "?" in stored procedure call above
    Set prm = cmd.CreateParameter("", adInteger, adParamInput, 5, 1234)
    cmd.Parameters.Append prm

    ' execute stored procedure
    Set rs = cmd.Execute(0, 0, adCmdStoredProc)
    
    ' scroll through rs as before
    
    ' close rs
    rs.Close
       
'//////////////////////////////////////////////////////////////////////////
'////////////////////  USE TRANSACTIONS  //////////////////////////////////
'//////////////////////////////////////////////////////////////////////////
' or just use MTS/COM+ objects
    cn.BeginTrans

    cn.CommitTrans

'    cn.RollbackTrans

   
'//////////////////////////////////////////////////////////////////////////
'////////////////////  SCROLL THROUGH ADO ERRORS //////////////////////////
'//////////////////////////////////////////////////////////////////////////
AdoError:
      Dim errLoop As Error
      Dim strError As String
      Set Errs = cn.Errors
      For Each errLoop In Errs
           Debug.Print errLoop.SQLState
           Debug.Print errLoop.NativeError
           Debug.Print errLoop.Description
      Next
Done:
'//////////////////////////////////////////////////////////////////////////
'////////////////////  DISCONNECT FROM DATABASE ///////////////////////////
'//////////////////////////////////////////////////////////////////////////
    cn.Close
End Sub

Private Sub Command2_Click()
    End
End Sub
