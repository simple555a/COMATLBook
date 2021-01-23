/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Feb 21 12:34:37 2000
 */
/* Compiler settings for C:\_jeswanke\mfc3\Examples\C35\Server\Server.idl:
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

#ifndef __Server_h__
#define __Server_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IWzd_FWD_DEFINED__
#define __IWzd_FWD_DEFINED__
typedef interface IWzd IWzd;
#endif 	/* __IWzd_FWD_DEFINED__ */


#ifndef __Wzd_FWD_DEFINED__
#define __Wzd_FWD_DEFINED__

#ifdef __cplusplus
typedef class Wzd Wzd;
#else
typedef struct Wzd Wzd;
#endif /* __cplusplus */

#endif 	/* __Wzd_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IWzd_INTERFACE_DEFINED__
#define __IWzd_INTERFACE_DEFINED__

/* interface IWzd */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IWzd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C177116E-9AAA-11D3-805D-000000000000")
    IWzd : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Simple1( 
            /* [in] */ unsigned char byArg,
            /* [in] */ short sArg,
            /* [in] */ long lArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Simple2( 
            /* [in] */ float fArg,
            /* [in] */ double dArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Simple3( 
            /* [in] */ long lArg1,
            /* [out] */ long __RPC_FAR *lArg2,
            /* [out][in] */ long __RPC_FAR *lArg3) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Array1( 
            /* [in] */ long lFirst,
            /* [in] */ long lLast,
            /* [in] */ long lSize,
            /* [size_is][last_is][first_is][in] */ long __RPC_FAR *aArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Array2( 
            /* [in] */ long lFirst,
            /* [in] */ long lLength,
            /* [in] */ long lSize,
            /* [size_is][length_is][first_is][in] */ long __RPC_FAR *aArg) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VBVars1( 
            /* [in] */ BSTR bstr,
            /* [out] */ BSTR __RPC_FAR *pBSTR) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VBVars2( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pSA) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VBVars3( 
            /* [out][in] */ VARIANT __RPC_FAR *pVAR1,
            /* [out][in] */ VARIANT __RPC_FAR *pVAR2,
            /* [out][in] */ VARIANT __RPC_FAR *pVAR3) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VBVars4( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
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
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWzd __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWzd __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWzd __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWzd __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Simple1 )( 
            IWzd __RPC_FAR * This,
            /* [in] */ unsigned char byArg,
            /* [in] */ short sArg,
            /* [in] */ long lArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Simple2 )( 
            IWzd __RPC_FAR * This,
            /* [in] */ float fArg,
            /* [in] */ double dArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Simple3 )( 
            IWzd __RPC_FAR * This,
            /* [in] */ long lArg1,
            /* [out] */ long __RPC_FAR *lArg2,
            /* [out][in] */ long __RPC_FAR *lArg3);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Array1 )( 
            IWzd __RPC_FAR * This,
            /* [in] */ long lFirst,
            /* [in] */ long lLast,
            /* [in] */ long lSize,
            /* [size_is][last_is][first_is][in] */ long __RPC_FAR *aArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Array2 )( 
            IWzd __RPC_FAR * This,
            /* [in] */ long lFirst,
            /* [in] */ long lLength,
            /* [in] */ long lSize,
            /* [size_is][length_is][first_is][in] */ long __RPC_FAR *aArg);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VBVars1 )( 
            IWzd __RPC_FAR * This,
            /* [in] */ BSTR bstr,
            /* [out] */ BSTR __RPC_FAR *pBSTR);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VBVars2 )( 
            IWzd __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pSA);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VBVars3 )( 
            IWzd __RPC_FAR * This,
            /* [out][in] */ VARIANT __RPC_FAR *pVAR1,
            /* [out][in] */ VARIANT __RPC_FAR *pVAR2,
            /* [out][in] */ VARIANT __RPC_FAR *pVAR3);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VBVars4 )( 
            IWzd __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
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


#define IWzd_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWzd_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWzd_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWzd_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWzd_Simple1(This,byArg,sArg,lArg)	\
    (This)->lpVtbl -> Simple1(This,byArg,sArg,lArg)

#define IWzd_Simple2(This,fArg,dArg)	\
    (This)->lpVtbl -> Simple2(This,fArg,dArg)

#define IWzd_Simple3(This,lArg1,lArg2,lArg3)	\
    (This)->lpVtbl -> Simple3(This,lArg1,lArg2,lArg3)

#define IWzd_Array1(This,lFirst,lLast,lSize,aArg)	\
    (This)->lpVtbl -> Array1(This,lFirst,lLast,lSize,aArg)

#define IWzd_Array2(This,lFirst,lLength,lSize,aArg)	\
    (This)->lpVtbl -> Array2(This,lFirst,lLength,lSize,aArg)

#define IWzd_VBVars1(This,bstr,pBSTR)	\
    (This)->lpVtbl -> VBVars1(This,bstr,pBSTR)

#define IWzd_VBVars2(This,pSA)	\
    (This)->lpVtbl -> VBVars2(This,pSA)

#define IWzd_VBVars3(This,pVAR1,pVAR2,pVAR3)	\
    (This)->lpVtbl -> VBVars3(This,pVAR1,pVAR2,pVAR3)

#define IWzd_VBVars4(This,pVal)	\
    (This)->lpVtbl -> VBVars4(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzd_Simple1_Proxy( 
    IWzd __RPC_FAR * This,
    /* [in] */ unsigned char byArg,
    /* [in] */ short sArg,
    /* [in] */ long lArg);


void __RPC_STUB IWzd_Simple1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzd_Simple2_Proxy( 
    IWzd __RPC_FAR * This,
    /* [in] */ float fArg,
    /* [in] */ double dArg);


void __RPC_STUB IWzd_Simple2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzd_Simple3_Proxy( 
    IWzd __RPC_FAR * This,
    /* [in] */ long lArg1,
    /* [out] */ long __RPC_FAR *lArg2,
    /* [out][in] */ long __RPC_FAR *lArg3);


void __RPC_STUB IWzd_Simple3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzd_Array1_Proxy( 
    IWzd __RPC_FAR * This,
    /* [in] */ long lFirst,
    /* [in] */ long lLast,
    /* [in] */ long lSize,
    /* [size_is][last_is][first_is][in] */ long __RPC_FAR *aArg);


void __RPC_STUB IWzd_Array1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzd_Array2_Proxy( 
    IWzd __RPC_FAR * This,
    /* [in] */ long lFirst,
    /* [in] */ long lLength,
    /* [in] */ long lSize,
    /* [size_is][length_is][first_is][in] */ long __RPC_FAR *aArg);


void __RPC_STUB IWzd_Array2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzd_VBVars1_Proxy( 
    IWzd __RPC_FAR * This,
    /* [in] */ BSTR bstr,
    /* [out] */ BSTR __RPC_FAR *pBSTR);


void __RPC_STUB IWzd_VBVars1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzd_VBVars2_Proxy( 
    IWzd __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pSA);


void __RPC_STUB IWzd_VBVars2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzd_VBVars3_Proxy( 
    IWzd __RPC_FAR * This,
    /* [out][in] */ VARIANT __RPC_FAR *pVAR1,
    /* [out][in] */ VARIANT __RPC_FAR *pVAR2,
    /* [out][in] */ VARIANT __RPC_FAR *pVAR3);


void __RPC_STUB IWzd_VBVars3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWzd_VBVars4_Proxy( 
    IWzd __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IWzd_VBVars4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWzd_INTERFACE_DEFINED__ */



#ifndef __SERVERLib_LIBRARY_DEFINED__
#define __SERVERLib_LIBRARY_DEFINED__

/* library SERVERLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_SERVERLib;

EXTERN_C const CLSID CLSID_Wzd;

#ifdef __cplusplus

class DECLSPEC_UUID("C177116F-9AAA-11D3-805D-000000000000")
Wzd;
#endif
#endif /* __SERVERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

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
