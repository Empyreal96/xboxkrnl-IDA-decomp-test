void __stdcall FatxReleaseVolumeMutex(_FAT_VOLUME_EXTENSION *VolumeExtension)
{
  _KTHREAD *v1; // eax
  unsigned int v2; // ecx

  if ( VolumeExtension->VolumeMutex.LockCount >= 0 && !VolumeExtension->VolumeMutex.ReadersEntryCount )
    VolumeExtension->VolumeMutexExclusiveOwner = 0;
  ExReleaseReadWriteLock((int)&VolumeExtension->VolumeMutex);
  v1 = thread;
  v2 = thread->KernelApcDisable + 1;
  thread->KernelApcDisable = v2;
  if ( !v2 && (_KAPC_STATE *)v1->ApcState.ApcListHead[0].Flink != &v1->ApcState )
  {
    v1->ApcState.KernelApcPending = 1;
    HalRequestSoftwareInterrupt(1);
  }
}