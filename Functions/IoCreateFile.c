int *__userpurge IoCreateFile@<eax>(int *a1@<edi>, int a2@<esi>, void **FileHandle, unsigned int DesiredAccess, _OBJECT_ATTRIBUTES *ObjectAttributes, _IO_STATUS_BLOCK *IoStatusBlock, _LARGE_INTEGER *AllocationSize, unsigned int FileAttributes, unsigned int ShareAccess, unsigned int Disposition, unsigned int CreateOptions, unsigned int Options)
{
  int v12; // edx
  int v13; // ST0C_4
  unsigned int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  int *v19; // esi
  _OPEN_PACKET openPacket; // [esp+Ch] [ebp-44h]
  void *handle; // [esp+4Ch] [ebp-4h]
  bool SuccessfulIoParse_3; // [esp+5Fh] [ebp+Fh]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v12, v13, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", 0x571u, 0);
  }
  if ( Options & 0x200
    && (FileAttributes & 0xFFFF8048
     || ShareAccess & 0xFFFFFFF8
     || Disposition > 5
     || CreateOptions & 0xFF000000
     || CreateOptions & 0x30 && !(DesiredAccess & 0x100000)
     || CreateOptions & 0x1000 && !(DesiredAccess & 0x10000)
     || (CreateOptions & 0x30) == 48
     || CreateOptions & 1
     && !(CreateOptions & 0x40)
     && (CreateOptions & 0xFF5F8ECC || Disposition != 2 && Disposition != 1 && Disposition != 3)
     || CreateOptions & 0x100 && CreateOptions & 0x100000
     || CreateOptions & 8 && DesiredAccess & 4) )
  {
    return (int *)-1073741811;
  }
  if ( AllocationSize )
  {
    v15 = AllocationSize->LowPart;
    v16 = AllocationSize->HighPart;
  }
  else
  {
    v15 = 0;
    v16 = 0;
  }
  openPacket.AllocationSize.QuadPart = __PAIR__(v16, v15);
  openPacket.FileAttributes = FileAttributes;
  openPacket.ShareAccess = ShareAccess;
  openPacket.DesiredAccess = DesiredAccess;
  openPacket.Type = 8;
  openPacket.Size = 64;
  openPacket.ParseCheck = 0;
  openPacket.CreateOptions = CreateOptions;
  openPacket.Disposition = Disposition;
  openPacket.QueryOnly = 0;
  openPacket.DeleteOnly = 0;
  openPacket.Options = Options;
  openPacket.RelatedFileObject = 0;
  openPacket.FinalStatus = 0;
  openPacket.FileObject = 0;
  v19 = ObOpenObjectByName(ObjectAttributes, 0, &openPacket, &handle);
  SuccessfulIoParse_3 = openPacket.ParseCheck == -1096154543;
  if ( (signed int)v19 >= 0 )
  {
    if ( SuccessfulIoParse_3 )
    {
      openPacket.FileObject->Flags |= 0x20u;
      if ( openPacket.FileObject->Type != 5 )
        RtlAssert(
          v17,
          v18,
          (int *)Options,
          (int)v19,
          "openPacket.FileObject->Type == IO_TYPE_FILE",
          "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
          0x699u,
          0);
      v19 = (int *)openPacket.FinalStatus;
      *FileHandle = handle;
      IoStatusBlock->Information = openPacket.Information;
      IoStatusBlock->Status = (int)v19;
      goto LABEL_39;
    }
    NtClose((int *)Options, handle);
    v19 = (int *)-1073741788;
  }
  if ( openPacket.FinalStatus >= 0 )
  {
    if ( openPacket.FileObject )
    {
      if ( SuccessfulIoParse_3 )
        goto LABEL_40;
      openPacket.FileObject->DeviceObject = 0;
      ObfDereferenceObject(openPacket.FileObject, v17);
    }
  }
  else
  {
    v19 = (int *)openPacket.FinalStatus;
    if ( (openPacket.FinalStatus & 0xC0000000) == 0x80000000 )
    {
      IoStatusBlock->Status = openPacket.FinalStatus;
      IoStatusBlock->Information = openPacket.Information;
    }
  }
LABEL_39:
  if ( SuccessfulIoParse_3 )
  {
LABEL_40:
    if ( openPacket.FileObject )
      ObfDereferenceObject(openPacket.FileObject, v17);
  }
  return v19;
}