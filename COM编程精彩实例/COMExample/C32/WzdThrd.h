#ifndef WZDTHREAD_H
#define WZDTHREAD_H

typedef struct t_THREADDATA
{
	LPUNKNOWN lpRawWzd;
	LPSTREAM lpStream;
} THREADDATA;

UINT WzdThrd( LPVOID pParam );

#endif
