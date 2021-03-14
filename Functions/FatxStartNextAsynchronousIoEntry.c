void __stdcall FatxStartNextAsynchronousIoEntry(_FAT_VOLUME_EXTENSION *VolumeExtension, _IRP *Irp, _FAT_ASYNC_IO_DESCRIPTOR *AsyncIoDescriptor)
{
  _FAT_ASYNC_IO_DESCRIPTOR *v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // edi
  int v6; // ebx
  int v7; // ecx
  unsigned __int64 v8; // rax
  unsigned int v9; // eax

  v3 = AsyncIoDescriptor;
  v4 = AsyncIoDescriptor->NextAsyncIoEntry;
  v5 = Irp->Tail.Overlay.PacketType - 36;
  AsyncIoDescriptor->NextAsyncIoEntry = v4 + 1;
  v6 = *(&AsyncIoDescriptor[1].IoLength + 2 * v4);
  v3->IoLengthRemaining -= v6;
  v7 = (unsigned __int8)VolumeExtension->SectorShift;
  v8 = (unsigned __int64)*(&AsyncIoDescriptor[1].MajorFunction + 2 * v4) << v7;
  *(_QWORD *)(v5 + 12) = v8;
  *(_DWORD *)(v5 + 4) = v6;
  *(_DWORD *)(v5 + 8) = AsyncIoDescriptor->BufferOffset;
  LODWORD(v8) = AsyncIoDescriptor->MajorFunction;
  v3->BufferOffset += v6;
  *(_DWORD *)v5 = v8;
  if ( !FatxNonCachedAsynchronousIoCompletion )
    RtlAssert(
      SHIDWORD(v8),
      v7,
      (int *)FatxNonCachedAsynchronousIoCompletion,
      (int)AsyncIoDescriptor,
      "(1) | (1) | (1) ? (FatxNonCachedAsynchronousIoCompletion) != NULL : TRUE",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\readwrit.c",
      0x26Fu,
      (char *)FatxNonCachedAsynchronousIoCompletion);
  v9 = Irp->Tail.Overlay.PacketType - 36;
  *(_DWORD *)(v9 + 28) = FatxNonCachedAsynchronousIoCompletion;
  *(_DWORD *)(v9 + 32) = AsyncIoDescriptor;
  *(_BYTE *)(v9 + 3) = -32;
  IofCallDriver(VolumeExtension->CacheExtension.TargetDeviceObject, Irp);
}