void __stdcall FatxDpcReleaseVolumeMutex(_FAT_VOLUME_EXTENSION *VolumeExtension)
{
  if ( VolumeExtension->VolumeMutex.LockCount >= 0 && !VolumeExtension->VolumeMutex.ReadersEntryCount )
    VolumeExtension->VolumeMutexExclusiveOwner = 0;
  ExReleaseReadWriteLock((int)&VolumeExtension->VolumeMutex);
}