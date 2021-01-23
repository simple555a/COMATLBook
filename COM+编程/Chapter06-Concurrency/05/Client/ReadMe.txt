
Shows various marshaling methods.

File client.cpp defines three macros.
Only one macro can be used at a time.

Macro NOMARSHAL shows the problem if
an interface pointer is passed to a
different context without marshaling.

Macro MARSHALONHGLOBAL shows how to
marshal an interface using global
memory handle.

Macro MARSHALWITHGIT shows how to
use GIT to marshal an interface.

