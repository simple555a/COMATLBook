//
// Auto-generated using JActiveX.EXE 5.00.2918
//   ("C:\Program Files\Microsoft Visual Studio\VJ98\jactivex.exe" /wfc  /w /xi /X:rkc /l "C:\TEMP\jvcBA.tmp" /nologo /d "G:\jeswanke\mfc3\Examples\Creating a COM Object using Visual JPP" "G:\jeswanke\mfc3\Examples\Creating a COM Object using Visual JPP\Server\Server.tlb")
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

/** @com.class(classid=C177116F-9AAA-11D3-805D-000000000000,DynamicCasts) 
    @com.interface(iid=C177116E-9AAA-11D3-805D-000000000000, thread=AUTO, type=DUAL) */
public class Wzd implements IUnknown,com.ms.com.NoAutoScripting,server.IWzd
{
  /** @com.method(vtoffset=4, dispid=1, type=METHOD, name="Method1", addFlagsVtable=4)
      @com.parameters([in,type=I4] lArg) */
  public native void Method1(int lArg);


  public static final com.ms.com._Guid iid = new com.ms.com._Guid((int)0xc177116e, (short)0x9aaa, (short)0x11d3, (byte)0x80, (byte)0x5d, (byte)0x0, (byte)0x0, (byte)0x0, (byte)0x0, (byte)0x0, (byte)0x0);

  public static final com.ms.com._Guid clsid = new com.ms.com._Guid((int)0xc177116f, (short)0x9aaa, (short)0x11d3, (byte)0x80, (byte)0x5d, (byte)0x0, (byte)0x0, (byte)0x0, (byte)0x0, (byte)0x0, (byte)0x0);
}
