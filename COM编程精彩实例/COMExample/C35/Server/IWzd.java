//
// Auto-generated using JActiveX.EXE 5.00.2918
//   ("C:\Program Files\Microsoft Visual Studio\VJ98\jactivex.exe" /wfc  /w /xi /X:rkc /l "C:\TEMP\jvc35.tmp" /nologo /d "G:\jeswanke\mfc3\EXAMPLES\Passing Data between CPP and Visual JPP" "G:\jeswanke\mfc3\EXAMPLES\Passing Data between CPP and Visual JPP\Server\Debug\Server.dll")
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
/** @com.interface(iid=C177116E-9AAA-11D3-805D-000000000000, thread=AUTO, type=DUAL) */
public interface IWzd extends IUnknown
{
  /** @com.method(vtoffset=4, dispid=1, type=METHOD, name="Simple1", addFlagsVtable=4)
      @com.parameters([in,type=I1] byArg, [in,type=I2] sArg, [in,type=I4] lArg) */
  public void Simple1(char byArg, short sArg, int lArg);

  /** @com.method(vtoffset=5, dispid=2, type=METHOD, name="Simple2", addFlagsVtable=4)
      @com.parameters([in,type=R4] fArg, [in,type=R8] dArg) */
  public void Simple2(float fArg, double dArg);

  /** @com.method(vtoffset=6, dispid=3, type=METHOD, name="Simple3", addFlagsVtable=4)
      @com.parameters([in,type=I4] lArg1, [out,size=1,elementType=I4,type=ARRAY] lArg2, [in,out,size=1,elementType=I4,type=ARRAY] lArg3) */
  public void Simple3(int lArg1, int[] lArg2, int[] lArg3);

  /** @com.method(vtoffset=7, dispid=4, type=METHOD, name="Array1", addFlagsVtable=4)
      @com.parameters([in,type=I4] lFirst, [in,type=I4] lLast, [in,type=I4] lSize, [in,size=1,elementType=I4,type=ARRAY] aArg) */
  public void Array1(int lFirst, int lLast, int lSize, int[] aArg);

  /** @com.method(vtoffset=8, dispid=5, type=METHOD, name="Array2", addFlagsVtable=4)
      @com.parameters([in,type=I4] lFirst, [in,type=I4] lLength, [in,type=I4] lSize, [in,size=1,elementType=I4,type=ARRAY] aArg) */
  public void Array2(int lFirst, int lLength, int lSize, int[] aArg);

  /** @com.method(vtoffset=9, dispid=6, type=METHOD, name="VBVars1", addFlagsVtable=4)
      @com.parameters([in,type=STRING] bstr, [out,size=1,elementType=STRING,type=ARRAY] pBSTR) */
  public void VBVars1(String bstr, String[] pBSTR);

  /** @com.method(vtoffset=10, dispid=7, type=METHOD, name="VBVars2", addFlagsVtable=4)
      @com.parameters([in,out,vt=16401,type=SAFEARRAY] pSA) */
  public void VBVars2(com.ms.com.SafeArray pSA);

  /** @com.method(vtoffset=11, dispid=8, type=METHOD, name="VBVars3", addFlagsVtable=4)
      @com.parameters([in,out,elementType=VARIANT,type=PTR] pVAR1, [in,out,elementType=VARIANT,type=PTR] pVAR2, [in,out,elementType=VARIANT,type=PTR] pVAR3) */
  public void VBVars3(Variant pVAR1, Variant pVAR2, Variant pVAR3);

  /** @com.method(vtoffset=12, dispid=9, type=METHOD, name="VBVars4", addFlagsVtable=4)
      @com.parameters([type=I4] return) */
  public int VBVars4();


  public static final com.ms.com._Guid iid = new com.ms.com._Guid((int)0xc177116e, (short)0x9aaa, (short)0x11d3, (byte)0x80, (byte)0x5d, (byte)0x0, (byte)0x0, (byte)0x0, (byte)0x0, (byte)0x0, (byte)0x0);
}
