import com.ms.wfc.app.*;
import com.ms.wfc.core.*;
import com.ms.wfc.ui.*;
import com.ms.wfc.html.*;
import com.ms.com.*;
import com.ms.wfc.data.*;

/**
 * This class can take a variable number of parameters on the command
 * line. Program execution begins with the main() method. The class
 * constructor is not invoked unless an object of type 'Form1' is
 * created in the main() method.
 */

public class Form1 extends Form
{
	public Form1()
	{
		// Required for Visual J++ Form Designer support
		initForm();		

		// TODO: Add any constructor code after initForm call
	}

	/**
	 * Form1 overrides dispose so it can clean up the
	 * component list.
	 */
	public void dispose()
	{
		super.dispose();
		components.dispose();
	}

	private void button1_click(Object source, Event e)
	{
//////////////////////////////////////////////////////////////////////////
////////////////     CREATE THE ADO COM OBJECT    ////////////////////////
//////////////////////////////////////////////////////////////////////////
	com.ms.wfc.data.Command command=new com.ms.wfc.data.Command();
	com.ms.wfc.data.Connection connection=new com.ms.wfc.data.Connection();	
//////////////////////////////////////////////////////////////////////////
////////////////     OPEN THE DATABASE    ////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// initialize connection object
		try {
		connection.setConnectionTimeout(
					1000		//default is DEFAULT_DBCONNECTPROP
					);

// open connection to db
		connection.open(
					"WZDDB",			// connection string DSN (other ex:"MSOracle8") 
					"",				// user id
					""				// password
					); 	

// initialize command object
		command.setActiveConnection(connection);
			
//////////////////////////////////////////////////////////////////////////
////////////////     GET A RECORD SET (w/SQL)  ///////////////////////////
//////////////////////////////////////////////////////////////////////////
		com.ms.wfc.data.Recordset rs =new Recordset();

// specify SQL command
	// *NOTE: SQL will not retrieve blobs--must use Stored Procedure
		command.setCommandText("SELECT * FROM CUSTOMERS");
		command.setCommandType(AdoEnums.CommandType.TEXT);	// what text in command specifies. also:
									  // adCmdStoredProc - stored procedure
							   		  // adCmdTable - table name
							   		  // adCmdFile - file name
							   		  // adCmdTableDirect - 
							   		  // adCmdUnknown - unknown

// open record set
		rs.open(command, 				// source of record set--can be a SQL statement, etc.--see last param
			null, 							// active connection object (optional)
			AdoEnums.CursorType.FORWARDONLY,// cursor type. also:
										 // adOpenForwardOnly 
										 //	adOpenKeyset Opens a keyset-type cursor. 
										 //	adOpenDynamic Opens a dynamic-type cursor. 
										 //	adOpenStatic Opens a static type cursor. 
			AdoEnums.LockType.OPTIMISTIC,// record set locking type. also:
										// adLockReadOnly -- read only
										// adLockPessimistic --lock records at the data source when editing
										// adLockOptimistic -- lock records only when you call the Update method. 
										// adLockBatchOptimistic -- same as above, used with batch mode
			AdoEnums.CommandType.UNSPECIFIED// define source param--here we can use a command object. also:
											// adCmdText indicates source is a SQL statement
											// adCmdTable indicates source is a table name. 
											// adCmdStoredProc indicates source as a stored procedure. 
											// adCmdUnknown indicates source argument is not known. 
			);

//////////////////////////////////////////////////////////////////////////
////////////////  SCROLL THROUGH RECORDSET (COLUMNS & ROWS) //////////////
//////////////////////////////////////////////////////////////////////////
	while (!rs.getEOF())
	{
		String CustomerID=rs.getField("CustomerID").getString();
		String CompanyName=rs.getField("CompanyName").getString();
		String ContactName=rs.getField("ContactName").getString();
		rs.moveNext();
	}
	rs.moveFirst();


//////////////////////////////////////////////////////////////////////////
////////////////  ADD A RECORD TO A DATABASE /////////////////////////////
//////////////////////////////////////////////////////////////////////////
	rs.addNew();
	rs.getField("CustomerID").setString("BONCO"); 
	rs.getField("CompanyName").setString("Franks"); 
	rs.getField("ContactName").setString("Runk"); 
	rs.update();
	

//////////////////////////////////////////////////////////////////////////
////////////////  EDIT A RECORD IN A DATABASE /////////////////////////////
//////////////////////////////////////////////////////////////////////////
// edits current record
	rs.getField("ContactName").setString("Smith"); 
	rs.update();

//////////////////////////////////////////////////////////////////////////
////////////////  DELETE A RECORD FROM THE DATABASE //////////////////////
//////////////////////////////////////////////////////////////////////////
// deletes current record
	rs.delete(AdoEnums.Affect.CURRENT);
	
//////////////////////////////////////////////////////////////////////////
////////////////  CLOSE RECORDSET ////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
	rs.close();

//////////////////////////////////////////////////////////////////////////
////////////////  EXECUTE A STORED PROCEDURE /////////////////////////////
//////////////////////////////////////////////////////////////////////////

	// specify timeout (optional)
	command.setCommandTimeout(
				1000				//default is DEFAULT_DBCONNECTPROP
				);

	// specify stored procedure
	command.setCommandText("Customers Query");
	command.setCommandType(AdoEnums.CommandType.STOREDPROC);

	// in order and one-by-one, add the calling parameter(s) required by the stored procedure
	command.getParameters().append(command.createParameter(
			"",					 		// a user assigned parameter name (optional)
			AdoEnums.DataType.INTEGER,		// data type. 
			AdoEnums.ParameterDirection.INPUT,// direction. 
			5,							// database column size for this parameter required by SP (must be a long)
			new Variant(1234)			 			//if adParamInput or adParamInputOutput, the input value as a variant
			));

	// execute stored procedure
	command.execute(null, 						// returned number of records affected
			AdoEnums.CommandType.STOREDPROC	// what text in command specifies.
			);		

	// retrieve an out parameter (if parameter direction is adParamOutput, adParamInputOutput or adParamReturnValue)
	// retrieve a long from the zeroth parameter
	long vt=command.getParameters().getItem(0).getValue().getvt(); //retrieve the 0 parameter
	// retrieve a variant the zeroth parameter
	Variant vart=command.getParameters().getItem(0).getValue();
	

//////////////////////////////////////////////////////////////////////////
///////////  EXECUTE A STORED PROCEDURE THAT RETURNS A RECORDSET /////////
//////////////////////////////////////////////////////////////////////////

// specify stored procedure with spot where recordset will be returned marked with "resultset"
	command.setCommandText("{ call Wzd.Package.SP(?,?,?,?,{resultset 1024, my_out})}");	
	command.setCommandType(AdoEnums.CommandType.TEXT);

// add input parameters only, one for each "?" in stored procedure call above
	command.getParameters().append(command.createParameter(
			"",						 		// a user assigned parameter name (optional)
			AdoEnums.DataType.INTEGER,		// data type. 
			AdoEnums.ParameterDirection.INPUT,// direction. 
			5,							// database column size for this parameter required by SP (must be a long)
			new Variant(1234)			 			//if adParamInput or adParamInputOutput, the input value as a variant
			));


// open, scroll through and close record set as above
	rs.open(command,null,AdoEnums.CursorType.FORWARDONLY,AdoEnums.LockType.OPTIMISTIC,AdoEnums.CommandType.UNSPECIFIED);
	rs.close();

//////////////////////////////////////////////////////////////////////////
////////////////////  USE TRANSACTIONS  //////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// or just use MTS/COM+ objects
	connection.beginTrans();

	connection.commitTrans();

//	connection.rollbackTrans();


//////////////////////////////////////////////////////////////////////////
////////////////////  DISCONNECT FROM DATABASE ///////////////////////////
//////////////////////////////////////////////////////////////////////////
	connection.close();


//////////////////////////////////////////////////////////////////////////
////////////////////  SCROLL THROUGH ADO ERRORS //////////////////////////
//////////////////////////////////////////////////////////////////////////
	}
	catch(AdoException ae)
	{
		for (int i = 0; i< connection.getErrors().getCount(); i++)
		{
			com.ms.wfc.data.Error errItem = connection.getErrors().getItem(i);
			System.out.println(errItem.getDescription());
			System.out.println("\nPress <Enter> to continue...");
		}
	}
	catch (Exception ae)
	{
	}
	
}


	private void Dismiss_click(Object source, Event e)
	{
		System.exit(0);
	}

	/**
	 * NOTE: The following code is required by the Visual J++ form
	 * designer.  It can be modified using the form editor.  Do not
	 * modify it using the code editor.
	 */
	Container components = new Container();
	Button button1 = new Button();
	Button Dismiss = new Button();
	Label label1 = new Label();

	private void initForm()
	{
		this.setText("Form1");
		this.setAutoScaleBaseSize(new Point(5, 13));
		this.setClientSize(new Point(311, 316));

		button1.setFont(new Font("MS Sans Serif", 12.0f, FontSize.POINTS, FontWeight.NORMAL, false, false, false, CharacterSet.DEFAULT, 0));
		button1.setLocation(new Point(88, 144));
		button1.setSize(new Point(152, 96));
		button1.setTabIndex(0);
		button1.setText("Test");
		button1.addOnClick(new EventHandler(this.button1_click));

		Dismiss.setFont(new Font("MS Sans Serif", 12.0f, FontSize.POINTS, FontWeight.NORMAL, false, false, false, CharacterSet.DEFAULT, 0));
		Dismiss.setLocation(new Point(88, 248));
		Dismiss.setSize(new Point(152, 56));
		Dismiss.setTabIndex(1);
		Dismiss.setText("Dismiss");
		Dismiss.addOnClick(new EventHandler(this.Dismiss_click));

		label1.setFont(new Font("MS Sans Serif", 12.0f, FontSize.POINTS, FontWeight.NORMAL, false, false, false, CharacterSet.DEFAULT, 0));
		label1.setLocation(new Point(16, 8));
		label1.setSize(new Point(288, 128));
		label1.setTabIndex(2);
		label1.setTabStop(false);
		label1.setText("To view the test, build both the tester and server (if any). If either is C++ build the debug version.  Put a breakpoint on the Test button handler and step through the project. Please refer to the book for any specific instructions.");

		this.setNewControls(new Control[] {
							label1, 
							Dismiss, 
							button1});
	}

	/**
	 * The main entry point for the application. 
	 *
	 * @param args Array of parameters passed to the application
	 * via the command line.
	 */
	public static void main(String args[])
	{
		Application.run(new Form1());
	}
}
