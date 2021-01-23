COM+ Programming: A Practical Guide Using Visual C++ and ATL
by Pradeep Tapadiya

ISBN: 0-13-088674-2

I. CONTENTS OF THE CD

This CD contains all the sample programs that were
referred to in the book. All the programs have been
organized by chapters. Each subfolder within a
chapter folder contains one sample application.
Subfolders with numeric names indicate a progression
from one sample to the next.

Each subfolder also contains a ReadMe.txt file describing
the intent of the sample application.

The CD also contains some useful C++ classes
that I refer to as the COM+ Programming Library (CPL).
The CPL files can be found in the DevInclude directory.

II. SYSTEM REQUIREMENTS

Visual C++ 6.0 Service Pack 3
Platform SDK (at least January 2000 edition)
Windows 2000 System

III. INSTALLATION

1. Copy all the files to a directory (for eg., c:\Dev).
2. Add "c:\Dev\DevInclude" to your include path (within Visual Studio).

IV. BUILDING THE APPLICATIONS

Most applications are based on Visual Studio's workspaces.
These applications should be built from within Visual Studio.

Some applications are based on makefile. To build these
applications, use "nmake -f makefile" command.

To build a new application using CPL, include <CPLBase.h>
in the standard header file (StdAfx.h) and <CPLBase.cpp> in
the standard source file (StdAfx.cpp).

V. LICENSE AGREEMENT

Use of the software accompanying COM+ Programming: A Practical Guide 
Using Visual C++ and ATL is subject to the terms of the License
Agreement and Limited Warranty, found in the back of the book.

VI. TECHNICAL SUPPORT

Prentice Hall does not offer technical support for any of the programs
on the CD-ROM. However, if the CD-ROM is damaged, you may obtain a 
replacement copy by sending an email that describes the problem to: 
disc_exchange@prenhall.com.
