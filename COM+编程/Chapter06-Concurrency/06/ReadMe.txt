Synctest shows the kind of problems arise
when Lock/Unlock semantics are exposed as
two different methods.

1. Let's say the client called Lock method.
   If the client crashes for some reason
   after this point, Unlock never gets called,
   thereby locking the resource forever.

2. The developer of the comserver
   may forget to call the Lock/Unlock API
   in some cases.

Both the problems are remedied in SyncTestNew
code. This code uses the CPL defined
CCPLWinSharedResource class.



