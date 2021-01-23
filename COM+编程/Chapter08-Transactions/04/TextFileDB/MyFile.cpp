// MyFile.cpp: implementation of the CMyFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyFile::CMyFile()
{
	m_pFile = NULL;

}

CMyFile::~CMyFile()
{
	Close();
}

void CMyFile::Close()
{
	if (NULL != m_pFile) {
		fclose(m_pFile);
		m_pFile = NULL;
	}
}

HRESULT CMyFile::Open(LPCTSTR pwszFilePath, OPENMODE mode)
{
	Close();

	m_pFile = _tfopen(pwszFilePath, (READ == mode) ? _T("r") : _T("w"));
	if (NULL == m_pFile) {
		return E_INVALIDARG; // will do for us
	}

	return S_OK;
}

HRESULT CMyFile::Load(MYACCOUNTDB& db)
{
	_ASSERT (NULL != m_pFile);

	db.erase(db.begin(), db.end()); // clean the list first

	const BUFSIZE = 512;
	TCHAR buf[BUFSIZE]; 
	TCHAR* pRetVal = _fgetts(buf, BUFSIZE, m_pFile);
	while (NULL != pRetVal) {
		TCHAR name[128]; long lBalance;
		int nCount = _stscanf(buf, _T("%s %ld"), name, &lBalance);
		if(2 != nCount) {
			break;
		}
		db[name] = lBalance;
		pRetVal = _fgetts(buf, BUFSIZE, m_pFile);
	}

	return S_OK;
}

HRESULT CMyFile::Save(const MYACCOUNTDB& db)
{
	_ASSERT (NULL != m_pFile);
	MYACCOUNTDB::const_iterator i = db.begin();
	for (; i!=db.end(); i++) {
		const CComBSTR& bsName = (*i).first;
		const long& lBalance = (*i).second;
		_ftprintf(m_pFile, _T("%S %ld\n"), (LPCWSTR) bsName, lBalance);
	}
	return S_OK;
}
