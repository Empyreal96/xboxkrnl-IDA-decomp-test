int *__fastcall FatxFsdCreate(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _FAT_VOLUME_EXTENSION *v4; // edi
  _IO_STACK_LOCATION *v5; // esi
  _FILE_OBJECT *v6; // ebx
  _STRING *v7; // eax
  _FILE_OBJECT *v8; // eax
  int v9; // edx
  int v10; // ecx
  int *v11; // edi
  _FAT_FCB *v12; // ebx
  unsigned int v13; // eax
  bool v14; // cf
  bool v15; // zf
  int v16; // edi
  _FAT_VOLUME_EXTENSION *v17; // ecx
  _FAT_FCB_BASE *v18; // eax
  int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  _FILE_OBJECT *v23; // edi
  _FAT_FCB *v24; // eax
  int v25; // edx
  _FAT_VOLUME_EXTENSION *v27; // esi
  _FILE_OBJECT *v28; // eax
  _DIRENT DirectoryEntry; // [esp+Ch] [ebp-7Ch]
  _STRING ElementName; // [esp+4Ch] [ebp-3Ch]
  _STRING RemainingName; // [esp+54h] [ebp-34h]
  unsigned int EmptyDirectoryByteOffset; // [esp+5Ch] [ebp-2Ch]
  unsigned int DirectoryByteOffset; // [esp+60h] [ebp-28h]
  _FILE_OBJECT *FileObject; // [esp+64h] [ebp-24h]
  unsigned __int16 ShareAccess; // [esp+68h] [ebp-20h]
  int FileAttributes; // [esp+6Ch] [ebp-1Ch]
  unsigned int DesiredAccess; // [esp+70h] [ebp-18h]
  int CreateFcbCalled; // [esp+74h] [ebp-14h]
  _FAT_FCB *FoundOrNewFcb; // [esp+78h] [ebp-10h]
  unsigned int CreateDisposition; // [esp+7Ch] [ebp-Ch]
  unsigned int CreateOptions; // [esp+80h] [ebp-8h]
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+84h] [ebp-4h]
  _FILE_OBJECT *TrailingBackslash; // [esp+90h] [ebp+8h]
  char TrailingBackslash_3; // [esp+93h] [ebp+Bh]

  v4 = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v5 = Irp->Tail.Overlay.CurrentStackLocation;
  v6 = v5->FileObject;
  DesiredAccess = v5->Parameters.Create.DesiredAccess;
  LOBYTE(FileAttributes) = *((char *)&v5->Parameters.SetVolume + 8) & 0x37;
  ShareAccess = v5->Parameters.Create.ShareAccess;
  CreateOptions = v5->Parameters.Create.Options;
  CreateDisposition = CreateOptions >> 24;
  v7 = v5->Parameters.Create.RemainingName;
  *(_DWORD *)&RemainingName.Length = *(_DWORD *)&v7->Length;
  RemainingName.Buffer = v7->Buffer;
  v8 = v6->RelatedFileObject;
  VolumeExtension = v4;
  FileObject = v6;
  TrailingBackslash = v8;
  FatxAcquireVolumeMutexExclusive(a2, *(int *)&RemainingName.Length, (int *)v4, (int)v5, v4);
  if ( v4->Flags & 1 )
  {
    v11 = (int *)-1073741202;
    goto CleanupAndExit_18;
  }
  if ( CreateOptions & 0x2000 )
  {
    v11 = (int *)-1073741822;
    goto CleanupAndExit_18;
  }
  if ( Irp->Overlay.AllocationSize.HighPart )
    goto LABEL_32;
  if ( TrailingBackslash )
  {
    v12 = (_FAT_FCB *)TrailingBackslash->FsContext;
    v11 = 0;
    if ( v12 && v12->Flags & 2 )
    {
      if ( v12->Flags & 0x10 )
      {
        v11 = (int *)-1073741738;
        goto CleanupAndExit_18;
      }
      if ( !RemainingName.Length )
      {
        if ( v5->Flags & 4 )
        {
LABEL_49:
          v11 = (int *)FatxOpenTargetDirectory(v10, v9, VolumeExtension, Irp, v12->ParentFcb, 4u, 0);
          goto CleanupAndExit_18;
        }
        ++v12->ReferenceCount;
        goto OpenStartDirectoryFcb;
      }
      if ( *RemainingName.Buffer != 92 )
      {
        v10 = RemainingName.Length;
        v13 = (unsigned __int8)v12->PathNameLength + RemainingName.Length + 1;
        v14 = v13 < 0xFA;
        v15 = v13 == 250;
        goto LABEL_35;
      }
LABEL_36:
      v11 = (int *)-1073741773;
      goto CleanupAndExit_18;
    }
LABEL_32:
    v11 = (int *)-1073741811;
    goto CleanupAndExit_18;
  }
  if ( !RemainingName.Length )
  {
    v16 = (int)&v4->VolumeFcb;
    if ( CreateDisposition != 1 && CreateDisposition != 3 )
    {
      v11 = (int *)-1073741790;
      goto CleanupAndExit_18;
    }
    if ( CreateOptions & 1 )
    {
      v11 = (int *)-1073741565;
      goto CleanupAndExit_18;
    }
    if ( CreateOptions & 0x1000 )
    {
      v11 = (int *)-1073741535;
      goto CleanupAndExit_18;
    }
    if ( !(v5->Flags & 4) )
    {
      v6->Flags |= 4u;
      if ( *(_BYTE *)(v16 + 8) )
      {
        v11 = (int *)IoCheckShareAccess(
                       (int *)v16,
                       (int)v5,
                       DesiredAccess,
                       ShareAccess,
                       v6,
                       (_SHARE_ACCESS *)(v16 + 8),
                       1);
        if ( (signed int)v11 < 0 )
          goto CleanupAndExit_18;
      }
      else
      {
        IoSetShareAccess((int *)v16, (int)v5, DesiredAccess, ShareAccess, v6, (_SHARE_ACCESS *)(v16 + 8));
      }
      v17 = VolumeExtension;
      v18 = &VolumeExtension->VolumeFcb;
      ++v18->ReferenceCount;
      v6->FsContext = v18;
      v11 = 0;
      v6->FsContext2 = 0;
      ++v17->FileObjectCount;
      Irp->IoStatus.Information = 1;
      goto CleanupAndExit_18;
    }
    goto LABEL_32;
  }
  v12 = VolumeExtension->RootDirectoryFcb;
  if ( *RemainingName.Buffer != 92 )
    goto LABEL_36;
  if ( RemainingName.Length == 1 )
  {
    if ( !(v5->Flags & 4) )
    {
      ++v12->ReferenceCount;
      v11 = 0;
      goto OpenStartDirectoryFcb;
    }
    goto LABEL_32;
  }
  v14 = RemainingName.Length < 0xFAu;
  v15 = RemainingName.Length == 250;
LABEL_35:
  if ( !v14 && !v15 )
    goto LABEL_36;
  v11 = (int *)"RemainingName.Length > 0";
  if ( !RemainingName.Length )
    RtlAssert(
      v9,
      v10,
      (int *)"RemainingName.Length > 0",
      (int)v5,
      "RemainingName.Length > 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x4BEu,
      0);
  if ( RemainingName.Buffer[RemainingName.Length - 1] == 92 )
  {
    --RemainingName.Length;
    TrailingBackslash_3 = 1;
  }
  else
  {
    TrailingBackslash_3 = 0;
  }
  if ( !RemainingName.Length )
    RtlAssert(
      v9,
      (int)RemainingName.Buffer,
      (int *)"RemainingName.Length > 0",
      (int)v5,
      "RemainingName.Length > 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x4C8u,
      0);
  do
  {
    ObDissectName(RemainingName, &ElementName, &RemainingName);
    if ( RemainingName.Length && *RemainingName.Buffer == 92
      || !FatxFindOpenChildFcb(v19, v20, (int *)"RemainingName.Length > 0", v12, &ElementName, &FoundOrNewFcb) )
    {
      LOBYTE(CreateFcbCalled) = 0;
      while ( 1 )
      {
        if ( (_BYTE)CreateFcbCalled )
        {
          ObDissectName(RemainingName, &ElementName, &RemainingName);
          if ( RemainingName.Length )
          {
            if ( *RemainingName.Buffer == 92 )
              goto LABEL_77;
          }
        }
        if ( !FatxIsValidFatFileName(&ElementName) )
          goto LABEL_77;
        v21 = FatxLookupElementNameInDirectory(
                v9,
                v10,
                v11,
                VolumeExtension,
                Irp,
                v12,
                &ElementName,
                &DirectoryEntry,
                &DirectoryByteOffset,
                &EmptyDirectoryByteOffset);
        v11 = (int *)v21;
        if ( v21 == -1073741772 )
          break;
        if ( v21 < 0 )
          goto LABEL_94;
        if ( RemainingName.Length )
        {
          if ( !(DirectoryEntry.FileAttributes & 0x10) )
            goto LABEL_59;
        }
        else if ( v5->Flags & 4 )
        {
          v22 = FatxOpenTargetDirectory(v10, v9, VolumeExtension, Irp, v12, 4u, CreateFcbCalled);
          goto LABEL_92;
        }
        v11 = (int *)FatxCreateFcb(
                       v10,
                       v9,
                       v12,
                       DirectoryEntry.FirstCluster,
                       &DirectoryEntry,
                       DirectoryByteOffset,
                       &FoundOrNewFcb);
        if ( (signed int)v11 < 0 )
          goto LABEL_94;
        if ( (_BYTE)CreateFcbCalled )
        {
          if ( v12->ReferenceCount < 2 )
            RtlAssert(
              v9,
              v10,
              v11,
              (int)v5,
              "CurrentFcb->ReferenceCount >= 2",
              "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
              0x5F7u,
              0);
          --v12->ReferenceCount;
        }
        v12 = FoundOrNewFcb;
        LOBYTE(CreateFcbCalled) = 1;
        if ( !RemainingName.Length )
          goto LABEL_93;
      }
      if ( RemainingName.Length )
      {
LABEL_59:
        v11 = (int *)-1073741766;
        goto LABEL_94;
      }
      if ( v12->Flags & 0x10 )
      {
        v11 = (int *)-1073741738;
        goto LABEL_94;
      }
      if ( v5->Flags & 4 )
      {
        v22 = FatxOpenTargetDirectory(v10, v9, VolumeExtension, Irp, v12, 5u, CreateFcbCalled);
LABEL_92:
        v11 = (int *)v22;
        if ( v22 >= 0 )
          goto CleanupAndExit_18;
LABEL_93:
        if ( (signed int)v11 >= 0 )
          goto OpenCurrentFcb;
        goto LABEL_94;
      }
      if ( CreateDisposition != 1 && CreateDisposition != 4 )
      {
        if ( TrailingBackslash_3 && CreateOptions & 0x40 )
        {
LABEL_77:
          v11 = (int *)-1073741773;
          goto LABEL_94;
        }
        if ( CreateOptions & 1 )
          LOBYTE(FileAttributes) = FileAttributes | 0x10;
        else
          LOBYTE(FileAttributes) = FileAttributes & 0xEF;
        v11 = (int *)FatxCheckDesiredAccess(DesiredAccess, CreateOptions, FileAttributes, 1);
        if ( (signed int)v11 >= 0 )
        {
          v11 = FatxCreateNewFile(
                  v9,
                  v10,
                  (int)Irp,
                  VolumeExtension,
                  Irp,
                  v12,
                  &ElementName,
                  EmptyDirectoryByteOffset,
                  FileAttributes,
                  Irp->Overlay.AllocationSize.LowPart,
                  &DirectoryEntry,
                  &FoundOrNewFcb);
          if ( (signed int)v11 >= 0 )
          {
            if ( (_BYTE)CreateFcbCalled )
            {
              if ( v12->ReferenceCount < 2 )
                RtlAssert(
                  v9,
                  v10,
                  v11,
                  (int)Irp,
                  "CurrentFcb->ReferenceCount >= 2",
                  "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
                  0x599u,
                  0);
              --v12->ReferenceCount;
            }
            v23 = FileObject;
            IoSetShareAccess(
              (int *)&FileObject->Type,
              (int)Irp,
              DesiredAccess,
              ShareAccess,
              FileObject,
              &FoundOrNewFcb->ShareAccess);
            v24 = FoundOrNewFcb;
            v23->FsContext2 = 0;
            v23->FsContext = v24;
            ++VolumeExtension->FileObjectCount;
            if ( CreateOptions & 0x1000 && !(FoundOrNewFcb->Flags & 2) )
              FoundOrNewFcb->Flags |= 0x10u;
            Irp->IoStatus.Information = 2;
            goto LABEL_129;
          }
        }
      }
LABEL_94:
      if ( !(_BYTE)CreateFcbCalled )
        goto CleanupAndExit_18;
      goto LABEL_95;
    }
    v12 = FoundOrNewFcb;
  }
  while ( RemainingName.Length );
  if ( v5->Flags & 4 )
    goto LABEL_49;
  ++FoundOrNewFcb->ReferenceCount;
  v11 = 0;
OpenCurrentFcb:
  if ( v12->Flags & 2 )
  {
OpenStartDirectoryFcb:
    if ( CreateDisposition == 1 || CreateDisposition == 3 )
    {
      if ( CreateOptions & 0x40 )
        v11 = (int *)-1073741638;
    }
    else
    {
LABEL_101:
      v11 = (int *)-1073741771;
    }
    goto LABEL_108;
  }
  if ( CreateDisposition == 2 )
    goto LABEL_101;
  if ( TrailingBackslash_3 || CreateOptions & 1 )
    v11 = (int *)-1073741565;
LABEL_108:
  if ( v5->Flags & 4 )
    RtlAssert(
      v9,
      v10,
      v11,
      (int)v5,
      "FatxIsFlagClear(IrpSp->Flags, SL_OPEN_TARGET_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
      0x62Eu,
      0);
  if ( (signed int)v11 < 0 )
    goto LABEL_95;
  v11 = (int *)FatxCheckDesiredAccess(DesiredAccess, CreateOptions, v12->FileAttributes, 0);
  if ( (signed int)v11 < 0 )
    goto LABEL_95;
  if ( v12->ShareAccess.OpenCount )
    v11 = (int *)IoCheckShareAccess(v11, (int)v5, DesiredAccess, ShareAccess, FileObject, &v12->ShareAccess, 1);
  else
    IoSetShareAccess(v11, (int)v5, DesiredAccess, ShareAccess, FileObject, &v12->ShareAccess);
  if ( (signed int)v11 < 0 )
    goto LABEL_95;
  if ( CreateDisposition && CreateDisposition != 4 && CreateDisposition != 5 )
  {
    v27 = VolumeExtension;
    Irp->IoStatus.Information = 1;
  }
  else
  {
    if ( v12->Flags & 2 )
      RtlAssert(
        v9,
        v10,
        v11,
        (int)v5,
        "FatxIsFlagClear(CurrentFcb->Flags, FAT_FCB_DIRECTORY)",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\create.c",
        0x659u,
        0);
    v27 = VolumeExtension;
    v11 = FatxOverwriteExistingFile(
            v9,
            v10,
            v11,
            VolumeExtension,
            Irp,
            v12,
            FileAttributes,
            Irp->Overlay.AllocationSize.LowPart);
    if ( (signed int)v11 < 0 )
      IoRemoveShareAccess(v11, (int)v27, FileObject, &v12->ShareAccess);
    else
      Irp->IoStatus.Information = 3;
  }
  if ( (signed int)v11 < 0 )
  {
LABEL_95:
    FatxDereferenceFcb(v9, v10, v11, v12);
  }
  else
  {
    v28 = FileObject;
    FileObject->FsContext2 = 0;
    v28->FsContext = v12;
    ++v27->FileObjectCount;
    if ( CreateOptions & 0x1000 && !(v12->Flags & 2) )
      v12->Flags |= 0x10u;
LABEL_129:
    v11 = 0;
  }
CleanupAndExit_18:
  FatxReleaseVolumeMutex(VolumeExtension);
  LOBYTE(v25) = 0;
  Irp->IoStatus.Status = (int)v11;
  IofCompleteRequest(Irp, v25, v11);
  return v11;
}