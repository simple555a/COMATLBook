import com.ms.wfc.app.*;
import com.ms.wfc.core.*;
import com.ms.wfc.ui.*;
import com.ms.wfc.html.*;
import com.ms.com.Variant;
import com.ms.com.SafeArray;

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
		server.Wzd wzd=new server.Wzd();
		
		// simple variables
		char byArg='a';
		short sArg=1234;
		int lArg=1234567890;
		wzd.Simple1(byArg,sArg,lArg);
		
		float fArg=1.234f;
		double dArg=1.23456789;
		wzd.Simple2(fArg, dArg);
		
		int lArg1=1234;
		int lArg2[]=new int[1];
		int lArg3[]=new int[1];
		lArg3[0]=5678;
		wzd.Simple3(lArg1, lArg2, lArg3);
		
		// arrays
		int lFirst=20;
		int lLast=23;
		int lSize=25;
		int	aArg[]=new int[lSize];
		wzd.Array1(lFirst, lLast, lSize, aArg);
		
		int lLength=3;
		wzd.Array2(lFirst, lLength, lSize, aArg);
		
		// strings
		String bstr="Test";
		String[] pBSTR=new String[1];
		wzd.VBVars1(bstr, pBSTR);
		
		// safearrays
		SafeArray psa = new SafeArray(Variant.VariantByte,100);
		psa.setByte(0,(byte)12);
		wzd.VBVars2(psa);
		
		// variants
		Variant pVAR1=new Variant(1234);
		Variant pVAR2=new Variant(bstr);
		Variant pVAR3=new Variant(psa);
		wzd.VBVars3(pVAR1, pVAR2, pVAR3);
		
		// retval
		int retval=wzd.VBVars4();

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
		this.setClientSize(new Point(308, 322));

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
		label1.setSize(new Point(272, 128));
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
