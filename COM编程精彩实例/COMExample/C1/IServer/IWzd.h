/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Jul 03 18:15:21 2007
 */
/* Compiler settings for IWzd.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IWzd_h__
#define __IWzd_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IWzd_FWD_DEFINED__
#define __IWzd_FWD_DEFINED__
typedef interface IWzd IWzd;
#endif 	/* __IWzd_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IWzd_INTERFACE_DEFINED__
#define __IWzd_INTERFACE_DEFINED__

/* interface IWzd */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IWzd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C177116E-9AAA-11D3-805D-000000000000")
    IWzd : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Method1( 
            /* [in] */ long lArg1,
            /* [out] */ long __RPC_FAR *plArg2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Method2( 
            /* [in] */ long lArg,
            /* [in] */ unsigned long ulArg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWzdVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWzd __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWzd __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWzd __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Method1 )( 
            IWzd __RPC_FAR * This,
            /* [in] */ long lArg1,
            /* [out] */ long __RPC_FAR *plArg2);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Method2 )( 
            IWzd __RPC_FAR * This,
            /* [in] */ long lArg,
            /* [in] */ unsigned long ulArg);
        
        END_INTERFACE
    } IWzdVtbl;

    interface IWzd
    {
        CONST_VTBL struct IWzdVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWzd_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWzd_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWzd_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWzd_Method1(This,lArg1,plArg2)	\
    (This)->lpVtbl -> Method1(This,lArg1,plArg2)

#define IWzd_Method2(This,lArg,ulArg)	\
    (This)->lpVtbl -> Method2(This,lArg,ulArg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWzd_Method1_Proxy( 
    IWzd __RPC_FAR * This,
    /* [in] */ long lArg1,
    /* [out] */ long __RPC_FAR *plArg2);


void __RPC_STUB IWzd_Method1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWzd_Method2_Proxy( 
    IWzd __RPC_FAR * This,
    /* [in] */ long lArg,
    /* [in] */ unsigned long ulArg);


void __RPC_STUB IWzd_Method2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWzd_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
