// MyFile.h: interface for the CMyFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYFILE_H__FB8D8FB6_3221_4F7D_A7F3_F84AD6E520FD__INCLUDED_)
#define AFX_MYFILE_H__FB8D8FB6_3221_4F7D_A7F3_F84AD6E520FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <map>
#include <stdio.h>

typedef std::map<CComBSTR, long> MYACCOUNTDB;

class CMyFile  
{
public:
	CMyFile();
	~CMyFile();

	enum OPENMODE {
		READ,
		WRITE
	};

	HRESULT Open(LPCTSTR pwszFilePath, OPENMODE mode);
	void Close();
	HRESULT Load(MYACCOUNTDB& db);
	HRESULT Save(const MYACCOUNTDB& db);

private:
	FILE* m_pFile;
};

#endif // !defined(AFX_MYFILE_H__FB8D8FB6_3221_4F7D_A7F3_F84AD6E520FD__INCLUDED_)
