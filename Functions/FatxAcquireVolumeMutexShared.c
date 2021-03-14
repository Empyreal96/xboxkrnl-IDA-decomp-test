void __userpurge FatxAcquireVolumeMutexShared(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension)
{
  int *v4; // edi

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      0x83u,
      0);
  v4 = &VolumeExtension->VolumeMutex.LockCount;
  if ( VolumeExtension->VolumeMutex.LockCount >= 0
    && !VolumeExtension->VolumeMutex.ReadersEntryCount
    && VolumeExtension->VolumeMutexExclusiveOwner == thread )
  {
    RtlAssert(
      a1,
      a2,
      v4,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      "VolumeExtension->VolumeMutexExclusiveOwner != KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      0x8Bu,
      0);
  }
  --thread->KernelApcDisable;
  ExAcquireReadWriteLockShared(v4);
}