NATIVE COM SUPPORT

Build ExploreIDL first so that this project
can pick up the typelibrary.

Note that the native COM support cannot handle
all possible IDL keywords. Temporarily, comment out
GetGrades3, GetGrades4, GetGrades5, and GetGrades6
methods in ExploreIDL.idl file before building
ExploreIDL project.
