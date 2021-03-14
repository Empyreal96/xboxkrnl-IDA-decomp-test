int *__userpurge IopOpenRenameTarget@<eax>(int *a1@<edi>, int a2@<esi>, void **TargetHandle, _IRP *Irp, _FILE_RENAME_INFORMATION *RenameBuffer, _FILE_OBJECT *FileObject)
{
  int v6; // edx
  int v7; // ST28_4
  void *v8; // ecx
  int v9; // edx
  int v10; // ecx
  int *v11; // esi
  int v12; // edx
  _OBJECT_ATTRIBUTES objectAttributes; // [esp+0h] [ebp-1Ch]
  _IO_STATUS_BLOCK ioStatus; // [esp+Ch] [ebp-10h]
  _FILE_OBJECT *targetFileObject; // [esp+14h] [ebp-8h]
  void *handle; // [esp+18h] [ebp-4h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v6, v7, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\internal.c", 0x32Cu, 0);
  }
  v8 = RenameBuffer->RootDirectory;
  objectAttributes.ObjectName = &RenameBuffer->FileName;
  objectAttributes.RootDirectory = v8;
  objectAttributes.Attributes = 64;
  v11 = IoCreateFile(a1, a2, &handle, 0x100002u, &objectAttributes, &ioStatus, 0, 0, 3u, 1u, 0x4000u, 0x105u);
  if ( (signed int)v11 >= 0 )
  {
    v11 = (int *)ObReferenceObjectByHandle(v9, v10, a1, (int)v11, handle, &IoFileObjectType, (void **)&targetFileObject);
    if ( (signed int)v11 < 0 )
    {
      NtClose(a1, handle);
    }
    else
    {
      ObfDereferenceObject(targetFileObject, v12);
      if ( targetFileObject->DeviceObject == FileObject->DeviceObject )
      {
        *(_DWORD *)(Irp->Tail.Overlay.PacketType - 24) = targetFileObject;
        *TargetHandle = handle;
        v11 = 0;
      }
      else
      {
        NtClose(a1, handle);
        v11 = (int *)-1073741612;
      }
    }
  }
  return v11;
}