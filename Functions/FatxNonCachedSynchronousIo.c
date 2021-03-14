int __fastcall FatxNonCachedSynchronousIo(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp, char MajorFunction, _FILE_OBJECT *FileObject, unsigned int FileByteOffset, unsigned int BufferByteOffset, unsigned int IoLength, char PartialTransfer)
{
  _FAT_VOLUME_EXTENSION *v10; // ebx
  _IO_STACK_LOCATION *v11; // esi
  int v12; // esi
  int *v13; // edi
  int v14; // ecx
  int result; // eax
  int v16; // edx
  int v17; // ecx
  unsigned int v18; // eax
  int *v19; // edi
  int v20; // ecx
  unsigned int v21; // eax
  int v22; // ecx
  _IRP *v23; // ecx
  _KEVENT IoEvent; // [esp+Ch] [ebp-38h]
  unsigned __int64 AdjacentPhysicalByteOffset; // [esp+1Ch] [ebp-28h]
  unsigned __int64 StartingPhysicalByteOffset; // [esp+24h] [ebp-20h]
  unsigned __int64 PhysicalByteOffset; // [esp+2Ch] [ebp-18h]
  unsigned int OriginalFileByteOffset; // [esp+34h] [ebp-10h]
  _FAT_FCB *Fcb; // [esp+38h] [ebp-Ch]
  unsigned int PhysicalRunLength; // [esp+3Ch] [ebp-8h]
  unsigned int IoLengthRemaining; // [esp+40h] [ebp-4h]
  unsigned int PhysicalIoLength; // [esp+4Ch] [ebp+8h]

  v10 = (_FAT_VOLUME_EXTENSION *)DeviceObject->DeviceExtension;
  Fcb = (_FAT_FCB *)FileObject->FsContext;
  v11 = Irp->Tail.Overlay.CurrentStackLocation;
  OriginalFileByteOffset = FileByteOffset;
  v12 = (int)&v11[-1];
  v13 = (int *)(~(v10->CacheExtension.SectorSize - 1) & (v10->CacheExtension.SectorSize + IoLength - 1));
  if ( !v13 )
    RtlAssert(
      a2,
      IoLength,
      0,
      v12,
      "IoLengthRemaining > 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
      0x134u,
      0);
  v14 = FileByteOffset;
  if ( (v10->CacheExtension.SectorSize - 1) & FileByteOffset )
    RtlAssert(
      a2,
      FileByteOffset,
      v13,
      v12,
      "FatxIsSectorAligned(VolumeExtension, FileByteOffset)",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
      0x135u,
      0);
  result = FatxFileByteOffsetToPhysicalByteOffset(
             a2,
             v14,
             v13,
             v10,
             Irp,
             Fcb,
             FileByteOffset,
             1,
             &PhysicalByteOffset,
             &PhysicalRunLength);
  if ( result >= 0 )
  {
    while ( 1 )
    {
      v17 = PhysicalByteOffset;
      PhysicalIoLength = 0;
      StartingPhysicalByteOffset = PhysicalByteOffset;
      while ( 1 )
      {
        v18 = PhysicalRunLength;
        if ( PhysicalRunLength <= (unsigned int)v13 )
        {
          v13 = (int *)((char *)v13 - PhysicalRunLength);
          IoLengthRemaining = (unsigned int)v13;
        }
        else
        {
          IoLengthRemaining = 0;
          v18 = (unsigned int)v13;
          v13 = 0;
          PhysicalRunLength = v18;
        }
        PhysicalIoLength += v18;
        FileByteOffset += v18;
        if ( !v13 )
          break;
        v19 = (int *)((__PAIR__(HIDWORD(PhysicalByteOffset), v17) + v18) >> 32);
        LODWORD(AdjacentPhysicalByteOffset) = v17 + v18;
        result = FatxFileByteOffsetToPhysicalByteOffset(
                   v16,
                   v17,
                   v19,
                   v10,
                   Irp,
                   Fcb,
                   FileByteOffset,
                   1,
                   &PhysicalByteOffset,
                   &PhysicalRunLength);
        if ( result < 0 )
          return result;
        v17 = PhysicalByteOffset;
        if ( (_DWORD)PhysicalByteOffset != (_DWORD)AdjacentPhysicalByteOffset
          || (int *)HIDWORD(PhysicalByteOffset) != v19 )
        {
          v13 = (int *)IoLengthRemaining;
          break;
        }
        v13 = (int *)IoLengthRemaining;
      }
      if ( MajorFunction == 3 )
        FscInvalidateByteRange(v16, v17, v13, &v10->CacheExtension, StartingPhysicalByteOffset, PhysicalIoLength);
      IoEvent.Header.SignalState = 0;
      v20 = BufferByteOffset;
      IoEvent.Header.WaitListHead.Blink = &IoEvent.Header.WaitListHead;
      IoEvent.Header.WaitListHead.Flink = &IoEvent.Header.WaitListHead;
      IoEvent.Header.Type = 1;
      IoEvent.Header.Size = 4;
      *(_QWORD *)(v12 + 12) = StartingPhysicalByteOffset;
      BufferByteOffset += PhysicalIoLength;
      *(_DWORD *)(v12 + 4) = PhysicalIoLength;
      *(_DWORD *)v12 = (unsigned __int8)MajorFunction;
      *(_DWORD *)(v12 + 8) = v20;
      if ( !FscSignalIoEventCompletion )
        RtlAssert(
          v16,
          v20,
          v13,
          v12,
          "(1) | (1) | (1) ? (FatxSignalIoEventCompletion) != NULL : TRUE",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
          0x1B6u,
          (char *)FscSignalIoEventCompletion);
      v21 = Irp->Tail.Overlay.PacketType - 36;
      *(_DWORD *)(v21 + 28) = FscSignalIoEventCompletion;
      *(_DWORD *)(v21 + 32) = &IoEvent;
      *(_BYTE *)(v21 + 3) = -32;
      result = IofCallDriver(v10->CacheExtension.TargetDeviceObject, Irp);
      if ( result == 259 )
      {
        KeWaitForSingleObject(v22, v16, &IoEvent, 0, 0, 0, 0);
        result = Irp->IoStatus.Status;
      }
      if ( result < 0 )
        break;
      v23 = Irp;
      if ( Irp->IoStatus.Information != PhysicalIoLength )
        RtlAssert(
          v16,
          (int)Irp,
          v13,
          v12,
          "Irp->IoStatus.Information == PhysicalIoLength",
          "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
          0x1CBu,
          0);
      if ( !v13 )
      {
        if ( PartialTransfer )
          result = 0;
        else
          result = FatxSynchronousIoTail(
                     (int)v23,
                     v16,
                     v10,
                     Irp,
                     MajorFunction,
                     FileObject,
                     OriginalFileByteOffset,
                     IoLength);
        return result;
      }
    }
  }
  return result;
}