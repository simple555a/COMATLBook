/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Feb 21 12:33:06 2000
 */
/* Compiler settings for C:\_jeswanke\mfc3\Examples\C34\CollSrv\CollSrv.idl:
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

#ifndef __CollSrv_h__
#define __CollSrv_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IWzdCollection_FWD_DEFINED__
#define __IWzdCollection_FWD_DEFINED__
typedef interface IWzdCollection IWzdCollection;
#endif 	/* __IWzdCollection_FWD_DEFINED__ */


#ifndef __WzdCollection_FWD_DEFINED__
#define __WzdCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class WzdCollection WzdCollection;
#else
typedef struct WzdCollection WzdCollection;
#endif /* __cplusplus */

#endif 	/* __WzdCollection_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IWzdCollection_INTERFACE_DEFINED__
#define __IWzdCollection_INTERFACE_DEFINED__

/* interface IWzdCollection */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IWzdCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("61790D42-A4D4-11D3-806F-000000000000")
    IWzdCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ VARIANT Index,
            /* [retval][out] */ LPVARIANT pItem) = 0;
        
        virtual /* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *NewObj) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ long numObjs) = 0;
        
        virtual /* [restricted][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ LPUNKNOWN __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWzdCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWzdCollection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWzdCollection __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWzdCollection __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWzdCollection __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWzdCollection __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWzdCollection __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWzdCollection __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item )( 
            IWzdCollection __RPC_FAR * This,
            /* [in] */ VARIANT Index,
            /* [retval][out] */ LPVARIANT pItem);
        
        /* [restricted][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            IWzdCollection __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *NewObj);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IWzdCollection __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IWzdCollection __RPC_FAR * This,
            /* [in] */ long numObjs);
        
        /* [restricted][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get__NewEnum )( 
            IWzdCollection __RPC_FAR * This,
            /* [retval][out] */ LPUNKNOWN __RPC_FAR *pVal);
        
        END_INTERFACE
    } IWzdCollectionVtbl;

    interface IWzdCollection
    {
        CONST_VTBL struct IWzdCollectionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWzdCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWzdCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWzdCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWzdCollection_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWzdCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWzdCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWzdCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWzdCollection_Item(This,Index,pItem)	\
    (This)->lpVtbl -> Item(This,Index,pItem)

#define IWzdCollection_Add(This,NewObj)	\
    (This)->lpVtbl -> Add(This,NewObj)

#define IWzdCollection_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#define IWzdCollection_Init(This,numObjs)	\
    (This)->lpVtbl -> Init(This,numObjs)

#define IWzdCollection_get__NewEnum(This,pVal)	\
    (This)->lpVtbl -> get__NewEnum(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzdCollection_Item_Proxy( 
    IWzdCollection __RPC_FAR * This,
    /* [in] */ VARIANT Index,
    /* [retval][out] */ LPVARIANT pItem);


void __RPC_STUB IWzdCollection_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [restricted][helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzdCollection_Add_Proxy( 
    IWzdCollection __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *NewObj);


void __RPC_STUB IWzdCollection_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWzdCollection_get_Count_Proxy( 
    IWzdCollection __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IWzdCollection_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzdCollection_Init_Proxy( 
    IWzdCollection __RPC_FAR * This,
    /* [in] */ long numObjs);


void __RPC_STUB IWzdCollection_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [restricted][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWzdCollection_get__NewEnum_Proxy( 
    IWzdCollection __RPC_FAR * This,
    /* [retval][out] */ LPUNKNOWN __RPC_FAR *pVal);


void __RPC_STUB IWzdCollection_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWzdCollection_INTERFACE_DEFINED__ */



#ifndef __COLLECTSRVLib_LIBRARY_DEFINED__
#define __COLLECTSRVLib_LIBRARY_DEFINED__

/* library COLLECTSRVLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_COLLECTSRVLib;

EXTERN_C const CLSID CLSID_WzdCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("61790D43-A4D4-11D3-806F-000000000000")
WzdCollection;
#endif
#endif /* __COLLECTSRVLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long __RPC_FAR *, unsigned long            , LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
