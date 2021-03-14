void __stdcall RawxAcquireVolumeMutexShared(_RAW_VOLUME_EXTENSION *VolumeExtension)
{
  --thread->KernelApcDisable;
  ExAcquireReadWriteLockShared(&VolumeExtension->VolumeMutex.LockCount);
}