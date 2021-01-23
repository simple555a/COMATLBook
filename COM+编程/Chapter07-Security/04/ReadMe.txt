Problems with callback.

Can be solved in two ways:

1. Use a NULL security descriptor, essentially allowing anyone to
   access the object.
2. Use IAccessControl to specify the users that can call back into the client.
