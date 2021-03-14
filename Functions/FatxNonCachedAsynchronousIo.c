int __userpurge FatxNonCachedAsynchronousIo@<eax>(int a1@<edx>, int a2@<esi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp, char MajorFunction, _FILE_OBJECT *FileObject, unsigned int FileByteOffset, unsigned int IoLength)
{
  int v8; // ecx
  _FAT_VOLUME_EXTENSION *v9; // edi
  unsigned int v10; // ebx
  int v11; // esi
  int v12; // ecx
  unsigned int v13; // eax
  int v14; // edx
  int *v15; // esi
  unsigned __int64 v16; // rax
  unsigned int v17; // ST0C_4
  _FAT_FCB *v18; // eax
  _FAT_FCB *v19; // ST08_4
  int v20; // ecx
  int v21; // ebx
  int v22; // ecx
  _FAT_ASYNC_IO_ENTRY *v23; // ecx
  int AdjacentPhysicalByteOffset; // [esp+Ch] [ebp-24h]
  unsigned __int64 StartingPhysicalByteOffset; // [esp+14h] [ebp-1Ch]
  unsigned __int64 PhysicalByteOffset; // [esp+1Ch] [ebp-14h]
  int status; // [esp+24h] [ebp-Ch]
  _FAT_ASYNC_IO_ENTRY *AsyncIoEntry; // [esp+28h] [ebp-8h]
  _FAT_FCB *Fcb; // [esp+2Ch] [ebp-4h]
  unsigned int IoLengthRemaining; // [esp+38h] [ebp+8h]

  v8 = IoLength;
  v9 = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  Fcb = (_FAT_FCB *)FileObject->FsContext;
  v10 = ~(v9->CacheExtension.SectorSize - 1) & (v9->CacheExtension.SectorSize + IoLength - 1);
  if ( !v10 )
    RtlAssert(
      a1,
      IoLength,
      (int *)v9,
      a2,
      "IoLengthRemaining > 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
      0x2AEu,
      0);
  v11 = FileByteOffset;
  if ( (v9->CacheExtension.SectorSize - 1) & FileByteOffset )
    RtlAssert(
      a1,
      v8,
      (int *)v9,
      FileByteOffset,
      "FatxIsSectorAligned(VolumeExtension, FileByteOffset)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
      0x2AFu,
      0);
  v12 = v9->BytesPerCluster - 1;
  v13 = 8 * (v10 >> v9->ClusterShift) + 32;
  if ( v12 & v11 )
    v13 = 8 * (v10 >> v9->ClusterShift) + 40;
  v15 = ExAllocatePoolWithTag(a1, v12, v11, v13, 0x64417446u);
  if ( v15 )
  {
    v15[3] = 0;
    v15[4] = 0;
    v17 = FileByteOffset;
    *v15 = (unsigned __int8)MajorFunction;
    v15[1] = IoLength;
    v18 = Fcb;
    v19 = Fcb;
    v15[2] = v10;
    v15[5] = (int)v18;
    LODWORD(v16) = FatxFileByteOffsetToPhysicalByteOffset(
                     v14,
                     (int)&PhysicalByteOffset,
                     (int *)v9,
                     v9,
                     Irp,
                     v19,
                     v17,
                     1,
                     &PhysicalByteOffset,
                     (unsigned int *)&FileObject);
    if ( (v16 & 0x80000000) == 0i64 )
    {
      AsyncIoEntry = (_FAT_ASYNC_IO_ENTRY *)(v15 + 6);
LABEL_11:
      v20 = PhysicalByteOffset;
      IoLength = 0;
      StartingPhysicalByteOffset = PhysicalByteOffset;
      while ( 1 )
      {
        LODWORD(v16) = FileObject;
        if ( (unsigned int)FileObject <= v10 )
        {
          v10 -= (unsigned int)FileObject;
          IoLengthRemaining = v10;
        }
        else
        {
          IoLengthRemaining = 0;
          LODWORD(v16) = v10;
          v10 = 0;
          FileObject = (_FILE_OBJECT *)v16;
        }
        IoLength += v16;
        FileByteOffset += v16;
        if ( !v10 )
          goto LABEL_21;
        v21 = ((unsigned int)v20 + __PAIR__(HIDWORD(PhysicalByteOffset), (unsigned int)v16)) >> 32;
        AdjacentPhysicalByteOffset = v20 + v16;
        status = FatxFileByteOffsetToPhysicalByteOffset(
                   SHIDWORD(v16),
                   v20,
                   (int *)v9,
                   v9,
                   Irp,
                   Fcb,
                   FileByteOffset,
                   1,
                   &PhysicalByteOffset,
                   (unsigned int *)&FileObject);
        if ( status < 0 )
          break;
        v20 = PhysicalByteOffset;
        if ( (_DWORD)PhysicalByteOffset != AdjacentPhysicalByteOffset || HIDWORD(PhysicalByteOffset) != v21 )
        {
          v10 = IoLengthRemaining;
LABEL_21:
          v22 = IoLength;
          if ( (v9->CacheExtension.SectorSize - 1) & IoLength )
            RtlAssert(
              SHIDWORD(v16),
              IoLength,
              (int *)v9,
              (int)v15,
              "FatxIsSectorAligned(VolumeExtension, PhysicalIoLength)",
              "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
              0x324u,
              0);
          if ( MajorFunction == 3 )
            FscInvalidateByteRange(
              SHIDWORD(v16),
              v22,
              (int *)v9,
              &v9->CacheExtension,
              StartingPhysicalByteOffset,
              IoLength);
          v16 = StartingPhysicalByteOffset >> v9->SectorShift;
          v23 = AsyncIoEntry;
          AsyncIoEntry->PhysicalSector = v16;
          v23->PhysicalIoLength = IoLength;
          AsyncIoEntry = v23 + 1;
          if ( !v10 )
          {
            *(_BYTE *)(Irp->Tail.Overlay.PacketType + 3) |= 1u;
            FatxStartNextAsynchronousIoEntry(v9, Irp, (_FAT_ASYNC_IO_DESCRIPTOR *)v15);
            LODWORD(v16) = 259;
            return v16;
          }
          goto LABEL_11;
        }
        v10 = IoLengthRemaining;
      }
      ExFreePool(v15);
      LODWORD(v16) = status;
    }
  }
  else
  {
    LODWORD(v16) = -1073741670;
  }
  return v16;
}