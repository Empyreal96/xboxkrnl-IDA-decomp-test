int __fastcall FatxCreateFcb(int a1, int a2, _FAT_FCB *ParentFcb, unsigned int FirstCluster, _DIRENT *DirectoryEntry, unsigned int DirectoryByteOffset, _FAT_FCB **ReturnedFcb)
{
  int v7; // edi
  unsigned int v8; // eax
  int v9; // edi
  int *v10; // ebx
  int v11; // edx
  int v12; // ecx
  _LARGE_INTEGER v13; // rax
  int v14; // ecx
  bool v15; // zf
  char *v16; // edi
  unsigned int v17; // eax
  char *v18; // edi
  int v19; // ecx
  int *v20; // edi
  int v21; // ecx
  unsigned int v22; // eax
  int v23; // edx
  char v24; // cl
  unsigned int v25; // ecx
  _BYTE *v26; // eax
  int result; // eax

  if ( DirectoryEntry )
  {
    v9 = (unsigned __int8)DirectoryEntry->FileNameLength;
    if ( DirectoryEntry->FileAttributes & 0x10 )
    {
      v7 = v9 + 104;
      v8 = 1665430598;
    }
    else
    {
      v7 = v9 + 244;
      v8 = 1665561670;
    }
  }
  else
  {
    v7 = 104;
    v8 = 1666348102;
  }
  v10 = ExAllocatePoolWithTag(a2, a1, (int)DirectoryEntry, v7, v8);
  if ( v10 )
  {
    v11 = v7;
    memset(v10, 0, v7);
    v12 = 0;
    v10[1] = 1;
    v10[7] = FirstCluster;
    v10[8] = 0;
    if ( FirstCluster )
    {
      v10[10] = -1;
    }
    else if ( v10[10] )
    {
      RtlAssert(
        v7,
        0,
        (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        (int)DirectoryEntry,
        "Fcb->AllocationSize == 0",
        "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
        0x7Cu,
        0);
    }
    if ( DirectoryEntry )
    {
      if ( !ParentFcb )
        RtlAssert(
          v11,
          v12,
          (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          (int)DirectoryEntry,
          "ParentFcb != NULL",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          0x88u,
          0);
      if ( !(ParentFcb->Flags & 2) )
        RtlAssert(
          v11,
          v12,
          (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          (int)DirectoryEntry,
          "FatxIsFlagSet(ParentFcb->Flags, FAT_FCB_DIRECTORY)",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          0x89u,
          0);
      *((_BYTE *)v10 + 3) = DirectoryEntry->FileAttributes;
      v10[9] = DirectoryEntry->FileSize;
      v10[16] = DirectoryEntry->LastAccessTime.AsULONG;
      v10[15] = DirectoryEntry->CreationTime.AsULONG;
      v13 = FatxFatTimestampToTime(&DirectoryEntry->LastWriteTime);
      v15 = (*((_BYTE *)v10 + 3) & 0x10) == 0;
      *(_LARGE_INTEGER *)(v10 + 13) = v13;
      if ( v15 )
      {
        ExInitializeReadWriteLock((_ERWLOCK *)(v10 + 17));
        v13.LowPart = (unsigned int)(v10 + 61);
      }
      else
      {
        *(_BYTE *)v10 |= 2u;
        v13.LowPart = (unsigned int)(v10 + 26);
      }
      v10[12] = v13.LowPart;
      if ( !DirectoryEntry->FileNameLength )
        RtlAssert(
          v13.HighPart,
          v14,
          (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          (int)DirectoryEntry,
          "DirectoryEntry->FileNameLength != 0",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          0xA4u,
          0);
      if ( DirectoryEntry->FileNameLength > 0x2Au )
        RtlAssert(
          v13.HighPart,
          v14,
          (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          (int)DirectoryEntry,
          "DirectoryEntry->FileNameLength <= FAT_FILE_NAME_LENGTH",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          0xA5u,
          0);
      v16 = (char *)v10[12];
      *((_BYTE *)v10 + 2) = DirectoryEntry->FileNameLength;
      v17 = (unsigned __int8)DirectoryEntry->FileNameLength;
      qmemcpy(v16, DirectoryEntry->FileName, 4 * (v17 >> 2));
      v18 = &v16[4 * (v17 >> 2)];
      v19 = v17 & 3;
      qmemcpy(v18, &DirectoryEntry->FileName[4 * (v17 >> 2)], v19);
      v20 = (int *)&v18[v19];
      v10[11] = DirectoryByteOffset;
      ++ParentFcb->ReferenceCount;
      v21 = *((unsigned __int8 *)v10 + 2);
      v10[6] = (int)ParentFcb;
      v22 = (unsigned __int8)ParentFcb->PathNameLength + v21 + 1;
      *((_BYTE *)v10 + 1) = v22;
      if ( v22 > 0xFA )
        RtlAssert(
          v13.HighPart,
          v21,
          v20,
          (int)ParentFcb,
          "PathNameLength <= FAT_PATH_NAME_LIMIT",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          0xC3u,
          0);
      v23 = ParentFcb->File.FileMutex.LockCount;
      v10[4] = v23;
      v10[5] = (int)&ParentFcb->68;
      *(_DWORD *)(v23 + 4) = v10 + 4;
      ParentFcb->File.FileMutex.LockCount = (int)(v10 + 4);
    }
    else
    {
      *(_BYTE *)v10 |= 6u;
      v15 = *((_BYTE *)v10 + 1) == 0;
      *((_BYTE *)v10 + 3) = 16;
      if ( !v15 )
        RtlAssert(
          v11,
          v12,
          (int *)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          0,
          "Fcb->PathNameLength == 0",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
          0xD5u,
          0);
    }
    v24 = *(_BYTE *)v10 & 2;
    if ( v24 )
    {
      v10[19] = 0;
      v10[18] = (int)(v10 + 17);
      v10[17] = (int)(v10 + 17);
    }
    if ( v24 )
    {
      *((_BYTE *)v10 + 87) = 1;
      *((_BYTE *)v10 + 83) = 1;
    }
    else
    {
      v25 = 0;
      v26 = (char *)v10 + 127;
      do
      {
        v26[4] = v25 - 1;
        *v26 = v25++ + 1;
        v26 += 12;
      }
      while ( v25 < 0xA );
      *((_BYTE *)v10 + 131) = 9;
      *((_BYTE *)v10 + 235) = 0;
    }
    result = 0;
  }
  else
  {
    result = -1073741670;
  }
  *ReturnedFcb = (_FAT_FCB *)v10;
  return result;
}