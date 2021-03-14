int *__userpurge IdexDiskPartitionCreate@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, unsigned int PartitionNumber)
{
  unsigned int v4; // ebx
  int *result; // eax
  unsigned int v6; // eax
  char *v7; // ecx
  unsigned int *v8; // eax
  _PARTITION_INFORMATION PartitionInformation; // [esp+8h] [ebp-28h]
  unsigned int v12; // [esp+28h] [ebp-8h]
  unsigned int v13; // [esp+2Ch] [ebp-4h]

  v4 = PartitionNumber;
  if ( !PartitionNumber )
    RtlAssert(a1, a2, a3, 0, "PartitionNumber != 0", "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c", 0x59Bu, 0);
  if ( v4 == 1 )
  {
    v6 = 5633024;
    PartitionInformation.PartitionLength.QuadPart = 5120024576i64;
  }
  else
  {
    if ( v4 == 2 )
    {
      v6 = 4609024;
      PartitionInformation.PartitionLength.LowPart = 524288000;
    }
    else
    {
      if ( v4 >= 6 )
        return (int *)-1073741772;
      v6 = 1536000 * (v4 - 3) + 1024;
      PartitionInformation.PartitionLength.LowPart = 786432000;
    }
    PartitionInformation.PartitionLength.HighPart = 0;
  }
  PartitionInformation.HiddenSectors = v6;
  v7 = (char *)IdexDiskPartitionArray[0]->DeviceExtension;
  PartitionInformation.StartingOffset.QuadPart = (unsigned __int64)v6 << 9;
  PartitionInformation.PartitionNumber = v4;
  if ( PartitionInformation.PartitionLength.QuadPart + PartitionInformation.StartingOffset.QuadPart > *(_QWORD *)(v7 + 12) )
    RtlAssert(
      (unsigned __int64)(PartitionInformation.PartitionLength.QuadPart + PartitionInformation.StartingOffset.QuadPart) >> 32,
      (int)v7,
      a3,
      512,
      "PartitionInformation.StartingOffset.QuadPart + PartitionInformation.PartitionLength.QuadPart <= ((PIDE_DISK_EXTENS"
      "ION)IdexDiskPartitionArray[0]->DeviceExtension)-> PartitionInformation.PartitionLength.QuadPart",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0x5D4u,
      0);
  result = IoCreateDevice(a3, 512, &IdexDiskDriverObject, 0x24u, 0, 7u, 0, (_DEVICE_OBJECT **)&PartitionNumber);
  if ( (signed int)result >= 0 )
  {
    *(_DWORD *)(PartitionNumber + 20) |= 0x44u;
    *(_DWORD *)(PartitionNumber + 36) = 1;
    *(_DWORD *)(PartitionNumber + 32) = 512;
    v8 = *(unsigned int **)(PartitionNumber + 24);
    *v8 = PartitionNumber;
    qmemcpy(v8 + 1, &PartitionInformation, 0x20u);
    *(_DWORD *)(PartitionNumber + 20) &= 0xFFFFFFEF;
    v13 = PartitionNumber;
    v12 = 4 * v4 - 2147150752;
    _ECX = 4 * v4 - 2147150752;
    _EDX = PartitionNumber;
    __asm { cmpxchg [ecx], edx }
    result = 0;
  }
  return result;
}