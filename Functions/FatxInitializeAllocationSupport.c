int __userpurge FatxInitializeAllocationSupport@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp)
{
  _FAT_VOLUME_EXTENSION *v5; // edi
  unsigned int v6; // esi
  unsigned int v7; // ebx
  unsigned int v8; // esi
  void *v9; // eax
  char *v10; // ecx
  char *v11; // ecx
  int result; // eax
  int status; // [esp+Ch] [ebp-1Ch]
  void *CacheBuffer; // [esp+10h] [ebp-18h]
  int v15; // [esp+14h] [ebp-14h]
  unsigned int FirstAvailableClusterHint; // [esp+18h] [ebp-10h]
  unsigned int NumberOfClustersAvailable; // [esp+1Ch] [ebp-Ch]
  unsigned int FatByteOffset; // [esp+20h] [ebp-8h]
  unsigned int PageClustersRemaining; // [esp+24h] [ebp-4h]
  char FirstPage_3; // [esp+33h] [ebp+Bh]

  v5 = VolumeExtension;
  if ( VolumeExtension->FatByteOffset & 0xFFF )
    RtlAssert(
      a1,
      a2,
      (int *)VolumeExtension,
      a3,
      "BYTE_OFFSET(VolumeExtension->FatByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x3B7u,
      0);
  v6 = VolumeExtension->NumberOfClusters;
  status = 0;
  NumberOfClustersAvailable = 0;
  v7 = -1;
  v8 = v6 + 1;
  FirstPage_3 = 1;
  FirstAvailableClusterHint = -1;
  for ( FatByteOffset = 0; v8; v8 -= PageClustersRemaining )
  {
    status = FscMapBuffer(
               a1,
               (v5->FatByteOffset + FatByteOffset) >> 32,
               (int *)v5,
               v8,
               &v5->CacheExtension,
               Irp,
               v5->FatByteOffset + FatByteOffset,
               0,
               &CacheBuffer);
    if ( status < 0 )
      break;
    if ( v5->Flags & 2 )
    {
      PageClustersRemaining = 2048;
      if ( v8 < 0x800 )
        PageClustersRemaining = v8;
      v9 = CacheBuffer;
      v10 = (char *)CacheBuffer;
      if ( FirstPage_3 )
      {
        FirstPage_3 = 0;
        v10 = (char *)CacheBuffer + 2;
      }
      if ( v10 >= (char *)CacheBuffer + 2 * PageClustersRemaining )
        goto LABEL_30;
      FirstAvailableClusterHint = v10 - (_BYTE *)CacheBuffer;
      do
      {
        if ( !*(_WORD *)v10 )
        {
          if ( v7 == -1 )
            v7 = (FatByteOffset >> 1) + ((signed int)FirstAvailableClusterHint >> 1);
          ++NumberOfClustersAvailable;
        }
        FirstAvailableClusterHint += 2;
        v10 += 2;
      }
      while ( v10 < (char *)CacheBuffer + 2 * PageClustersRemaining );
    }
    else
    {
      PageClustersRemaining = 1024;
      if ( v8 < 0x400 )
        PageClustersRemaining = v8;
      v9 = CacheBuffer;
      v11 = (char *)CacheBuffer;
      if ( FirstPage_3 )
      {
        FirstPage_3 = 0;
        v11 = (char *)CacheBuffer + 4;
      }
      v7 = FirstAvailableClusterHint;
      if ( v11 >= (char *)CacheBuffer + 4 * PageClustersRemaining )
        goto LABEL_30;
      v15 = v11 - (_BYTE *)CacheBuffer;
      do
      {
        if ( !*(_DWORD *)v11 )
        {
          if ( v7 == -1 )
            v7 = (FatByteOffset >> 2) + (v15 >> 2);
          ++NumberOfClustersAvailable;
        }
        v15 += 4;
        v11 += 4;
      }
      while ( v11 < (char *)CacheBuffer + 4 * PageClustersRemaining );
    }
    FirstAvailableClusterHint = v7;
LABEL_30:
    FscUnmapBuffer((int *)v5, v8, v9);
    FatByteOffset += 4096;
  }
  v5->NumberOfClustersAvailable = NumberOfClustersAvailable;
  result = status;
  v5->FirstAvailableClusterHint = v7;
  return result;
}