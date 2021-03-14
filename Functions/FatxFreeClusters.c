char __userpurge FatxFreeClusters@<al>(int a1@<edx>, char a2@<cl>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, unsigned int ClusterNumber, char MarkFirstAsLast)
{
  _FAT_VOLUME_EXTENSION *v7; // esi
  unsigned int v8; // edi
  int v10; // edx
  char v11; // cl
  unsigned int v12; // edi
  unsigned int v13; // ebx
  int *v14; // edi
  unsigned int v15; // eax
  char v16; // cl
  char v17; // ST14_1
  int v18; // edx
  char v19; // cl
  unsigned int SectorSize; // [esp+8h] [ebp-1Ch]
  unsigned int FatEntryFreeValue; // [esp+Ch] [ebp-18h]
  int v22; // [esp+10h] [ebp-14h]
  unsigned int CacheBufferFatByteOffset; // [esp+14h] [ebp-10h]
  unsigned int CacheBufferClustersFreed; // [esp+18h] [ebp-Ch]
  unsigned int FirstAvailableClusterHint; // [esp+1Ch] [ebp-8h]
  void *CacheBuffer; // [esp+20h] [ebp-4h]
  bool FlushedFirstDirtySector_3; // [esp+2Fh] [ebp+Bh]
  char Result; // [esp+3Bh] [ebp+17h]

  v7 = VolumeExtension;
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)VolumeExtension,
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x2ACu,
      0);
  SectorSize = VolumeExtension->CacheExtension.SectorSize;
  v8 = SectorSize - 1;
  FirstAvailableClusterHint = VolumeExtension->FirstAvailableClusterHint;
  if ( VolumeExtension->FatByteOffset & 0xFFF )
    RtlAssert(
      a1,
      a2,
      (int *)v8,
      (int)VolumeExtension,
      "BYTE_OFFSET(VolumeExtension->FatByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
      0x2B8u,
      0);
  if ( ClusterNumber - 1 >= VolumeExtension->NumberOfClusters )
    return 0;
  v22 = ~v8;
  Result = 0;
  FatEntryFreeValue = -(MarkFirstAsLast != 0);
  FlushedFirstDirtySector_3 = MarkFirstAsLast == 0;
  v10 = 0;
  CacheBuffer = 0;
  CacheBufferFatByteOffset = 0;
  CacheBufferClustersFreed = 0;
  while ( 1 )
  {
    v11 = v7->FatEntryShift;
    v12 = ClusterNumber << v11;
    v13 = (ClusterNumber << v11) & v22;
    if ( !CacheBuffer )
      goto LABEL_15;
    if ( v10 != v13 )
      break;
LABEL_17:
    v14 = (int *)((char *)CacheBuffer + ((SectorSize - 1) & v12));
    if ( ClusterNumber < FirstAvailableClusterHint && !FatEntryFreeValue )
      FirstAvailableClusterHint = ClusterNumber;
    if ( v7->Flags & 2 )
    {
      LOWORD(v15) = *(_WORD *)v14;
      if ( *(_WORD *)v14 >= 0xFFF0u )
        v15 = (signed __int16)v15;
      else
        v15 = (unsigned __int16)v15;
    }
    else
    {
      v15 = *v14;
    }
    ClusterNumber = v15;
    if ( v7->Flags & 2 )
      *(_WORD *)v14 = FatEntryFreeValue;
    else
      *v14 = FatEntryFreeValue;
    if ( !FatEntryFreeValue )
      ++CacheBufferClustersFreed;
    FatEntryFreeValue = 0;
    v16 = v15 - 1;
    if ( v15 - 1 >= v7->NumberOfClusters )
    {
      if ( v15 != -1 )
      {
        DbgPrint(v14, "FATX: corrupt FAT chain found while freeing clusters\n");
        v10 = CacheBufferFatByteOffset;
        v16 = v17;
      }
      if ( !CacheBuffer )
      {
        RtlAssert(
          v10,
          v16,
          v14,
          (int)v7,
          "CacheBuffer != NULL",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
          0x36Cu,
          0);
        v10 = CacheBufferFatByteOffset;
      }
      if ( FscWriteBuffer(
             LODWORD(v7->FatByteOffset) + v10,
             v16,
             (int)v7,
             &v7->CacheExtension,
             Irp,
             v7->FatByteOffset + (unsigned int)v10,
             SectorSize,
             CacheBuffer) >= 0 )
      {
        v7->FirstAvailableClusterHint = FirstAvailableClusterHint;
        v7->NumberOfClustersAvailable += CacheBufferClustersFreed;
        Result = 1;
      }
      if ( v7->NumberOfClustersAvailable >= v7->NumberOfClusters )
        RtlAssert(
          v18,
          v19,
          v14,
          (int)v7,
          "VolumeExtension->NumberOfClustersAvailable < VolumeExtension->NumberOfClusters",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\allocsup.c",
          0x38Bu,
          0);
      return Result;
    }
  }
  if ( FscWriteBuffer(
         LODWORD(v7->FatByteOffset) + v10,
         v11,
         (int)v7,
         &v7->CacheExtension,
         Irp,
         v7->FatByteOffset + (unsigned int)v10,
         SectorSize,
         CacheBuffer) >= 0 )
  {
    v7->FirstAvailableClusterHint = FirstAvailableClusterHint;
    v7->NumberOfClustersAvailable += CacheBufferClustersFreed;
    Result = 1;
LABEL_14:
    CacheBufferClustersFreed = 0;
    FlushedFirstDirtySector_3 = 1;
LABEL_15:
    if ( FscMapBuffer(
           v10,
           (v7->FatByteOffset + v13) >> 32,
           (int *)v12,
           (int)v7,
           &v7->CacheExtension,
           Irp,
           v7->FatByteOffset + v13,
           1,
           &CacheBuffer) < 0 )
      return Result;
    CacheBufferFatByteOffset = v13;
    v10 = v13;
    goto LABEL_17;
  }
  if ( FlushedFirstDirtySector_3 )
  {
    FirstAvailableClusterHint = v7->FirstAvailableClusterHint;
    goto LABEL_14;
  }
  return 0;
}