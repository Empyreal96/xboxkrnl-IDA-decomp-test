int __userpurge GdfxFindNextDirectoryEntry@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _GDF_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _GDF_FCB *DirectoryFcb, _DIRECTORY_ENUM_CONTEXT *DirectoryEnumContext, _GDF_DIRECTORY_ENTRY **ReturnedDirectoryEntry, unsigned int *ReturnedDirectoryByteOffset)
{
  _GDF_FCB *v9; // esi
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ebx
  signed int v14; // esi
  unsigned __int64 v15; // ST08_8
  _GDF_DIRECTORY_ENTRY *v16; // esi
  unsigned __int8 v17; // cl
  unsigned int v18; // edx
  _STRING DirectoryEntryFileName; // [esp+Ch] [ebp-Ch]
  void *CacheBuffer; // [esp+14h] [ebp-4h]
  _STRING *TemplateFileName; // [esp+2Ch] [ebp+14h]

  v9 = DirectoryFcb;
  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)DirectoryFcb,
      "GdfxIsFlagSet(DirectoryFcb->Flags, GDF_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\gdfx\\dirctrl.c",
      0x41u,
      0);
  v10 = DirectoryEnumContext->QueryOffset;
  TemplateFileName = &DirectoryEnumContext->TemplateFileName;
  v11 = DirectoryFcb->FileSize;
  v12 = 0;
  if ( !v11 )
    return -1073741807;
  CacheBuffer = 0;
  if ( v10 < v11 )
  {
    while ( 1 )
    {
      if ( CacheBuffer )
      {
        if ( v12 == (v10 & 0xFFFFF800) )
          goto LABEL_16;
        FscUnmapBuffer((int *)v10, (int)v9, CacheBuffer);
        CacheBuffer = 0;
      }
      v12 = v10 & 0xFFFFF800;
      v15 = (v10 & 0xFFFFF800) + ((unsigned __int64)v9->FirstSector << 11);
      v14 = FscMapBuffer(
              SHIDWORD(v15),
              0,
              (int *)v10,
              (int)v9,
              &VolumeExtension->CacheExtension,
              Irp,
              v15,
              0,
              &CacheBuffer);
      if ( v14 < 0 )
        goto CleanupAndExit_22;
LABEL_16:
      v10 &= 0x7FFu;
      v16 = (_GDF_DIRECTORY_ENTRY *)((char *)CacheBuffer + v10);
      if ( *(_WORD *)((char *)CacheBuffer + v10) != -1 || v16->RightEntryIndex != -1 )
      {
        if ( v10 > 0x7F2 || (v17 = v16->FileNameLength, v18 = v10 + v17, v18 > 0x7F2) )
        {
          DbgPrint((int *)v10, "GDFX: found invalid directory byte offset\n");
          v14 = -1073741774;
          goto CleanupAndExit_22;
        }
        DirectoryEntryFileName.Length = v17;
        DirectoryEntryFileName.Buffer = v16->FileName;
        if ( !TemplateFileName->Buffer
          || IoIsNameInExpression(
               v18,
               (int)&DirectoryEntryFileName,
               (int *)v10,
               TemplateFileName,
               &DirectoryEntryFileName) )
        {
          *ReturnedDirectoryEntry = v16;
          *ReturnedDirectoryByteOffset = v10 + v12;
          return 0;
        }
        v10 += v12 + (((unsigned __int8)v16->FileNameLength + 17) & 0xFFFFFFFC);
      }
      else
      {
        v10 = v12 + 2048;
      }
      if ( v10 >= DirectoryFcb->FileSize )
        break;
      v9 = DirectoryFcb;
    }
  }
  v14 = -1073741807;
CleanupAndExit_22:
  if ( CacheBuffer )
    FscUnmapBuffer((int *)v10, v14, CacheBuffer);
  return v14;
}