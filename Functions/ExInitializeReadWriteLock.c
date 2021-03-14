void __stdcall ExInitializeReadWriteLock(_ERWLOCK *ReadWriteLock)
{
  ReadWriteLock->LockCount = -1;
  ReadWriteLock->WritersWaitingCount = 0;
  ReadWriteLock->ReadersWaitingCount = 0;
  ReadWriteLock->ReadersEntryCount = 0;
  ReadWriteLock->WriterEvent.Header.Type = 1;
  ReadWriteLock->WriterEvent.Header.Size = 4;
  ReadWriteLock->WriterEvent.Header.SignalState = 0;
  InitializeListHead(&ReadWriteLock->WriterEvent.Header.WaitListHead);
  KeInitializeSemaphore(&ReadWriteLock->ReaderSemaphore, 0, 0x7FFFFFFF);
}