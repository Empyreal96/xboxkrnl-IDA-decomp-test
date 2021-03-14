int __userpurge GdfxLookupElementNameInDirectory@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _GDF_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _GDF_FCB *DirectoryFcb, _STRING *ElementName, _GDF_DIRECTORY_ENTRY *ReturnedDirectoryEntry)
{
  _GDF_FCB *v8; // esi
  unsigned int v9; // ebx
  int *v11; // edi
  unsigned __int64 v12; // ST08_8
  signed int v13; // esi
  unsigned int v14; // ebx
  unsigned __int16 *v15; // esi
  unsigned __int8 v16; // cl
  int v17; // eax
  int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // ecx
  unsigned int v21; // eax
  int v22; // esi
  int *v23; // [esp-4h] [ebp-18h]
  _STRING DirectoryEntryFileName; // [esp+8h] [ebp-Ch]
  void *CacheBuffer; // [esp+10h] [ebp-4h]

  v8 = DirectoryFcb;
  if ( !(DirectoryFcb->Flags & 2) )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)DirectoryFcb,
      "GdfxIsFlagSet(DirectoryFcb->Flags, GDF_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\gdfx\\create.c",
      0x3Du,
      0);
  v9 = 0;
  if ( !DirectoryFcb->FileSize )
    return -1073741772;
  v23 = a3;
  CacheBuffer = 0;
  v11 = 0;
  while ( 1 )
  {
    if ( CacheBuffer )
    {
      if ( v11 == (int *)(v9 & 0xFFFFF800) )
        goto LABEL_10;
      FscUnmapBuffer(v11, (int)v8, CacheBuffer);
      CacheBuffer = 0;
    }
    v11 = (int *)(v9 & 0xFFFFF800);
    v12 = (v9 & 0xFFFFF800) + ((unsigned __int64)v8->FirstSector << 11);
    v13 = FscMapBuffer(
            SHIDWORD(v12),
            0,
            (int *)(v9 & 0xFFFFF800),
            (int)v8,
            &VolumeExtension->CacheExtension,
            Irp,
            v12,
            0,
            &CacheBuffer);
    if ( v13 < 0 )
      goto CleanupAndExit_26;
LABEL_10:
    v14 = v9 & 0x7FF;
    if ( v14 > 0x7F2
      || (v15 = (unsigned __int16 *)((char *)CacheBuffer + v14),
          v16 = *((_BYTE *)CacheBuffer + v14 + 13),
          v14 + v16 > 0x7F2) )
    {
      DbgPrint(v11, "GDFX: found invalid directory byte offset\n");
      goto LABEL_21;
    }
    DirectoryEntryFileName.Length = v16;
    DirectoryEntryFileName.Buffer = (char *)(v15 + 7);
    v17 = RtlCompareString(ElementName, &DirectoryEntryFileName, 1);
    if ( !v17 )
    {
      v20 = *((_DWORD *)v15 + 1);
      v21 = VolumeExtension->PartitionSectorCount;
      if ( v20 < v21 && v21 - v20 >= (unsigned int)(*((_DWORD *)v15 + 2) + 2047) >> 11 )
      {
        *(_DWORD *)&ReturnedDirectoryEntry->LeftEntryIndex = *(_DWORD *)v15;
        v22 = (int)(v15 + 2);
        ReturnedDirectoryEntry->FirstSector = *(_DWORD *)v22;
        v22 += 4;
        ReturnedDirectoryEntry->FileSize = *(_DWORD *)v22;
        v22 += 4;
        *(_WORD *)&ReturnedDirectoryEntry->FileAttributes = *(_WORD *)v22;
        ReturnedDirectoryEntry->FileName[0] = *(_BYTE *)(v22 + 2);
        v13 = 0;
        goto CleanupAndExit_26;
      }
LABEL_21:
      v13 = -1073741774;
      goto CleanupAndExit_26;
    }
    v18 = v17 >= 0 ? v15[1] : *v15;
    v19 = 4 * v18;
    if ( !v19 )
      break;
    if ( v19 < (unsigned int)v11 + v14 || v19 >= DirectoryFcb->FileSize )
      goto LABEL_21;
    v9 = v19;
    v8 = DirectoryFcb;
  }
  v13 = -1073741772;
CleanupAndExit_26:
  if ( CacheBuffer )
    FscUnmapBuffer(v23, v13, CacheBuffer);
  return v13;
}