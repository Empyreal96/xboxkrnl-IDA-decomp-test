int __fastcall FatxFullyCachedSynchronousIo(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp, char MajorFunction, _FILE_OBJECT *FileObject, unsigned int FileByteOffset, unsigned int BufferByteOffset, unsigned int IoLength, char PartialTransfer)
{
  _IRP *v10; // ecx
  _FAT_VOLUME_EXTENSION *v11; // ebx
  unsigned int v12; // esi
  char *v13; // edi
  int result; // eax
  int v15; // ecx
  unsigned int v16; // ebx
  int v17; // edx
  int v18; // edx
  char *v19; // esi
  _DEVICE_OBJECT *v20; // edi
  char *v21; // edi
  char *v22; // esi
  int v23; // ecx
  int *v24; // edi
  int v25; // edx
  int v26; // ecx
  _DEVICE_OBJECT *v27; // esi
  char *v28; // edi
  char *v29; // esi
  int v30; // ecx
  unsigned __int64 PhysicalByteOffset; // [esp+Ch] [ebp-20h]
  unsigned int OriginalFileByteOffset; // [esp+14h] [ebp-18h]
  unsigned int PhysicalRunLength; // [esp+18h] [ebp-14h]
  _FAT_FCB *Fcb; // [esp+1Ch] [ebp-10h]
  unsigned int IoLengthRemaining; // [esp+20h] [ebp-Ch]
  void *UserBuffer; // [esp+24h] [ebp-8h]
  _FAT_VOLUME_EXTENSION *VolumeExtension; // [esp+28h] [ebp-4h]

  v10 = Irp;
  v11 = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  v12 = FileByteOffset;
  v13 = (char *)Irp->UserBuffer + BufferByteOffset;
  Fcb = (_FAT_FCB *)FileObject->FsContext;
  VolumeExtension = v11;
  OriginalFileByteOffset = FileByteOffset;
  IoLengthRemaining = IoLength;
  UserBuffer = v13;
  if ( !IoLength )
    RtlAssert(
      a2,
      (int)Irp,
      (int *)v13,
      FileByteOffset,
      "IoLengthRemaining > 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
      0x388u,
      0);
  result = FatxFileByteOffsetToPhysicalByteOffset(
             a2,
             (int)v10,
             (int *)v13,
             v11,
             Irp,
             Fcb,
             v12,
             1,
             &PhysicalByteOffset,
             &PhysicalRunLength);
  if ( result >= 0 )
  {
LABEL_4:
    BufferByteOffset = PhysicalRunLength;
    while ( 1 )
    {
      v15 = 4096;
      v16 = 4096 - (PhysicalByteOffset & 0xFFF);
      if ( v16 >= BufferByteOffset )
      {
        v16 = BufferByteOffset;
        BufferByteOffset = 0;
      }
      else
      {
        BufferByteOffset -= v16;
      }
      v17 = IoLengthRemaining;
      if ( v16 > IoLengthRemaining )
        v16 = IoLengthRemaining;
      if ( MajorFunction == 3 )
      {
        if ( v16 != 4096
          && ((v15 = FileByteOffset, FileByteOffset & 0xFFF)
           || (v17 = FileByteOffset + IoLengthRemaining, FileByteOffset + IoLengthRemaining < Fcb->FileSize)) )
        {
          result = FscMapBuffer(
                     v17,
                     FileByteOffset,
                     (int *)v13,
                     PhysicalByteOffset,
                     &VolumeExtension->CacheExtension,
                     Irp,
                     PhysicalByteOffset,
                     1,
                     (void **)&DeviceObject);
        }
        else
        {
          result = FscMapEmptyBuffer(
                     v17,
                     v15,
                     (int *)v13,
                     PhysicalByteOffset,
                     &VolumeExtension->CacheExtension,
                     PhysicalByteOffset,
                     (void **)&DeviceObject);
        }
        if ( result < 0 )
          return result;
        v19 = v13;
        v20 = DeviceObject;
        qmemcpy(DeviceObject, v19, 4 * (v16 >> 2));
        v22 = &v19[4 * (v16 >> 2)];
        v21 = (char *)v20 + 4 * (v16 >> 2);
        v23 = v16 & 3;
        qmemcpy(v21, v22, v23);
        v24 = (int *)&v21[v23];
        result = FscWriteBuffer(
                   v18,
                   0,
                   (int)&v22[v23],
                   &VolumeExtension->CacheExtension,
                   Irp,
                   PhysicalByteOffset,
                   v16,
                   DeviceObject);
        if ( result < 0 )
          return result;
      }
      else
      {
        result = FscMapBuffer(
                   IoLengthRemaining,
                   4096,
                   (int *)v13,
                   PhysicalByteOffset,
                   &VolumeExtension->CacheExtension,
                   Irp,
                   PhysicalByteOffset,
                   0,
                   (void **)&DeviceObject);
        if ( result < 0 )
          return result;
        v27 = DeviceObject;
        qmemcpy(v13, DeviceObject, 4 * (v16 >> 2));
        v29 = (char *)v27 + 4 * (v16 >> 2);
        v28 = &v13[4 * (v16 >> 2)];
        v30 = v16 & 3;
        qmemcpy(v28, v29, v30);
        v24 = (int *)&v28[v30];
        FscUnmapBuffer(v24, (int)&v29[v30], DeviceObject);
      }
      result = 0;
      PhysicalByteOffset += v16;
      IoLengthRemaining -= v16;
      if ( !IoLengthRemaining )
        break;
      FileByteOffset += v16;
      UserBuffer = (char *)UserBuffer + v16;
      if ( BufferByteOffset <= 0 )
      {
        result = FatxFileByteOffsetToPhysicalByteOffset(
                   v25,
                   v26,
                   v24,
                   VolumeExtension,
                   Irp,
                   Fcb,
                   FileByteOffset,
                   1,
                   &PhysicalByteOffset,
                   &PhysicalRunLength);
        if ( result < 0 )
          return result;
        v13 = (char *)UserBuffer;
        goto LABEL_4;
      }
      v13 = (char *)UserBuffer;
    }
    if ( !PartialTransfer )
      result = FatxSynchronousIoTail(
                 v26,
                 v25,
                 VolumeExtension,
                 Irp,
                 MajorFunction,
                 FileObject,
                 OriginalFileByteOffset,
                 IoLength);
  }
  return result;
}