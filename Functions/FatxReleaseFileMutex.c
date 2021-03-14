void __userpurge FatxReleaseFileMutex(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_FCB *FileFcb)
{
  _KTHREAD *v4; // eax
  unsigned int v5; // ecx

  if ( FileFcb->Flags & 3 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)FileFcb,
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_VOLUME | FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      0x128u,
      0);
  if ( FileFcb->File.FileMutex.LockCount >= 0 && !FileFcb->File.FileMutex.ReadersEntryCount )
    FileFcb->File.FileMutexExclusiveOwner = 0;
  ExReleaseReadWriteLock((int)&FileFcb->68);
  v4 = thread;
  v5 = thread->KernelApcDisable + 1;
  thread->KernelApcDisable = v5;
  if ( !v5 && (_KAPC_STATE *)v4->ApcState.ApcListHead[0].Flink != &v4->ApcState )
  {
    v4->ApcState.KernelApcPending = 1;
    HalRequestSoftwareInterrupt(1);
  }
}