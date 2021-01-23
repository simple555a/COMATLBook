#if !defined(CREATEINST_INCLUDED)
#define CREATEINST_INCLUDED

HRESULT
PTCreateRemoteInstance(
   LPCOLESTR pwszMach, // @parm [in] Remote machine
   const CLSID& clsId, // @parm [in] Class ID
   IUnknown** ppOut);   // @parm [out, retval] IUnknown instance handle

#endif // CREATEINST_INCLUDED

