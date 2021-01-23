Showing how to specify default authentication information to
use with each authentication service.

To demonstrate this.

1. Add user "x" to "Employees" role for the salary application.
2. Run the client application as user "y".
3. The client application uses pAuthList parameter of
   CoInitializeSecurity to set identity as "x"
4. The impersonation level that should be used is RPC_C_IMP_LEVEL_IMPERSONATE.

