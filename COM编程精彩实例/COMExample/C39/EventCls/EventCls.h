/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Jan 22 13:54:52 2000
 */
/* Compiler settings for C:\_jeswanke\mfc3\Examples\__Todo\Using the Event Server\EventCls\EventCls.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
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

#ifndef __EventCls_h__
#define __EventCls_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IWzdCall_FWD_DEFINED__
#define __IWzdCall_FWD_DEFINED__
typedef interface IWzdCall IWzdCall;
#endif 	/* __IWzdCall_FWD_DEFINED__ */


#ifndef __WzdCall_FWD_DEFINED__
#define __WzdCall_FWD_DEFINED__

#ifdef __cplusplus
typedef class WzdCall WzdCall;
#else
typedef struct WzdCall WzdCall;
#endif /* __cplusplus */

#endif 	/* __WzdCall_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IWzdCall_INTERFACE_DEFINED__
#define __IWzdCall_INTERFACE_DEFINED__

/* interface IWzdCall */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IWzdCall;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9431786B-D0FB-11D3-B7BD-000000000000")
    IWzdCall : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WzdEvent( 
            /* [in] */ long lArg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWzdCallVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWzdCall __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWzdCall __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWzdCall __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWzdCall __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWzdCall __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWzdCall __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWzdCall __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WzdEvent )( 
            IWzdCall __RPC_FAR * This,
            /* [in] */ long lArg);
        
        END_INTERFACE
    } IWzdCallVtbl;

    interface IWzdCall
    {
        CONST_VTBL struct IWzdCallVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWzdCall_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWzdCall_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWzdCall_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWzdCall_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWzdCall_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWzdCall_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWzdCall_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWzdCall_WzdEvent(This,lArg)	\
    (This)->lpVtbl -> WzdEvent(This,lArg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzdCall_WzdEvent_Proxy( 
    IWzdCall __RPC_FAR * This,
    /* [in] */ long lArg);


void __RPC_STUB IWzdCall_WzdEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWzdCall_INTERFACE_DEFINED__ */



#ifndef __EVENTCLSLib_LIBRARY_DEFINED__
#define __EVENTCLSLib_LIBRARY_DEFINED__

/* library EVENTCLSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_EVENTCLSLib;

EXTERN_C const CLSID CLSID_WzdCall;

#ifdef __cplusplus

class DECLSPEC_UUID("9431786C-D0FB-11D3-B7BD-000000000000")
WzdCall;
#endif
#endif /* __EVENTCLSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
