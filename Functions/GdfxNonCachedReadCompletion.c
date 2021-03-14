int __userpurge GdfxNonCachedReadCompletion@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp, void *Context)
{
  _IRP *v6; // esi
  _IO_STACK_LOCATION *v7; // ebx
  int *v8; // edi
  _FILE_OBJECT *v9; // eax
  int v10; // ecx
  _FILE_OBJECT *FileObject; // [esp+18h] [ebp+Ch]

  v6 = Irp;
  if ( Irp->IoStatus.Status < 0 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)Irp,
      "NT_SUCCESS(Irp->IoStatus.Status)",
      "d:\\xbox-apr03\\private\\ntos\\gdfx\\read.c",
      0x33u,
      0);
  v7 = Irp->Tail.Overlay.CurrentStackLocation;
  v8 = (int *)v7->Parameters.Create.DesiredAccess;
  v9 = v7->FileObject;
  v10 = ((unsigned int)v8 + 2047) & 0xFFFFF800;
  FileObject = v7->FileObject;
  if ( v6->IoStatus.Information != v10 )
  {
    RtlAssert(
      a1,
      v10,
      v8,
      (int)v6,
      "Irp->IoStatus.Information == GDF_CD_SECTOR_ALIGN_UP(ReadLength)",
      "d:\\xbox-apr03\\private\\ntos\\gdfx\\read.c",
      0x3Du,
      0);
    v9 = FileObject;
  }
  if ( v6->PendingReturned )
    *(_BYTE *)(v6->Tail.Overlay.PacketType + 3) |= 1u;
  v6->IoStatus.Information = (unsigned int)v8;
  if ( v9->Flags & 1 )
    v9->CurrentByteOffset.QuadPart = (__int64)(int *)((char *)v8 + v7->Parameters.Read.ByteOffset.QuadPart);
  return 0;
}