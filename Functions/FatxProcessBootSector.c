int __userpurge FatxProcessBootSector@<eax>(int a1@<edx>, int *a2@<edi>, _DEVICE_OBJECT *VolumeDeviceObject, _IRP *Irp, _LARGE_INTEGER *PartitionLength)
{
  unsigned __int8 *v5; // esi
  unsigned int v6; // ebx
  signed int v7; // esi
  _DEVICE_OBJECT *v8; // edi
  unsigned int v9; // eax
  bool v10; // zf
  unsigned int v11; // eax
  unsigned int v12; // eax
  int v13; // edi
  int *v14; // edi
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rax
  int v17; // ecx
  unsigned int v18; // kr00_4
  unsigned __int64 v19; // kr08_8
  int *v21; // [esp-4h] [ebp-10h]
  unsigned int NumberOfReservedBytes; // [esp+8h] [ebp-4h]

  v5 = (unsigned __int8 *)VolumeDeviceObject->DeviceExtension;
  VolumeDeviceObject = 0;
  v6 = (*((_DWORD *)v5 + 3) + 4095) & 0xFFFFF000;
  NumberOfReservedBytes = 4096;
  if ( v6 > 0x1000 )
    NumberOfReservedBytes = (*((_DWORD *)v5 + 3) + 4095) & 0xFFFFF000;
  if ( PartitionLength->HighPart <= 0u )
  {
    a1 = NumberOfReservedBytes;
    if ( NumberOfReservedBytes >= PartitionLength->LowPart )
      return -1073741489;
  }
  if ( FscMapBuffer(a1, 0, a2, (int)v5, (_FSCACHE_EXTENSION *)v5, Irp, 0i64, 0, (void **)&VolumeDeviceObject) < 0 )
  {
    v7 = -1073741489;
    goto CleanupAndExit_7;
  }
  v21 = a2;
  v8 = VolumeDeviceObject;
  if ( *(_DWORD *)&VolumeDeviceObject->Type != 1481916742 )
  {
    DbgPrint((int *)&VolumeDeviceObject->Type, "FATX: found unrecognized signature\n");
    goto LABEL_10;
  }
  v9 = (unsigned int)VolumeDeviceObject->DriverObject;
  if ( v9 > 0x10 )
  {
    if ( v9 == 32 || v9 == 64 )
      goto LABEL_22;
    v10 = v9 == 128;
    goto LABEL_20;
  }
  if ( v9 != 16 )
  {
    if ( !v9 )
    {
LABEL_21:
      DbgPrint((int *)&VolumeDeviceObject->Type, "FATX: found invalid sectors per cluster\n");
      goto LABEL_10;
    }
    if ( v9 > 2 && v9 != 4 )
    {
      v10 = v9 == 8;
LABEL_20:
      if ( !v10 )
        goto LABEL_21;
      goto LABEL_22;
    }
  }
LABEL_22:
  v11 = v9 << v5[32];
  *((_DWORD *)v5 + 7) = v11;
  v5[33] = RtlFindFirstSetRightMember((void *)v11);
  *((_DWORD *)v5 + 39) = v8->ReferenceCount;
  Irp = (_IRP *)v8->MountedOrSelfDevice;
  FscUnmapBuffer((int *)&v8->Type, (int)v5, VolumeDeviceObject);
  VolumeDeviceObject = 0;
  if ( *((_DWORD *)v5 + 7) >= v6 )
  {
    v12 = ((unsigned __int64)PartitionLength->QuadPart >> v5[33]) + 1;
    if ( v12 >= 0xFFF0 )
    {
      v5[34] = 2;
      v13 = 4 * v12;
    }
    else
    {
      v5[35] |= 2u;
      v5[34] = 1;
      v13 = 2 * v12;
    }
    v14 = (int *)(~(v6 - 1) & (v13 + v6 - 1));
    v15 = *(_QWORD *)PartitionLength - NumberOfReservedBytes;
    if ( (unsigned int)v14 < v15 )
    {
      v17 = v5[33];
      v16 = (v15 - (unsigned int)v14) >> v17;
      *((_DWORD *)v5 + 6) = v16;
      *((_DWORD *)v5 + 9) = NumberOfReservedBytes;
      v18 = *((_DWORD *)v5 + 9);
      *((_DWORD *)v5 + 10) = 0;
      v19 = v18 + (unsigned __int64)(unsigned int)v14;
      *((_DWORD *)v5 + 11) = v19;
      v10 = (*((_DWORD *)v5 + 9) & 0xFFF) == 0;
      *((_DWORD *)v5 + 12) = HIDWORD(v19);
      if ( !v10 )
        RtlAssert(
          SHIDWORD(v16),
          v17,
          (int *)0xFFF,
          (int)v5,
          "BYTE_OFFSET(VolumeExtension->FatByteOffset) == 0",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\mountvol.c",
          0x1AFu,
          0);
      if ( *((_DWORD *)v5 + 11) & 0xFFF )
        RtlAssert(
          SHIDWORD(v16),
          v17,
          (int *)0xFFF,
          (int)v5,
          "BYTE_OFFSET(VolumeExtension->FileAreaByteOffset) == 0",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\mountvol.c",
          0x1B0u,
          0);
      if ( *((_DWORD *)v5 + 7) & 0xFFF )
        RtlAssert(
          SHIDWORD(v16),
          v17,
          (int *)0xFFF,
          (int)v5,
          "BYTE_OFFSET(VolumeExtension->BytesPerCluster) == 0",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\mountvol.c",
          0x1B1u,
          0);
      v7 = FatxCreateFcb(v17, SHIDWORD(v16), 0, (unsigned int)Irp, 0, 0, (_FAT_FCB **)v5 + 4);
      if ( v7 >= 0 )
        v7 = 0;
      goto LABEL_37;
    }
    DbgPrint(v14, "FATX: volume too small to hold the FAT\n");
  }
  else
  {
    DbgPrint((int *)&v8->Type, "FATX: found too small of cluster size\n");
  }
LABEL_10:
  v7 = -1073741489;
LABEL_37:
  a2 = v21;
CleanupAndExit_7:
  if ( VolumeDeviceObject )
    FscUnmapBuffer(a2, v7, VolumeDeviceObject);
  return v7;
}