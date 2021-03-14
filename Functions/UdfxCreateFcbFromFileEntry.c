int __fastcall UdfxCreateFcbFromFileEntry(int a1, int a2, _UDF_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, LONGAD *IcbExtent, _UDF_FCB *ParentFcb, _STRING *FileName, _UDF_FCB **ReturnedFcb)
{
  int v8; // edi
  bool v9; // zf
  int v10; // esi
  int *v11; // edi
  int *v12; // ebx
  ICBFILE *v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // ecx
  char v16; // cl
  int v17; // eax
  TIMESTAMP *v18; // esi
  ICBFILE *v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  _LIST_ENTRY *v23; // edx
  unsigned int v25; // [esp-Ch] [ebp-18h]
  ICBFILE *IcbFile; // [esp+8h] [ebp-4h]

  v8 = 0;
  *ReturnedFcb = 0;
  v9 = IcbExtent->Start.Partition == 0;
  IcbFile = 0;
  if ( !v9 )
    return -1073741774;
  if ( FileName )
    v8 = FileName->Length;
  v11 = (int *)(v8 + 52);
  v12 = ExAllocatePoolWithTag(a2, a1, (int)FileName, (unsigned int)v11, 0x63467855u);
  if ( v12 )
  {
    memset(v12, 0, (unsigned int)v11);
    v12[12] = (int)(v12 + 11);
    v12[11] = (int)(v12 + 11);
    if ( FileName )
    {
      qmemcpy(v12 + 13, FileName->Buffer, FileName->Length);
      *((_BYTE *)v12 + 1) = FileName->Length;
    }
    v11 = (int *)IcbExtent;
    v10 = UdfxMapLogicalSector(VolumeExtension, Irp, IcbExtent->Start.Lbn, (void **)&IcbFile);
    if ( v10 < 0 )
      goto CleanupAndExit_29;
    if ( !UdfxVerifyDescriptor(&IcbFile->Destag, 0x800u, 0x105u, IcbExtent->Start.Lbn) )
    {
      DbgPrint((int *)IcbExtent, "UDFX: file descriptor doesn't verify\n");
LABEL_51:
      v10 = -1073741774;
      goto CleanupAndExit_29;
    }
    v13 = IcbFile;
    v14 = IcbFile->EALength;
    if ( v14 > 0x800 || (v15 = IcbFile->AllocLength, v15 > 0x800) || v15 + v14 + 176 > 0x800 )
    {
      DbgPrint((int *)IcbExtent, "UDFX: file descriptor has too large of variant structures\n");
      goto LABEL_51;
    }
    v16 = IcbFile->Icbtag.FileType;
    if ( v16 == 4 )
    {
      *(_BYTE *)v12 |= 2u;
      v13 = IcbFile;
    }
    else if ( v16 != 5 )
    {
      DbgPrint((int *)IcbExtent, "UDFX: file descriptor has unsupported file type\n");
      goto LABEL_51;
    }
    v12[2] = v13->InfoLength;
    v17 = HIDWORD(v13->InfoLength);
    v12[3] = v17;
    if ( v17 )
    {
      DbgPrint((int *)IcbExtent, "UDFX: file descriptor has too large of file size\n");
      goto LABEL_51;
    }
    v18 = &IcbFile->ModifyTime;
    v12[4] = (int)IcbFile->ModifyTime;
    v18 = (TIMESTAMP *)((char *)v18 + 4);
    v12[5] = *(_DWORD *)v18;
    v12[6] = *(_DWORD *)&v18->Month;
    v11 = v12 + 7;
    v19 = IcbFile;
    if ( IcbFile->Icbtag.StratType != 4 )
    {
      DbgPrint(v11, "UDFX: file descriptor has unsupported ICB strategy\n");
      goto LABEL_51;
    }
    v20 = v12[2];
    v10 = 0;
    v21 = IcbFile->Icbtag.Flags & 7;
    if ( !v20 && !IcbFile->AllocLength )
    {
      v11 = (int *)"d:\\xbox-apr03\\private\\ntos\\udfx\\fcbsup.c";
      if ( v12[1] )
        RtlAssert(
          (int)IcbFile,
          0,
          (int *)"d:\\xbox-apr03\\private\\ntos\\udfx\\fcbsup.c",
          0,
          "Fcb->AllocationSectorStart == 0",
          "d:\\xbox-apr03\\private\\ntos\\udfx\\fcbsup.c",
          0xCCu,
          0);
      if ( *((_WORD *)v12 + 1) )
        RtlAssert(
          (int)v19,
          v20,
          (int *)"d:\\xbox-apr03\\private\\ntos\\udfx\\fcbsup.c",
          0,
          "Fcb->EmbeddedDataOffset == 0",
          "d:\\xbox-apr03\\private\\ntos\\udfx\\fcbsup.c",
          0xCDu,
          0);
      goto LABEL_46;
    }
    if ( v21 == 3 )
    {
      if ( v20 == IcbFile->AllocLength )
      {
        *(_BYTE *)v12 |= 8u;
        v12[1] = IcbExtent->Start.Lbn;
        *((_WORD *)v12 + 1) = LOWORD(IcbFile->EALength) + 176;
LABEL_46:
        v12[7] = 1;
        if ( ParentFcb )
        {
          ++ParentFcb->ReferenceCount;
          v12[8] = (int)ParentFcb;
          v23 = ParentFcb->ChildFcbList.Flink;
          v12[9] = (int)ParentFcb->ChildFcbList.Flink;
          v12[10] = (int)&ParentFcb->ChildFcbList;
          v23->Blink = (_LIST_ENTRY *)(v12 + 9);
          ParentFcb->ChildFcbList.Flink = (_LIST_ENTRY *)(v12 + 9);
        }
        *ReturnedFcb = (_UDF_FCB *)v12;
        v12 = 0;
        goto CleanupAndExit_29;
      }
LABEL_40:
      DbgPrint(v11, "UDFX: file descriptor has invalid allocation length\n");
      goto LABEL_51;
    }
    if ( v21 == 1 )
    {
      if ( IcbFile->AllocLength != 16 )
        goto LABEL_40;
      if ( *(unsigned __int16 *)((char *)&IcbFile[1].Destag.Serial + IcbFile->EALength + 1) )
        goto LABEL_51;
      v22 = *(_DWORD *)&IcbFile->EAs[IcbFile->EALength] & 0x3FFFFFFF;
      if ( v20 == v22 )
      {
        v9 = *((_WORD *)v12 + 1) == 0;
        v12[1] = *(_DWORD *)((char *)&IcbFile[1].Destag.Version + IcbFile->EALength + 1);
        if ( v9 )
          goto LABEL_46;
        v25 = 255;
LABEL_45:
        RtlAssert(
          v22,
          v20,
          v11,
          0,
          "Fcb->EmbeddedDataOffset == 0",
          "d:\\xbox-apr03\\private\\ntos\\udfx\\fcbsup.c",
          v25,
          0);
        goto LABEL_46;
      }
    }
    else
    {
      if ( IcbFile->Icbtag.Flags & 7 )
      {
        DbgPrint(v11, "UDFX: file descriptor has unsupported allocation type\n");
        goto LABEL_51;
      }
      if ( IcbFile->AllocLength != 8 )
        goto LABEL_40;
      v22 = *(_DWORD *)&IcbFile->EAs[IcbFile->EALength] & 0x3FFFFFFF;
      if ( v20 == v22 )
      {
        v9 = *((_WORD *)v12 + 1) == 0;
        v12[1] = *(_DWORD *)((char *)&IcbFile[1].Destag.Version + IcbFile->EALength + 1);
        if ( v9 )
          goto LABEL_46;
        v25 = 279;
        goto LABEL_45;
      }
    }
    DbgPrint(v11, "UDFX: file descriptor has invalid extent length\n");
    goto LABEL_51;
  }
  v10 = -1073741670;
CleanupAndExit_29:
  if ( IcbFile )
    FscUnmapBuffer(v11, v10, IcbFile);
  if ( v12 )
    ExFreePool(v12);
  return v10;
}