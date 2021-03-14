int __userpurge FatxFileByteOffsetToPhysicalByteOffset@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_FCB *Fcb, unsigned int FileByteOffset, char AcquireVolumeMutexShared, unsigned __int64 *ReturnedPhysicalByteOffset, unsigned int *ReturnedPhysicalRunLength)
{
  _FAT_VOLUME_EXTENSION *v10; // esi
  int v11; // ebx
  unsigned int v12; // edi

  v10 = VolumeExtension;
  if ( AcquireVolumeMutexShared )
    FatxAcquireVolumeMutexShared(a1, a2, a3, VolumeExtension);
  v11 = FatxFileByteOffsetToCluster(
          a1,
          a2,
          (int)v10,
          v10,
          Irp,
          Fcb,
          FileByteOffset,
          (unsigned int *)&VolumeExtension,
          (unsigned int *)&Fcb);
  if ( AcquireVolumeMutexShared )
    FatxReleaseVolumeMutex(v10);
  if ( v11 < 0 )
  {
    if ( v11 == -1073741807 )
      v11 = -1073741566;
  }
  else
  {
    v12 = FileByteOffset & (v10->BytesPerCluster - 1);
    *ReturnedPhysicalByteOffset = v12
                                + v10->FileAreaByteOffset
                                + ((unsigned __int64)((unsigned int)&VolumeExtension[-1].VolumeMutexExclusiveOwner + 3) << v10->ClusterShift);
    *ReturnedPhysicalRunLength = ((_DWORD)Fcb << v10->ClusterShift) - v12;
  }
  return v11;
}