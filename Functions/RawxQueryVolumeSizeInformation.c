int __fastcall RawxQueryVolumeSizeInformation(int a1, int a2, _RAW_VOLUME_EXTENSION *VolumeExtension, _FILE_FS_SIZE_INFORMATION *SizeInformation)
{
  int v4; // edx
  int v5; // ecx
  int v6; // ebx
  unsigned int v7; // esi
  __int64 v8; // rax
  _PARTITION_INFORMATION PartitionInformation; // [esp+Ch] [ebp-38h]
  _DISK_GEOMETRY DiskGeometry; // [esp+2Ch] [ebp-18h]

  v6 = IoSynchronousDeviceIoControlRequest(
         a1,
         a2,
         0x70000u,
         VolumeExtension->TargetDeviceObject,
         0,
         0,
         &DiskGeometry,
         0x18u,
         0,
         0);
  if ( v6 >= 0 )
  {
    v6 = IoSynchronousDeviceIoControlRequest(
           v5,
           v4,
           0x74004u,
           VolumeExtension->TargetDeviceObject,
           0,
           0,
           &PartitionInformation,
           0x20u,
           0,
           0);
    if ( v6 >= 0 )
    {
      v7 = DiskGeometry.BytesPerSector;
      v8 = PartitionInformation.PartitionLength.QuadPart / DiskGeometry.BytesPerSector;
      SizeInformation->TotalAllocationUnits.LowPart = v8;
      SizeInformation->AvailableAllocationUnits.LowPart = v8;
      SizeInformation->TotalAllocationUnits.HighPart = HIDWORD(v8);
      SizeInformation->AvailableAllocationUnits.HighPart = HIDWORD(v8);
      SizeInformation->BytesPerSector = v7;
      SizeInformation->SectorsPerAllocationUnit = 1;
    }
  }
  return v6;
}