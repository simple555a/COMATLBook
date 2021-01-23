// EmployeeSalary.cpp : Implementation of CMyCompanySalaryApp and DLL registration.

#include "stdafx.h"
#include "MyCompanySalary.h"
#include "EmployeeSalary.h"
#include <comdef.h>
#include <comsvcs.h>

/////////////////////////////////////////////////////////////////////////////
//

void DisplayServerSecurityBlanket()
{
	// Step 1: Get IServerSecurity interface
	CComPtr<IServerSecurity> spSec;
	HRESULT hr = ::CoGetCallContext(__uuidof(IServerSecurity),
		(void**) &spSec);
	if (FAILED(hr)) {
		_bstr_t bsDisplay = "Error getting call context\n";
		bsDisplay += _com_error(hr).ErrorMessage();
		::MessageBox(NULL, bsDisplay, NULL, MB_OK);
		return;
	}

	// Step 2: Get the client's identity
	DWORD dwAuthnSvc, dwAuthzSvc, dwAuthnLevel, dwImpLevel, dwCapabilities;
	OLECHAR* pPrincipalName = NULL;
	RPC_AUTHZ_HANDLE hPrivs;
	hr = spSec->QueryBlanket(
		&dwAuthnSvc,
		&dwAuthzSvc,
		&pPrincipalName,
		&dwAuthnLevel,
		&dwImpLevel,
		&hPrivs,
		&dwCapabilities);
	if (FAILED(hr)) {
		_bstr_t bsDisplay = "Error getting security blanket\n";
		bsDisplay += _com_error(hr).ErrorMessage();
		::MessageBox(NULL, bsDisplay, NULL, MB_OK);
		return;
	}

	_bstr_t bsDisplay = _T("Principal name: ");
	if (NULL == pPrincipalName) {
		bsDisplay += "(Unknown)";
	}else {
		bsDisplay += pPrincipalName;
		::CoTaskMemFree(pPrincipalName); pPrincipalName = NULL;
	}

	bsDisplay += "\nPrivilege name: ";
	if (NULL == hPrivs) {
		bsDisplay += "(Unknown)";
	}else {
		bsDisplay += reinterpret_cast<LPCWSTR>(hPrivs);
	}

	TCHAR buf[256];
	_stprintf(buf, _T("\ndwAuthnSvc=%d, dwAuthzSvc=%d, dwAuthnLevel=%d, dwImpLevel=%d, dwCapabilities=%d"),
			dwAuthnSvc, dwAuthzSvc, dwAuthnLevel, dwImpLevel, dwCapabilities);
	bsDisplay += buf;
	::MessageBox(NULL, bsDisplay, _T("Security blanket"), MB_OK);
}

void DisplaySecurityCallContext()
{
	// Step 1: Get IServerSecurity interface
	CComPtr<ISecurityCallContext> spSec;
	HRESULT hr = ::CoGetCallContext(__uuidof(ISecurityCallContext),
		(void**) &spSec);
	if (FAILED(hr)) {
		_bstr_t bsDisplay = "Error getting call context\n";
		bsDisplay += _com_error(hr).ErrorMessage();
		::MessageBox(NULL, bsDisplay, NULL, MB_OK);
		return;
	}

	VARIANT_BOOL bVal;
	hr = spSec->IsSecurityEnabled(&bVal);
	if (FAILED(hr)) {
		_bstr_t bsDisplay = "Error checking IsSecurityEnabled\n";
		bsDisplay += _com_error(hr).ErrorMessage();
		::MessageBox(NULL, bsDisplay, NULL, MB_OK);
		return;
	}

	_bstr_t bsDisplay = "Security: ";
	bsDisplay += (VARIANT_TRUE == bVal) ? "Enabled" : "Disabled";

	CComVariant vColl;
	hr = spSec->get_Item(CComBSTR("Callers"), &vColl);
	if (FAILED(hr)) {
		bsDisplay += "Error getting callers information\n";
		bsDisplay += _com_error(hr).ErrorMessage();
		::MessageBox(NULL, bsDisplay, NULL, MB_OK);
		return;
	}

	_ASSERT (V_VT(&vColl) == VT_DISPATCH);
	CComPtr<IDispatch> spDisp = V_DISPATCH(&vColl);
	CComPtr<ISecurityCallersColl> spCallersColl;
	hr = spDisp->QueryInterface(&spCallersColl);
	_ASSERT (SUCCEEDED(hr));


	long lCount = 0;
	hr = spCallersColl->get_Count(&lCount);
	_ASSERT (SUCCEEDED(hr));

	for (long i=0; i<lCount; i++) {
		CComPtr<ISecurityIdentityColl> spIdentity;
		hr = spCallersColl->get_Item(i, &spIdentity);
		_ASSERT (SUCCEEDED(hr));
		CComVariant vAccountName;
		hr = spIdentity->get_Item(CComBSTR("AccountName"), &vAccountName);
		_ASSERT (SUCCEEDED(hr));
		_ASSERT (V_VT(&vAccountName) == VT_BSTR);
		bsDisplay += "\nCaller: ";
		bsDisplay += V_BSTR(&vAccountName);
	}

	::MessageBox(NULL, bsDisplay, _T("Security call context"), MB_OK);
}


_bstr_t GetOriginalCaller(ISecurityCallContext* pSec)
{
	CComVariant vColl;
	HRESULT hr = pSec->get_Item(CComBSTR("OriginalCaller"), &vColl);
	_ASSERT (SUCCEEDED(hr));

	_ASSERT (V_VT(&vColl) == VT_DISPATCH);
	CComPtr<IDispatch> spDisp = V_DISPATCH(&vColl);
	CComPtr<ISecurityIdentityColl> spIdentity;
	hr = spDisp->QueryInterface(&spIdentity);
	_ASSERT (SUCCEEDED(hr));

	CComVariant vAccountName;
	hr = spIdentity->get_Item(CComBSTR("AccountName"), &vAccountName);
	_ASSERT (SUCCEEDED(hr));
	_ASSERT (V_VT(&vAccountName) == VT_BSTR);
	return V_BSTR(&vAccountName);
}

STDMETHODIMP CEmployeeSalary::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IEmployeeSalary,
	};

	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (::InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CEmployeeSalary::GetSalary(BSTR bsEmployeeName, long *pVal)
{
	/*
	DisplayServerSecurityBlanket();
	DisplaySecurityCallContext();
	*/

	CComPtr<ISecurityCallContext> spSec;
	HRESULT hr = ::CoGetCallContext(__uuidof(ISecurityCallContext), (void**) &spSec);
	_ASSERT (SUCCEEDED(hr));

	VARIANT_BOOL bFlag;
	hr = spSec->IsCallerInRole(CComBSTR("Managers"), &bFlag);
	_ASSERT (SUCCEEDED(hr));
	if (VARIANT_TRUE == bFlag) {
		*pVal = 100000;
		return S_OK;
	}

	// the caller must be in "Employees" role (as set declaratively on the method)
	// Get the account information

	_bstr_t bsCaller = GetOriginalCaller(spSec);

	if (0 != wcscmp(bsCaller, bsEmployeeName)) {
		// do not match
		return Error(_T("Cannot access another employee's data"), __uuidof(IEmployeeSalary), E_ACCESSDENIED);
	}

	*pVal = 80000;

	return S_OK;
}

STDMETHODIMP CEmployeeSalary::UpdateSalary(BSTR bsEmployeeName, long newVal)
{

	

	return S_OK;
}
