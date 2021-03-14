int *__stdcall GdfxFsdQueryInformation(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v2; // esi
  _IO_STACK_LOCATION *v3; // ebx
  int *v4; // edi
  unsigned int v5; // edx
  _DWORD *v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // eax
  _DWORD *v9; // eax
  signed int v11; // [esp-4h] [ebp-14h]
  _GDF_VOLUME_EXTENSION *VolumeExtension; // [esp+Ch] [ebp-4h]
  _FILE_OBJECT *FileObject; // [esp+18h] [ebp+8h]
  _GDF_FCB *Fcb; // [esp+1Ch] [ebp+Ch]

  v2 = Irp;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  VolumeExtension = (_GDF_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  FileObject = v3->FileObject;
  Fcb = (_GDF_FCB *)FileObject->FsContext;
  if ( Fcb->Flags & 1 && v3->Parameters.Create.Options != 14 )
  {
    v4 = (int *)-1073741811;
    goto CleanupAndExit_24;
  }
  v5 = v3->Parameters.Create.DesiredAccess;
  memset(v2->UserBuffer, 0, v5);
  v6 = 0;
  v7 = v3->Parameters.Create.Options;
  v4 = 0;
  if ( v7 == 6 )
  {
    v9 = v2->UserBuffer;
    v9[1] = VolumeExtension;
    v6 = &Fcb->FirstSector;
    *v9 = Fcb;
    goto LABEL_11;
  }
  if ( v7 == 14 )
  {
    v5 = FileObject->CurrentByteOffset.LowPart;
    v6 = v2->UserBuffer;
    *v6 = v5;
    v6[1] = FileObject->CurrentByteOffset.HighPart;
LABEL_11:
    v11 = 8;
    goto LABEL_12;
  }
  if ( v7 != 34 )
  {
    v8 = 0;
    v4 = (int *)-1073741811;
    goto LABEL_13;
  }
  GdfxQueryNetworkOpenInformation(VolumeExtension, FileObject, (_FILE_NETWORK_OPEN_INFORMATION *)v2->UserBuffer);
  v11 = 56;
LABEL_12:
  v8 = v11;
LABEL_13:
  v2->IoStatus.Information = v8;
  if ( v8 > v3->Parameters.Create.DesiredAccess )
    RtlAssert(
      v5,
      (int)v6,
      v4,
      (int)v2,
      "Irp->IoStatus.Information <= IrpSp->Parameters.QueryFile.Length",
      "d:\\xbox-apr03\\private\\ntos\\gdfx\\fileinfo.c",
      0xAEu,
      0);
CleanupAndExit_24:
  v2->IoStatus.Status = (int)v4;
  IofCompleteRequest(v2, 0, v4);
  return v4;
}