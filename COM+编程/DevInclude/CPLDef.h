#ifndef CPLDEF_H_INCLUDED
#define CPLDEF_H_INCLUDED

#pragma once

#if !defined(_MT)
   #error COM+ Utility code generation option "Multithread" required.
#endif

#ifndef STRICT
#define STRICT
#endif

#ifndef _WIN32_DCOM
#define _WIN32_DCOM
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif

#ifndef WIN32
#define WIN32
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifdef _UNICODE
#ifndef UNICODE
#define UNICODE         // UNICODE is used by Windows headers
#endif
#endif

#ifdef UNICODE
#ifndef _UNICODE
#define _UNICODE        // _UNICODE is used by C-runtime headers
#endif
#endif

#endif // CPLDEF_H_INCLUDED
