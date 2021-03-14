void __userpurge FatxDpcReleaseFileMutex(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _FAT_FCB *FileFcb)
{
  if ( FileFcb->Flags & 3 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)FileFcb,
      "FatxIsFlagClear(FileFcb->Flags, FAT_FCB_VOLUME | FAT_FCB_DIRECTORY)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\synch.c",
      0x14Eu,
      0);
  if ( FileFcb->File.FileMutex.LockCount >= 0 && !FileFcb->File.FileMutex.ReadersEntryCount )
    FileFcb->File.FileMutexExclusiveOwner = 0;
  ExReleaseReadWriteLock((int)&FileFcb->68);
}