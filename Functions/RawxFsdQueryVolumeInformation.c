int *__stdcall RawxFsdQueryVolumeInformation(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IO_STACK_LOCATION *v2; // ebx
  int *v3; // edi
  unsigned int v4; // edx
  int v5; // ecx
  unsigned int v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  int v9; // edx
  signed int v11; // [esp-4h] [ebp-10h]
  _RAW_VOLUME_EXTENSION *VolumeExtension; // [esp+14h] [ebp+8h]

  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  VolumeExtension = (_RAW_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  RawxAcquireVolumeMutexShared(VolumeExtension);
  if ( VolumeExtension->Dismounted )
  {
    v3 = (int *)-1073741202;
    goto CleanupAndExit_3;
  }
  v4 = v2->Parameters.Create.DesiredAccess;
  memset(Irp->UserBuffer, 0, v4);
  v5 = 0;
  v3 = 0;
  switch ( v2->Parameters.Create.Options )
  {
    case 1u:
      v11 = 17;
      break;
    case 3u:
      v3 = (int *)RawxQueryVolumeSizeInformation(0, v4, VolumeExtension, (_FILE_FS_SIZE_INFORMATION *)Irp->UserBuffer);
      v11 = 24;
      break;
    case 4u:
      v5 = (unsigned __int8)VolumeExtension->TargetDeviceObject->DeviceType;
      v8 = Irp->UserBuffer;
      *v8 = v5;
      v8[1] = 0;
      v11 = 8;
      break;
    case 5u:
      v7 = Irp->UserBuffer;
      v7[2] = 4;
      if ( v2->Parameters.Create.DesiredAccess >= 0x10 )
      {
        v7[3] = 1482113362;
        v11 = 16;
      }
      else
      {
        v11 = 12;
        v3 = (int *)-2147483643;
      }
      break;
    default:
      v6 = 0;
      v3 = (int *)-1073741811;
      goto LABEL_15;
  }
  v6 = v11;
LABEL_15:
  Irp->IoStatus.Information = v6;
  if ( v6 > v2->Parameters.Create.DesiredAccess )
    RtlAssert(
      v4,
      v5,
      v3,
      (int)Irp,
      "Irp->IoStatus.Information <= IrpSp->Parameters.QueryVolume.Length",
      "d:\\xbox-apr03\\private\\ntos\\rawx\\volinfo.c",
      0xC7u,
      0);
CleanupAndExit_3:
  RawxReleaseVolumeMutex(VolumeExtension);
  LOBYTE(v9) = 0;
  Irp->IoStatus.Status = (int)v3;
  IofCompleteRequest(Irp, v9, v3);
  return v3;
}