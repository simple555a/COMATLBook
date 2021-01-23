//
// Auto-generated using JActiveX.EXE 5.00.2918
//   ("C:\PROGRAM FILES\MICROSOFT VISUAL STUDIO\VJ98\jactivex.exe" /wfc  /w /xi /X:rkc /l "C:\WINDOWS\TEMP\jvc9381.TMP" /nologo /d "C:\jeswanke\EXAMPLES\Handling Callbacks from COM objects using Visual JPP" "C:\JESWANKE\EXAMPLES\HANDLING CALLBACKS FROM COM OBJECTS USING VISUAL JPP\SERVER\DEBUG\SERVER.DLL")
//
// WARNING: Do not remove the comments that include "@com" directives.
// This source file must be compiled by a @com-aware compiler.
// If you are using the Microsoft Visual J++ compiler, you must use
// version 1.02.3920 or later. Previous versions will not issue an error
// but will not generate COM-enabled class files.
//

package server;

import com.ms.com.*;
import com.ms.com.IUnknown;
import com.ms.com.Variant;

// Dual interface IWzd
/** @com.interface(iid=603F1DE4-A7D8-11D3-A398-00C04F570E2C, thread=AUTO, type=DUAL) */
public interface IWzd extends IUnknown
{
  /** @com.method(vtoffset=4, dispid=1, type=METHOD, name="Method1", addFlagsVtable=4)
      @com.parameters([in,type=I4] lArg) */
  public void Method1(int lArg);


  public static final com.ms.com._Guid iid = new com.ms.com._Guid((int)0x603f1de4, (short)0xa7d8, (short)0x11d3, (byte)0xa3, (byte)0x98, (byte)0x0, (byte)0xc0, (byte)0x4f, (byte)0x57, (byte)0xe, (byte)0x2c);
}
