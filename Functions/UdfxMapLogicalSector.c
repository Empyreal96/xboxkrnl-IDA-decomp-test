int __stdcall UdfxMapLogicalSector(_UDF_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, unsigned int LogicalSectorNumber, void **CacheBuffer)
{
  unsigned __int64 v5; // kr00_8

  if ( LogicalSectorNumber >= VolumeExtension->PartitionSectorCount )
    return -1073741774;
  v5 = LogicalSectorNumber + (unsigned __int64)VolumeExtension->PartitionSectorStart;
  return FscMapBuffer(
           v5 >> 21,
           v5,
           0,
           (int)VolumeExtension,
           &VolumeExtension->CacheExtension,
           Irp,
           v5 << 11,
           0,
           CacheBuffer);
}