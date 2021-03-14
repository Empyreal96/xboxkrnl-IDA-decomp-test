int *__fastcall FatxFsdQueryInformation(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v4; // esi
  _IO_STACK_LOCATION *v5; // ebx
  _FILE_OBJECT *v6; // edi
  int *v7; // edi
  unsigned int v8; // edx
  _DWORD *v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  _DWORD *v12; // eax
  int v13; // edx
  signed int v15; // [esp-4h] [ebp-14h]
  _FAT_FCB *Fcb; // [esp+Ch] [ebp-4h]
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+18h] [ebp+8h]
  _FILE_OBJECT *FileObject; // [esp+1Ch] [ebp+Ch]

  v4 = Irp;
  v5 = Irp->Tail.Overlay.CurrentStackLocation;
  v6 = v5->FileObject;
  VolumeExtension = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  FileObject = v5->FileObject;
  Fcb = (_FAT_FCB *)v6->FsContext;
  FatxAcquireVolumeMutexShared(a2, (int)Fcb, (int *)&v6->Type, VolumeExtension);
  if ( VolumeExtension->Flags & 1 )
  {
    v7 = (int *)-1073741202;
    goto CleanupAndExit_14;
  }
  if ( v6->Flags & 0x10 )
  {
    v7 = (int *)-1073741528;
    goto CleanupAndExit_14;
  }
  if ( Fcb->Flags & 1 && v5->Parameters.Create.Options != 14 )
  {
    v7 = (int *)-1073741811;
    goto CleanupAndExit_14;
  }
  v8 = v5->Parameters.Create.DesiredAccess;
  memset(v4->UserBuffer, 0, v8);
  v9 = 0;
  v10 = v5->Parameters.Create.Options;
  v7 = 0;
  if ( v10 == 6 )
  {
    v12 = v4->UserBuffer;
    v12[1] = VolumeExtension;
    v9 = &Fcb->Flags;
    *v12 = Fcb;
    goto LABEL_15;
  }
  if ( v10 == 14 )
  {
    v8 = FileObject->CurrentByteOffset.LowPart;
    v9 = v4->UserBuffer;
    *v9 = v8;
    v9[1] = FileObject->CurrentByteOffset.HighPart;
LABEL_15:
    v15 = 8;
    goto LABEL_16;
  }
  if ( v10 != 34 )
  {
    v11 = 0;
    v7 = (int *)-1073741811;
    goto LABEL_17;
  }
  FatxQueryNetworkOpenInformation(v8, 0, (int)v4, FileObject, (_FILE_NETWORK_OPEN_INFORMATION *)v4->UserBuffer);
  v15 = 56;
LABEL_16:
  v11 = v15;
LABEL_17:
  v4->IoStatus.Information = v11;
  if ( v11 > v5->Parameters.Create.DesiredAccess )
    RtlAssert(
      v8,
      (int)v9,
      v7,
      (int)v4,
      "Irp->IoStatus.Information <= IrpSp->Parameters.QueryFile.Length",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0xCCu,
      0);
CleanupAndExit_14:
  FatxReleaseVolumeMutex(VolumeExtension);
  LOBYTE(v13) = 0;
  v4->IoStatus.Status = (int)v7;
  IofCompleteRequest(v4, v13, v7);
  return v7;
}