int *__stdcall UdfxFsdQueryVolumeInformation(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IO_STACK_LOCATION *v2; // ebx
  __int64 v3; // rax
  char *v4; // edi
  char *v5; // edi
  int v6; // ecx
  int *v7; // edi
  int v8; // ecx
  unsigned int v9; // eax
  _DWORD *v10; // eax
  signed int v12; // [esp-4h] [ebp-14h]
  _UDF_VOLUME_EXTENSION *VolumeExtension; // [esp+Ch] [ebp-4h]
  int *status; // [esp+18h] [ebp+8h]

  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  HIDWORD(v3) = v2->Parameters.Create.DesiredAccess;
  VolumeExtension = (_UDF_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v4 = (char *)Irp->UserBuffer;
  memset(v4, 0, 4 * (HIDWORD(v3) >> 2));
  v5 = &v4[4 * (HIDWORD(v3) >> 2)];
  v6 = BYTE4(v3) & 3;
  memset(v5, 0, v6);
  v7 = (int *)&v5[v6];
  v8 = 0;
  status = 0;
  switch ( v2->Parameters.Create.Options )
  {
    case 1u:
      v12 = 17;
      break;
    case 3u:
      v8 = (int)VolumeExtension;
      v7 = (int *)Irp->UserBuffer;
      v3 = VolumeExtension->CacheExtension.PartitionLength.QuadPart >> 11;
      *(_QWORD *)v7 = v3;
      v7[4] = 1;
      v7[5] = 2048;
      v12 = 24;
      break;
    case 4u:
      HIDWORD(v3) = (unsigned __int8)VolumeExtension->CacheExtension.TargetDeviceObject->DeviceType;
      LODWORD(v3) = Irp->UserBuffer;
      *(_DWORD *)v3 = HIDWORD(v3);
      *(_DWORD *)(v3 + 4) = 0;
      v12 = 8;
      break;
    case 5u:
      v10 = Irp->UserBuffer;
      *v10 = 0;
      v10[1] = 255;
      v10[2] = 4;
      if ( v2->Parameters.Create.DesiredAccess >= 0x10 )
      {
        v10[3] = 1481000021;
        v12 = 16;
      }
      else
      {
        v12 = 12;
        status = (int *)-2147483643;
      }
      break;
    default:
      v9 = 0;
      status = (int *)-1073741811;
      goto LABEL_13;
  }
  v9 = v12;
LABEL_13:
  Irp->IoStatus.Information = v9;
  if ( v9 > v2->Parameters.Create.DesiredAccess )
    RtlAssert(
      SHIDWORD(v3),
      v8,
      v7,
      (int)Irp,
      "Irp->IoStatus.Information <= IrpSp->Parameters.QueryVolume.Length",
      "d:\\xbox-apr03\\private\\ntos\\udfx\\volinfo.c",
      0x81u,
      0);
  BYTE4(v3) = 0;
  Irp->IoStatus.Status = (int)status;
  IofCompleteRequest(Irp, SHIDWORD(v3), status);
  return status;
}