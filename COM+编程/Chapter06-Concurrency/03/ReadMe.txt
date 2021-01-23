The sample shows if a component is part of an activity,
only one thread can enter the activity.

The component, ActivityTest, displays a MessageBox on
DoIt method. Any threading model will do as long
as Synchronization=Required is set.

The client sample spawns two threads to enter the
activity. The second thread blocks forever till
OK button is clicked on the message box.
