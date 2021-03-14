int *__fastcall FatxSetRenameInformation(int a1, char a2, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp)
{
  _IO_STACK_LOCATION *v4; // esi
  int v5; // ecx
  _FAT_FCB *v6; // ebx
  int *v7; // edi
  int *result; // eax
  char v9; // dl
  unsigned int v10; // edx
  unsigned int v11; // eax
  char *v12; // ecx
  int v13; // edx
  int v14; // ecx
  unsigned int v15; // eax
  _FAT_FCB *v16; // esi
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int *v21; // eax
  char *v22; // esi
  int v23; // edx
  unsigned int v24; // ecx
  int *v25; // edi
  char *v26; // esi
  int v27; // ecx
  int v28; // ecx
  int v29; // esi
  _FAT_FCB *v30; // edi
  int *v31; // esi
  int v32; // edx
  _LIST_ENTRY *v33; // ecx
  _LIST_ENTRY *v34; // eax
  int v35; // ecx
  int v36; // edx
  bool v37; // zf
  _LIST_ENTRY *v38; // esi
  _LIST_ENTRY *v39; // eax
  int v40; // edx
  int v41; // ST18_4
  char *v42; // ST18_4
  _DIRENT DirectoryEntry; // [esp+Ch] [ebp-68h]
  _STRING TargetFileName; // [esp+4Ch] [ebp-28h]
  _FAT_FCB *FoundOrNewFcb; // [esp+54h] [ebp-20h]
  unsigned int NewPathNameLength; // [esp+58h] [ebp-1Ch]
  unsigned int DirectoryByteOffset; // [esp+5Ch] [ebp-18h]
  _FAT_FCB *TargetDirectoryFcb; // [esp+60h] [ebp-14h]
  char *TargetFileNameBuffer; // [esp+64h] [ebp-10h]
  char *OriginalFileNameBuffer; // [esp+68h] [ebp-Ch]
  unsigned int EmptyDirectoryByteOffset; // [esp+6Ch] [ebp-8h]
  char OriginalFileNameLength; // [esp+73h] [ebp-1h]
  int status; // [esp+80h] [ebp+Ch]

  v4 = Irp->Tail.Overlay.CurrentStackLocation;
  v5 = (int)v4->FileObject;
  v6 = *(_FAT_FCB **)(v5 + 8);
  v7 = (int *)Irp->UserBuffer;
  if ( v6->Flags & 1 )
    RtlAssert(
      a2,
      v5,
      v7,
      (int)v4,
      "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x1CBu,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a2,
      v5,
      v7,
      (int)v4,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x1CCu,
      0);
  if ( !v6->ParentFcb )
    return (int *)-1073741566;
  if ( !*((_WORD *)v7 + 4) )
    return (int *)-1073741811;
  v9 = v6->FileNameLength;
  OriginalFileNameBuffer = v6->FileNameBuffer;
  OriginalFileNameLength = v9;
  if ( !OriginalFileNameBuffer )
    RtlAssert(
      v9,
      0,
      v7,
      (int)v4,
      "OriginalFileNameBuffer != NULL",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x1E9u,
      0);
  v10 = v7[3];
  v11 = v10 + *((unsigned __int16 *)v7 + 4);
  if ( *(_BYTE *)(v11 - 1) == 92 )
    --v11;
  v12 = (char *)v11;
  if ( v11 > v10 )
  {
    while ( *v12 != 92 )
    {
      if ( (unsigned int)--v12 <= v10 )
        goto LABEL_18;
    }
    ++v12;
  }
LABEL_18:
  TargetFileName.Length = v11 - (_WORD)v12;
  TargetFileName.MaximumLength = v11 - (_WORD)v12;
  TargetFileName.Buffer = v12;
  if ( !FatxIsValidFatFileName(&TargetFileName) )
    return (int *)-1073741773;
  v15 = v4->Parameters.Read.ByteOffset.LowPart;
  if ( v15 )
  {
    v16 = *(_FAT_FCB **)(v15 + 8);
    TargetDirectoryFcb = *(_FAT_FCB **)(v15 + 8);
  }
  else
  {
    TargetDirectoryFcb = v6->ParentFcb;
    v16 = TargetDirectoryFcb;
  }
  if ( !(v16->Flags & 2) )
    RtlAssert(
      (unsigned __int8)v13,
      v14,
      v7,
      (int)v16,
      "FatxIsFlagSet(TargetDirectoryFcb->Flags, FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
      0x220u,
      0);
  NewPathNameLength = (unsigned __int8)v16->PathNameLength + TargetFileName.Length + 1;
  if ( NewPathNameLength > 0xFA )
    return (int *)-1073741773;
  if ( v6->Flags & 2 && ($C1467EDA487160C22DD12D00C5A5B084 *)v6->File.FileMutex.LockCount != &v6->68 )
    return (int *)-1073741790;
  result = (int *)FatxLookupElementNameInDirectory(
                    v13,
                    TargetFileName.Length,
                    v7,
                    VolumeExtension,
                    Irp,
                    v16,
                    &TargetFileName,
                    &DirectoryEntry,
                    &DirectoryByteOffset,
                    &EmptyDirectoryByteOffset);
  if ( (signed int)result < 0 )
  {
    if ( result != (int *)-1073741772 )
      return result;
  }
  else
  {
    if ( !*(_BYTE *)v7 || DirectoryEntry.FileAttributes & 0x11 )
      return (int *)-1073741771;
    if ( FatxFindOpenChildFcb(v17, v18, v7, v16, &TargetFileName, &FoundOrNewFcb) )
      return (int *)-1073741790;
    result = (int *)FatxDeleteFile(v19, v20, v7, VolumeExtension, Irp, v16, DirectoryByteOffset);
    if ( (signed int)result < 0 )
      return result;
    EmptyDirectoryByteOffset = DirectoryByteOffset;
  }
  v21 = ExAllocatePoolWithTag(v17, v18, (int)v16, TargetFileName.Length, 0x6E467446u);
  TargetFileNameBuffer = (char *)v21;
  if ( !v21 )
    return (int *)-1073741670;
  v22 = TargetFileName.Buffer;
  v23 = TargetFileName.Length;
  v24 = (unsigned int)TargetFileName.Length >> 2;
  qmemcpy(v21, TargetFileName.Buffer, 4 * v24);
  v26 = &v22[4 * v24];
  v25 = &v21[v24];
  v27 = v23 & 3;
  qmemcpy(v25, v26, v27);
  v29 = (int)&v26[v27];
  v28 = 0;
  v30 = TargetDirectoryFcb;
  if ( TargetDirectoryFcb == v6->ParentFcb )
  {
    v6->FileNameBuffer = (char *)v21;
    v6->FileNameLength = TargetFileName.Length;
    v31 = (int *)FatxUpdateDirectoryEntry(v23, 0, (int *)&v30->Flags, VolumeExtension, Irp, v6);
    if ( (signed int)v31 < 0 )
    {
      v6->FileNameBuffer = OriginalFileNameBuffer;
      v6->FileNameLength = OriginalFileNameLength;
    }
    else
    {
      if ( v6->Flags < 0 )
        ExFreePool(OriginalFileNameBuffer);
      v6->Flags |= 0x80u;
    }
    return v31;
  }
  if ( EmptyDirectoryByteOffset == -1 )
  {
    if ( TargetDirectoryFcb->AllocationSize == -1 )
      RtlAssert(
        (unsigned __int8)v23,
        0,
        (int *)&TargetDirectoryFcb->Flags,
        v29,
        "TargetDirectoryFcb->AllocationSize != MAXULONG",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fileinfo.c",
        0x2B9u,
        0);
    EmptyDirectoryByteOffset = v30->AllocationSize;
    v31 = FatxExtendDirectoryAllocation(v28, v23, VolumeExtension, Irp, v30);
    if ( (signed int)v31 < 0 )
      goto LABEL_61;
  }
  v31 = (int *)FatxMarkDirectoryEntryDeleted(v28, v23, VolumeExtension, Irp, v6);
  if ( (signed int)v31 < 0 )
  {
LABEL_61:
    ExFreePool(TargetFileNameBuffer);
    return v31;
  }
  v33 = v6->SiblingFcbLink.Blink;
  v34 = v6->SiblingFcbLink.Flink;
  v33->Flink = v34;
  v34->Blink = v33;
  FatxDereferenceFcb(v32, (int)v33, (int *)&v30->Flags, v6->ParentFcb);
  ++v30->ReferenceCount;
  v6->ParentFcb = v30;
  v35 = v30->File.FileMutex.LockCount;
  v6->SiblingFcbLink.Blink = (_LIST_ENTRY *)&v30->68;
  v6->SiblingFcbLink.Flink = (_LIST_ENTRY *)v35;
  *(_DWORD *)(v35 + 4) = (char *)v6 + 16;
  v30->File.FileMutex.LockCount = (int)&v6->SiblingFcbLink;
  v6->FileNameBuffer = TargetFileNameBuffer;
  v6->FileNameLength = TargetFileName.Length;
  v6->DirectoryByteOffset = EmptyDirectoryByteOffset;
  status = FatxUpdateDirectoryEntry(v36, v35, (int *)&v30->Flags, VolumeExtension, Irp, v6);
  if ( status < 0 )
  {
    DbgPrint((int *)&v30->Flags, "FATX: failed to move file across directories\n");
    v38 = v6->SiblingFcbLink.Flink;
    v6->FileNameBuffer = OriginalFileNameBuffer;
    v6->FileNameLength = OriginalFileNameLength;
    v39 = v6->SiblingFcbLink.Blink;
    v39->Flink = v38;
    v38->Blink = v39;
    FatxDereferenceFcb(v40, v41, (int *)&v30->Flags, v30);
    v42 = TargetFileNameBuffer;
    v6->ParentFcb = 0;
    ExFreePool(v42);
  }
  else
  {
    v37 = v6->Flags >= 0;
    v6->PathNameLength = NewPathNameLength;
    if ( !v37 )
      ExFreePool(OriginalFileNameBuffer);
    v6->Flags |= 0x80u;
  }
  return (int *)status;
}