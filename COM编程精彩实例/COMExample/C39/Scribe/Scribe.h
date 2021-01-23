/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Jan 22 14:03:17 2000
 */
/* Compiler settings for C:\_jeswanke\mfc3\Examples\__Todo\Using the Event Server\Scribe\Scribe.idl:
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

#ifndef __Scribe_h__
#define __Scribe_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IWzdSubscribe_FWD_DEFINED__
#define __IWzdSubscribe_FWD_DEFINED__
typedef interface IWzdSubscribe IWzdSubscribe;
#endif 	/* __IWzdSubscribe_FWD_DEFINED__ */


#ifndef __WzdSubscribe_FWD_DEFINED__
#define __WzdSubscribe_FWD_DEFINED__

#ifdef __cplusplus
typedef class WzdSubscribe WzdSubscribe;
#else
typedef struct WzdSubscribe WzdSubscribe;
#endif /* __cplusplus */

#endif 	/* __WzdSubscribe_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IWzdSubscribe_INTERFACE_DEFINED__
#define __IWzdSubscribe_INTERFACE_DEFINED__

/* interface IWzdSubscribe */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IWzdSubscribe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9431787F-D0FB-11D3-B7BD-000000000000")
    IWzdSubscribe : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WzdEvent( 
            /* [in] */ long lArg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWzdSubscribeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWzdSubscribe __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWzdSubscribe __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWzdSubscribe __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWzdSubscribe __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWzdSubscribe __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWzdSubscribe __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWzdSubscribe __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WzdEvent )( 
            IWzdSubscribe __RPC_FAR * This,
            /* [in] */ long lArg);
        
        END_INTERFACE
    } IWzdSubscribeVtbl;

    interface IWzdSubscribe
    {
        CONST_VTBL struct IWzdSubscribeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWzdSubscribe_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWzdSubscribe_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWzdSubscribe_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWzdSubscribe_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWzdSubscribe_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWzdSubscribe_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWzdSubscribe_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWzdSubscribe_WzdEvent(This,lArg)	\
    (This)->lpVtbl -> WzdEvent(This,lArg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzdSubscribe_WzdEvent_Proxy( 
    IWzdSubscribe __RPC_FAR * This,
    /* [in] */ long lArg);


void __RPC_STUB IWzdSubscribe_WzdEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWzdSubscribe_INTERFACE_DEFINED__ */



#ifndef __SUBSCRIBERLib_LIBRARY_DEFINED__
#define __SUBSCRIBERLib_LIBRARY_DEFINED__

/* library SUBSCRIBERLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SUBSCRIBERLib;

EXTERN_C const CLSID CLSID_WzdSubscribe;

#ifdef __cplusplus

class DECLSPEC_UUID("94317880-D0FB-11D3-B7BD-000000000000")
WzdSubscribe;
#endif
#endif /* __SUBSCRIBERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
