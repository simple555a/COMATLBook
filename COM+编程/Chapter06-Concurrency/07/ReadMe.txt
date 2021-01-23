Using CComAutoCriticalSection or InterlockedIncrement or
CWinAtomicCounter to achieve thread-safety on a single
variable of data type "long."

MyCount.cpp defines three macros. Only one of them
can be used at a time.

Macro USECRITICALSECTION shows how to use critical
section to provide thread-safety.

Macro USEINTERLOCK shows how to use InterlockXXX API
to provide thread-safety.

Macro USECPLATOMICCOUNTER shows how to use CPL defined
atomic counter class to provide thread-safety.



