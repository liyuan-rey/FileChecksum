/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Oct 24 23:38:10 2001
 */
/* Compiler settings for G:\AllProjs\Working_Folder\VC6Projs\FileChecksum\Codes\FileChecksum.idl:
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

#ifndef __FileChecksum_h__
#define __FileChecksum_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IChecksum_FWD_DEFINED__
#define __IChecksum_FWD_DEFINED__
typedef interface IChecksum IChecksum;
#endif 	/* __IChecksum_FWD_DEFINED__ */


#ifndef __Checksum_FWD_DEFINED__
#define __Checksum_FWD_DEFINED__

#ifdef __cplusplus
typedef class Checksum Checksum;
#else
typedef struct Checksum Checksum;
#endif /* __cplusplus */

#endif 	/* __Checksum_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IChecksum_INTERFACE_DEFINED__
#define __IChecksum_INTERFACE_DEFINED__

/* interface IChecksum */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IChecksum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B974ACA6-B145-4017-90BA-DCA2E2CD68B8")
    IChecksum : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IChecksumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IChecksum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IChecksum __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IChecksum __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IChecksum __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IChecksum __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IChecksum __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IChecksum __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IChecksumVtbl;

    interface IChecksum
    {
        CONST_VTBL struct IChecksumVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChecksum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IChecksum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IChecksum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IChecksum_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IChecksum_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IChecksum_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IChecksum_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IChecksum_INTERFACE_DEFINED__ */



#ifndef __FILECHECKSUMLib_LIBRARY_DEFINED__
#define __FILECHECKSUMLib_LIBRARY_DEFINED__

/* library FILECHECKSUMLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_FILECHECKSUMLib;

EXTERN_C const CLSID CLSID_Checksum;

#ifdef __cplusplus

class DECLSPEC_UUID("4E51DE8C-07AB-49E4-B151-21B0A1B6AB41")
Checksum;
#endif
#endif /* __FILECHECKSUMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
