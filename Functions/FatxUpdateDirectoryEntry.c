int __userpurge FatxUpdateDirectoryEntry@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *Fcb)
{
  _FAT_FCB *v6; // ebx
  _FAT_FCB *v7; // eax
  int result; // eax
  int v9; // edx
  int v10; // ecx
  _FAT_FCB *v11; // esi
  char v12; // dl
  _FAT_FCB *v13; // eax
  char *v14; // esi
  unsigned int v15; // ecx
  char *v16; // edi
  char *v17; // esi
  int v18; // ecx
  int v19; // esi
  int v20; // edx
  int v21; // ecx
  unsigned __int64 PhysicalByteOffset; // [esp+Ch] [ebp-Ch]
  unsigned int PhysicalRunLength; // [esp+14h] [ebp-4h]

  v6 = Fcb;
  if ( Fcb->Flags & 5 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "FatxIsFlagClear(Fcb->Flags, FAT_FCB_VOLUME | FAT_FCB_ROOT_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x171u,
      0);
  if ( VolumeExtension->VolumeMutexExclusiveOwner != thread )
    RtlAssert(
      a1,
      a2,
      (int *)VolumeExtension,
      (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      "VolumeExtension->VolumeMutexExclusiveOwner == KeGetCurrentThread()",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
      0x172u,
      0);
  v7 = v6->ParentFcb;
  if ( !v7 )
    return -1073741566;
  result = FatxFileByteOffsetToPhysicalByteOffset(
             a1,
             (int)&PhysicalByteOffset,
             (int *)VolumeExtension,
             VolumeExtension,
             Irp,
             v7,
             v6->DirectoryByteOffset,
             0,
             &PhysicalByteOffset,
             &PhysicalRunLength);
  if ( result >= 0 )
  {
    result = FscMapBuffer(
               v9,
               v10,
               (int *)VolumeExtension,
               (int)"d:\\xbox-apr03\\private\\ntos\\fatx\\fcbsup.c",
               &VolumeExtension->CacheExtension,
               Irp,
               PhysicalByteOffset,
               1,
               (void **)&Fcb);
    if ( result >= 0 )
    {
      v11 = Fcb;
      Fcb->Flags = v6->FileNameLength;
      v12 = v6->FileNameLength;
      v13 = v11;
      v14 = v6->FileNameBuffer;
      v15 = (unsigned int)(unsigned __int8)v6->FileNameLength >> 2;
      qmemcpy(&v13->FileNameLength, v14, 4 * v15);
      v17 = &v14[4 * v15];
      v16 = &v13->FileNameLength + 4 * v15;
      v18 = v12 & 3;
      qmemcpy(v16, v17, v18);
      v19 = (int)&v17[v18];
      v13->PathNameLength = v6->FileAttributes;
      v13->DirectoryByteOffset = v6->FirstCluster;
      v13->FileNameBuffer = (char *)v6->FileSize;
      v13->LastWriteTime.LowPart = v6->CreationTime.AsULONG;
      v13->CreationTime.AsULONG = v6->LastAccessTime.AsULONG;
      FatxTimeToFatTimestamp(&v6->LastWriteTime, (_FAT_TIME_STAMP *)&v13->LastWriteTime.QuadPart + 1);
      result = FscWriteBuffer(v20, v21, v19, &VolumeExtension->CacheExtension, Irp, PhysicalByteOffset, 0x40u, Fcb);
      if ( result >= 0 )
        v6->Flags &= 0xBFu;
    }
  }
  return result;
}