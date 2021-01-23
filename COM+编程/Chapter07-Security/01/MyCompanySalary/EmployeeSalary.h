// EmployeeSalary.h: Definition of the CEmployeeSalary class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EMPLOYEESALARY_H__D1302DF0_DD23_40AE_8A39_819575ECE331__INCLUDED_)
#define AFX_EMPLOYEESALARY_H__D1302DF0_DD23_40AE_8A39_819575ECE331__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEmployeeSalary

class CEmployeeSalary : 
	public IDispatchImpl<IEmployeeSalary, &IID_IEmployeeSalary, &LIBID_MYCOMPANYSALARYLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<CEmployeeSalary,&CLSID_EmployeeSalary>
{
public:
	CEmployeeSalary() {}
BEGIN_COM_MAP(CEmployeeSalary)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IEmployeeSalary)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CEmployeeSalary) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_EmployeeSalary)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IEmployeeSalary
public:
	STDMETHOD(GetSalary)(/*[in]*/ BSTR bsEmployeeName, /*[out, retval]*/ long *pVal);
	STDMETHOD(UpdateSalary)(/*[in]*/ BSTR bsEmployeeName, /*[in]*/ long newVal);
};

#endif // !defined(AFX_EMPLOYEESALARY_H__D1302DF0_DD23_40AE_8A39_819575ECE331__INCLUDED_)
