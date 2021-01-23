// CreatePS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

static char* g_pszUsage = 
"This program generates a makefile and a .def file to\n"
"for creating a proxy-stub dll.\n"
"\n"
"Usage: CreatePS basefilename [-r]\n"
"       Options:\n"
"	      -r -- Adds logic into the makefile\n"
"		        to register the dll after creation\n";

static char* g_pszDefFileInfo =
"LIBRARY      \"%sps.dll\"\n"
"\n"
"DESCRIPTION  'Proxy/Stub DLL'\n"
"\n"
"EXPORTS\n"
"	DllGetClassObject       @1	PRIVATE\n"
"	DllCanUnloadNow         @2	PRIVATE\n"
"	GetProxyDllInfo         @3	PRIVATE\n"
"	DllRegisterServer		@4	PRIVATE\n"
"	DllUnregisterServer		@5	PRIVATE\n";


static char* g_pszLinkInfo =
"%sps.dll: DllData.obj %s_p.obj %s_i.obj\n"
"	link /dll /out:%sps.dll /def:%sps.def /entry:DllMain DllData.obj %s_p.obj %s_i.obj \\\n"
"		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib\n";

static char* g_pszRegSvrInfo =
"	regsvr32 /s %sps.dll\n";

static char* g_pszRuleInfo =
"\n"
".c.obj:\n"
"	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL $<\n";

static char* g_pszCleanInfo =
"\n"
"clean:\n"
"	@del %sps.dll\n"
"	@del %sps.lib\n"
"	@del %sps.exp\n"
"	@del DllData.obj\n"
"	@del %s_p.obj\n"
"	@del %s_i.obj\n";

int main(int argc, char* argv[])
{
	if (argc < 2 || argc > 3) {
		printf(g_pszUsage);
		return 0;
	}

	bool bRegServer = false;
	if (3 == argc) {
		if (!stricmp(argv[2], "-r")) {
			printf("Unknown option: \"%s\"\n", argv[2]);
			return 1;
		}
		bRegServer = true;
	}

	char* pszBaseFileName = argv[1];


	// Step 1: Create def file
	char buf[_MAX_PATH];
	sprintf(buf, "%sps.def", pszBaseFileName);
	FILE* pOut = fopen(buf, "w");
	if (NULL == pOut) {
		printf("File: \"%s\" could not be created\n", buf);
		return 2;
	}

	fprintf(pOut, g_pszDefFileInfo, pszBaseFileName);
	fclose(pOut);

	// Step 2: Generate make file
	sprintf(buf, "%sps.mk", pszBaseFileName);
	pOut = fopen(buf, "w");
	if (NULL == pOut) {
		printf("File: \"%s\" could not be created\n", buf);
		return 3;
	}

	fprintf(pOut, g_pszLinkInfo,
		pszBaseFileName,
		pszBaseFileName,
		pszBaseFileName,
		pszBaseFileName,
		pszBaseFileName,
		pszBaseFileName,
		pszBaseFileName);

	if (true == bRegServer) {
		fprintf(pOut, g_pszRegSvrInfo, pszBaseFileName);
	}

	fprintf(pOut, g_pszRuleInfo, pszBaseFileName);


	fprintf(pOut, g_pszCleanInfo,
		pszBaseFileName,
		pszBaseFileName,
		pszBaseFileName,
		pszBaseFileName,
		pszBaseFileName);

	fclose(pOut);

	printf("Files: \"%sps.def\" and \"%sps.mk\" created\n",
		pszBaseFileName,
		pszBaseFileName);

	return 0;
}

