int __fastcall FatxFsdQueryVolumeInformation(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v4; // ebx
  _FAT_VOLUME_EXTENSION *v5; // esi
  _IO_STACK_LOCATION *v6; // edi
  unsigned int v7; // ecx
  char *v8; // edi
  char v9; // dl
  char *v10; // edi
  int v11; // ecx
  unsigned int v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // eax
  int v16; // edx
  signed int v18; // [esp-4h] [ebp-10h]
  int status; // [esp+14h] [ebp+8h]
  _IO_STACK_LOCATION *IrpSp; // [esp+18h] [ebp+Ch]

  v4 = Irp;
  v5 = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v6 = Irp->Tail.Overlay.CurrentStackLocation;
  IrpSp = v6;
  FatxAcquireVolumeMutexShared(
    a2,
    a1,
    (int *)&v6->MajorFunction,
    (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension);
  if ( v5->Flags & 1 )
  {
    status = -1073741202;
    goto CleanupAndExit_13;
  }
  v7 = v6->Parameters.Create.DesiredAccess;
  v8 = (char *)v4->UserBuffer;
  v9 = v7;
  v7 >>= 2;
  memset(v8, 0, 4 * v7);
  v10 = &v8[4 * v7];
  v11 = v9 & 3;
  memset(v10, 0, v11);
  v6 = (_IO_STACK_LOCATION *)&v10[v11];
  status = 0;
  switch ( IrpSp->Parameters.Create.Options )
  {
    case 1u:
      v6 = (_IO_STACK_LOCATION *)v5->SerialNumber;
      *((_DWORD *)v4->UserBuffer + 2) = v6;
      v18 = 17;
      break;
    case 3u:
      v15 = v4->UserBuffer;
      *v15 = v5->NumberOfClusters;
      v15[1] = 0;
      v15[2] = v5->NumberOfClustersAvailable;
      v15[3] = 0;
      v6 = (_IO_STACK_LOCATION *)(v5->BytesPerCluster >> v5->SectorShift);
      v18 = 24;
      v15[4] = v6;
      v15[5] = v5->CacheExtension.SectorSize;
      break;
    case 4u:
      v6 = (_IO_STACK_LOCATION *)(unsigned __int8)v5->CacheExtension.TargetDeviceObject->DeviceType;
      v14 = v4->UserBuffer;
      *v14 = v6;
      v14[1] = 0;
      v18 = 8;
      break;
    case 5u:
      v13 = v4->UserBuffer;
      *v13 = 0;
      v13[1] = 42;
      v13[2] = 4;
      if ( IrpSp->Parameters.Create.DesiredAccess >= 0x10 )
      {
        v13[3] = 1481916742;
        v18 = 16;
      }
      else
      {
        v18 = 12;
        status = -2147483643;
      }
      break;
    default:
      v12 = 0;
      status = -1073741811;
      goto LABEL_15;
  }
  v12 = v18;
LABEL_15:
  v4->IoStatus.Information = v12;
  if ( v12 > IrpSp->Parameters.Create.DesiredAccess )
    RtlAssert(
      (int)IrpSp,
      0,
      (int *)&v6->MajorFunction,
      (int)v5,
      "Irp->IoStatus.Information <= IrpSp->Parameters.QueryVolume.Length",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\volinfo.c",
      0x92u,
      0);
CleanupAndExit_13:
  FatxReleaseVolumeMutex(v5);
  LOBYTE(v16) = 0;
  v4->IoStatus.Status = status;
  IofCompleteRequest(v4, v16, (int *)&v6->MajorFunction);
  return status;
}