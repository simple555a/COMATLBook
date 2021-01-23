/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Feb 21 11:55:23 2000
 */
/* Compiler settings for C:\_jeswanke\mfc3\Examples\C26\AggSvr\AggSvr.idl:
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

#ifndef __AggSvr_h__
#define __AggSvr_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IWzdAgSvr_FWD_DEFINED__
#define __IWzdAgSvr_FWD_DEFINED__
typedef interface IWzdAgSvr IWzdAgSvr;
#endif 	/* __IWzdAgSvr_FWD_DEFINED__ */


#ifndef __WzdAgSvr_FWD_DEFINED__
#define __WzdAgSvr_FWD_DEFINED__

#ifdef __cplusplus
typedef class WzdAgSvr WzdAgSvr;
#else
typedef struct WzdAgSvr WzdAgSvr;
#endif /* __cplusplus */

#endif 	/* __WzdAgSvr_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IWzdAgSvr_INTERFACE_DEFINED__
#define __IWzdAgSvr_INTERFACE_DEFINED__

/* interface IWzdAgSvr */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IWzdAgSvr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("853B853E-A88A-11D3-A398-00C04F570E2C")
    IWzdAgSvr : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Method1( 
            /* [in] */ long lArg,
            /* [out] */ long __RPC_FAR *plArg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWzdAgSvrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWzdAgSvr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWzdAgSvr __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWzdAgSvr __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWzdAgSvr __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWzdAgSvr __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWzdAgSvr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWzdAgSvr __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Method1 )( 
            IWzdAgSvr __RPC_FAR * This,
            /* [in] */ long lArg,
            /* [out] */ long __RPC_FAR *plArg);
        
        END_INTERFACE
    } IWzdAgSvrVtbl;

    interface IWzdAgSvr
    {
        CONST_VTBL struct IWzdAgSvrVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWzdAgSvr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWzdAgSvr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWzdAgSvr_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWzdAgSvr_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWzdAgSvr_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWzdAgSvr_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWzdAgSvr_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWzdAgSvr_Method1(This,lArg,plArg)	\
    (This)->lpVtbl -> Method1(This,lArg,plArg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzdAgSvr_Method1_Proxy( 
    IWzdAgSvr __RPC_FAR * This,
    /* [in] */ long lArg,
    /* [out] */ long __RPC_FAR *plArg);


void __RPC_STUB IWzdAgSvr_Method1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWzdAgSvr_INTERFACE_DEFINED__ */



#ifndef __AGGSVRLib_LIBRARY_DEFINED__
#define __AGGSVRLib_LIBRARY_DEFINED__

/* library AGGSVRLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AGGSVRLib;

EXTERN_C const CLSID CLSID_WzdAgSvr;

#ifdef __cplusplus

class DECLSPEC_UUID("853B853F-A88A-11D3-A398-00C04F570E2C")
WzdAgSvr;
#endif
#endif /* __AGGSVRLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
