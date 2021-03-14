void __userpurge FatxAcquireFileMutexShared(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_FCB *FileFcb)
{
  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      0x10Du,
      0);
  if ( FileFcb->Flags & 3 )
    RtlAssert(
      a1,
      a2,
      (int *)&FileFcb->Flags,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_VOLUME | FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      0x10Eu,
      0);
  --thread->KernelApcDisable;
  ExAcquireReadWriteLockShared(&FileFcb->File.FileMutex.LockCount);
}