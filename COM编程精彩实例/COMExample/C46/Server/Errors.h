// errors.h : user defined COM errors used by this project
//
/////////////////////////////////////////////////////////////////////////////

#if !defined errors_h
#define errors_h

const HRESULT WZD_ERROR1 = MAKE_HRESULT(
							1,				// 1=failure, 0=success
							FACILITY_ITF, 	// COM errors (can also be FACILITY_WINDOWS for window errors, etc.)
							0x0400			// user defined 0x400 and above
							);
const HRESULT WZD_ERROR2 = MAKE_HRESULT(1, FACILITY_ITF, 0x0401);
const HRESULT WZD_ERROR3 = MAKE_HRESULT(1, FACILITY_ITF, 0x0402);

#endif 
