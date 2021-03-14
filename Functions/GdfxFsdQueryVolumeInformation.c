int *__stdcall GdfxFsdQueryVolumeInformation(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IO_STACK_LOCATION *v2; // edx
  int *v3; // edi
  unsigned int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  signed int v9; // [esp-4h] [ebp-10h]
  _GDF_VOLUME_EXTENSION *VolumeExtension; // [esp+14h] [ebp+8h]

  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  VolumeExtension = (_GDF_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  memset(Irp->UserBuffer, 0, v2->Parameters.Create.DesiredAccess);
  v3 = 0;
  switch ( v2->Parameters.Create.Options )
  {
    case 1u:
      v9 = 17;
      break;
    case 3u:
      v7 = Irp->UserBuffer;
      *v7 = VolumeExtension->PartitionSectorCount;
      v7[1] = 0;
      v7[4] = 1;
      v7[5] = 2048;
      v9 = 24;
      break;
    case 4u:
      v6 = Irp->UserBuffer;
      *v6 = (unsigned __int8)VolumeExtension->CacheExtension.TargetDeviceObject->DeviceType;
      v6[1] = 0;
      v9 = 8;
      break;
    case 5u:
      v5 = Irp->UserBuffer;
      *v5 = 0;
      v5[1] = 255;
      v5[2] = 4;
      if ( v2->Parameters.Create.DesiredAccess >= 0x10 )
      {
        v5[3] = 1481000007;
        v9 = 16;
      }
      else
      {
        v9 = 12;
        v3 = (int *)-2147483643;
      }
      break;
    default:
      v4 = 0;
      v3 = (int *)-1073741811;
      goto LABEL_13;
  }
  v4 = v9;
LABEL_13:
  Irp->IoStatus.Information = v4;
  if ( v4 > v2->Parameters.Create.DesiredAccess )
    RtlAssert(
      (int)v2,
      0,
      v3,
      (int)Irp,
      "Irp->IoStatus.Information <= IrpSp->Parameters.QueryVolume.Length",
      "d:\\xbox-apr03\\private\\ntos\\gdfx\\volinfo.c",
      0x81u,
      0);
  LOBYTE(v2) = 0;
  Irp->IoStatus.Status = (int)v3;
  IofCompleteRequest(Irp, (int)v2, v3);
  return v3;
}