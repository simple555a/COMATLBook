TestA and TestB are two components.
They both support "DoIt" interface method.

MyClient calls TestB::DoIt.

TestB::DoIt
  a) displays its context Id
  b) calls TestA::DoIt

TestA::DoIt
  a) displays its context id
  b) spawns a thread that tries to
     obtains the default context id (but fails).

Build instructions:

1. Load MyClient workspace.
2. Build TestA, TestB, and MyClient in order.

