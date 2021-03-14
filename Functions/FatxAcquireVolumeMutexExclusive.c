void __userpurge FatxAcquireVolumeMutexExclusive(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _FAT_VOLUME_EXTENSION *VolumeExtension)
{
  int *v5; // edi
  _KTHREAD *v6; // ecx

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      0x5Bu,
      0);
  v5 = &VolumeExtension->VolumeMutex.LockCount;
  if ( VolumeExtension->VolumeMutex.LockCount >= 0 && !VolumeExtension->VolumeMutex.ReadersEntryCount )
  {
    v6 = VolumeExtension->VolumeMutexExclusiveOwner;
    if ( v6 == thread )
      RtlAssert(
        a1,
        (int)v6,
        v5,
        (int)VolumeExtension,
        "VolumeExtension->VolumeMutexExclusiveOwner != KeGetCurrentThread()",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
        0x63u,
        0);
  }
  --thread->KernelApcDisable;
  ExAcquireReadWriteLockExclusive(v5);
  VolumeExtension->VolumeMutexExclusiveOwner = thread;
}