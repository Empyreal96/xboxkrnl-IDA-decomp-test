int __fastcall FatxPartiallyCachedSynchronousIo(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp, char MajorFunction, _FILE_OBJECT *FileObject, unsigned int FileByteOffset, unsigned int IoLength, char NonCachedEndOfFileTransfer)
{
  int v9; // ecx
  unsigned int v10; // edi
  int v11; // esi
  int v12; // eax
  int result; // eax
  unsigned int v14; // ebx
  unsigned int v15; // esi
  int v16; // edx
  int v17; // ecx
  unsigned int OriginalFileByteOffset; // [esp+Ch] [ebp-8h]
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+10h] [ebp-4h]
  unsigned int OriginalIoLength; // [esp+2Ch] [ebp+18h]
  unsigned int IoLengtha; // [esp+30h] [ebp+1Ch]

  v9 = IoLength;
  v10 = FileByteOffset;
  v11 = 4095;
  VolumeExtension = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  OriginalFileByteOffset = FileByteOffset;
  OriginalIoLength = IoLength;
  if ( *((_DWORD *)DeviceObject->DeviceExtension + 11) & 0xFFF )
    RtlAssert(
      a2,
      IoLength,
      (int *)v10,
      4095,
      "BYTE_OFFSET(VolumeExtension->FileAreaByteOffset) == 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
      0x467u,
      0);
  v12 = v10 & 0xFFF;
  if ( !(v10 & 0xFFF) )
  {
    v14 = 0;
    goto LABEL_9;
  }
  v11 = 4096 - v12;
  if ( 4096 - v12 >= IoLength )
    RtlAssert(
      a2,
      v9,
      (int *)v10,
      v11,
      "PartialIoLength < IoLength",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
      0x471u,
      0);
  result = FatxFullyCachedSynchronousIo(v9, a2, DeviceObject, Irp, MajorFunction, FileObject, v10, 0, v11, 1);
  if ( result >= 0 )
  {
    IoLength -= v11;
    v10 += v11;
    v14 = v11;
LABEL_9:
    if ( NonCachedEndOfFileTransfer )
    {
      if ( MajorFunction != 2 )
        RtlAssert(
          a2,
          v9,
          (int *)v10,
          v11,
          "MajorFunction == IRP_MJ_READ",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
          0x489u,
          0);
      v9 = IoLength;
      v15 = ~(VolumeExtension->CacheExtension.SectorSize - 1) & (VolumeExtension->CacheExtension.SectorSize
                                                               + IoLength
                                                               - 1);
      IoLength = ~(VolumeExtension->CacheExtension.SectorSize - 1) & (VolumeExtension->CacheExtension.SectorSize
                                                                    + IoLength
                                                                    - 1);
    }
    else
    {
      if ( IoLength < 0x1000 )
        RtlAssert(
          a2,
          v9,
          (int *)v10,
          IoLength,
          "IoLength >= PAGE_SIZE",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
          0x48Du,
          0);
      v15 = IoLength & 0xFFFFF000;
    }
    result = FatxNonCachedSynchronousIo(v9, a2, DeviceObject, Irp, MajorFunction, FileObject, v10, v14, v15, 1);
    if ( result >= 0 )
    {
      IoLengtha = IoLength - v15;
      if ( IoLengtha )
        result = FatxFullyCachedSynchronousIo(
                   v17,
                   v16,
                   DeviceObject,
                   Irp,
                   MajorFunction,
                   FileObject,
                   v10 + v15,
                   v15 + v14,
                   IoLengtha,
                   1);
      if ( result >= 0 )
        result = FatxSynchronousIoTail(
                   v17,
                   v16,
                   VolumeExtension,
                   Irp,
                   MajorFunction,
                   FileObject,
                   OriginalFileByteOffset,
                   OriginalIoLength);
    }
  }
  return result;
}