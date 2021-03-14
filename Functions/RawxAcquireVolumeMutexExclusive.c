void __stdcall RawxAcquireVolumeMutexExclusive(_RAW_VOLUME_EXTENSION *VolumeExtension)
{
  --thread->KernelApcDisable;
  ExAcquireReadWriteLockExclusive(&VolumeExtension->VolumeMutex.LockCount);
}