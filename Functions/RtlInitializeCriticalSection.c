void __stdcall RtlInitializeCriticalSection(_RTL_CRITICAL_SECTION *CriticalSection)
{
  _RTL_CRITICAL_SECTION *v1; // eax

  v1 = CriticalSection;
  CriticalSection->LockCount = -1;
  CriticalSection->Synchronization.Event.Type = 1;
  CriticalSection->Synchronization.Event.Size = 4;
  CriticalSection->Synchronization.Event.SignalState = 0;
  v1->Synchronization.RawEvent[3] = (unsigned int)&v1->Synchronization.RawEvent[2];
  v1->Synchronization.RawEvent[2] = (unsigned int)&v1->Synchronization.RawEvent[2];
  CriticalSection->RecursionCount = 0;
  CriticalSection->OwningThread = 0;
}