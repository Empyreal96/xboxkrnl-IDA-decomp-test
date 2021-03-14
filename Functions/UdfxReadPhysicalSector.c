int __stdcall UdfxReadPhysicalSector(_UDF_VOLUME_EXTENSION *VolumeExtension, unsigned int PhysicalSectorNumber, void *Buffer)
{
  int result; // eax
  _LARGE_INTEGER ByteOffset; // [esp+0h] [ebp-8h]

  if ( PhysicalSectorNumber < VolumeExtension->PhysicalSectorCount )
    result = IoSynchronousFsdRequest(
               (int)VolumeExtension,
               (unsigned __int64)PhysicalSectorNumber >> 21,
               2u,
               VolumeExtension->CacheExtension.TargetDeviceObject,
               Buffer,
               0x800u,
               &ByteOffset);
  else
    result = -1073741774;
  return result;
}