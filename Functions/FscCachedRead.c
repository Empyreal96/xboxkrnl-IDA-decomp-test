int __fastcall FscCachedRead(int a1, int a2, _FSCACHE_EXTENSION *CacheExtension, _IRP *Irp, unsigned __int64 ByteOffset, unsigned int ReadLength, char NonCachedEndOfFileTransfer)
{
  unsigned int v7; // ebx
  _IRP *v8; // esi
  _IO_STACK_LOCATION *v9; // edi
  int v10; // edx
  int v11; // ecx
  int result; // eax
  int v13; // eax
  unsigned int v14; // ecx
  char *v15; // esi
  void *v16; // ST18_4
  char v17; // al
  unsigned int v18; // ecx
  char *v19; // edi
  char *v20; // esi
  int v21; // ecx
  _FILE_OBJECT *v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // eax
  unsigned int v26; // edi
  char *v27; // esi
  void *v28; // ST18_4
  char v29; // al
  char *v30; // edi
  char *v31; // esi
  int v32; // ecx
  unsigned int PartialIoLength; // [esp+Ch] [ebp-10h]
  _IO_STACK_LOCATION *IrpSp; // [esp+10h] [ebp-Ch]
  char *BufferByteOffset; // [esp+14h] [ebp-8h]
  unsigned int BufferByteOffseta; // [esp+14h] [ebp-8h]
  void *CacheBuffer; // [esp+18h] [ebp-4h]
  unsigned int BytesToCopy; // [esp+38h] [ebp+1Ch]

  v7 = ReadLength;
  v8 = Irp;
  v9 = Irp->Tail.Overlay.CurrentStackLocation;
  IrpSp = v9;
  BufferByteOffset = (char *)Irp->UserBuffer;
  if ( FscTestForFullyCachedIo(
         a2,
         a1,
         (int *)&v9->MajorFunction,
         Irp,
         ByteOffset,
         ReadLength,
         NonCachedEndOfFileTransfer) )
  {
    while ( 1 )
    {
      result = FscMapBuffer(
                 v10,
                 v11,
                 (int *)&v9->MajorFunction,
                 (int)v8,
                 CacheExtension,
                 v8,
                 ByteOffset,
                 0,
                 &CacheBuffer);
      if ( result < 0 )
        break;
      v13 = ByteOffset & 0xFFF;
      v14 = 4096 - v13;
      BytesToCopy = 4096 - v13;
      if ( 4096 - v13 > v7 )
      {
        BytesToCopy = v7;
        v14 = v7;
      }
      v15 = (char *)CacheBuffer;
      v16 = CacheBuffer;
      v17 = v14;
      v18 = v14 >> 2;
      qmemcpy(BufferByteOffset, CacheBuffer, 4 * v18);
      v20 = &v15[4 * v18];
      v19 = &BufferByteOffset[4 * v18];
      v21 = v17 & 3;
      qmemcpy(v19, v20, v21);
      v9 = (_IO_STACK_LOCATION *)&v19[v21];
      FscUnmapBuffer((int *)&v9->MajorFunction, (int)&v20[v21], v16);
      v8 = Irp;
      v11 = (ByteOffset + 4096) >> 32;
      LODWORD(ByteOffset) = (ByteOffset + 4096) & 0xFFFFF000;
      BufferByteOffset += BytesToCopy;
      v7 -= BytesToCopy;
      HIDWORD(ByteOffset) = v11;
      if ( !v7 )
      {
        v9 = IrpSp;
        goto LABEL_7;
      }
    }
  }
  else
  {
    IoLockUserBuffer(v10, v11, (int)Irp, Irp, *(_DWORD *)(Irp->Tail.Overlay.PacketType + 4));
    v25 = ByteOffset & 0xFFF;
    if ( ByteOffset & 0xFFF )
    {
      v26 = 4096 - v25;
      PartialIoLength = 4096 - v25;
      if ( 4096 - v25 >= ReadLength )
        RtlAssert(
          v23,
          v24,
          (int *)v26,
          (int)Irp,
          "PartialIoLength < BytesRemaining",
          "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
          0x7CCu,
          0);
      result = FscMapBuffer(v23, v24, (int *)v26, (int)Irp, CacheExtension, Irp, ByteOffset, 0, &CacheBuffer);
      if ( result < 0 )
        return result;
      v27 = (char *)CacheBuffer;
      v28 = CacheBuffer;
      v29 = v26;
      qmemcpy(BufferByteOffset, CacheBuffer, 4 * (v26 >> 2));
      v31 = &v27[4 * (v26 >> 2)];
      v30 = &BufferByteOffset[4 * (v26 >> 2)];
      v32 = v29 & 3;
      qmemcpy(v30, v31, v32);
      FscUnmapBuffer((int *)&v30[v32], (int)&v31[v32], v28);
      v8 = Irp;
      v9 = IrpSp;
      v7 = ReadLength - PartialIoLength;
      BufferByteOffseta = PartialIoLength;
      ByteOffset += PartialIoLength;
    }
    else
    {
      BufferByteOffseta = 0;
    }
    if ( ByteOffset & 0xFFF )
      RtlAssert(
        v23,
        v24,
        (int *)&v9->MajorFunction,
        (int)v8,
        "BYTE_OFFSET(ByteOffset) == 0",
        "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c",
        0x7EDu,
        0);
    result = FscPartiallyCachedRead(
               v23,
               v24,
               (int)v8,
               CacheExtension,
               v8,
               ByteOffset,
               v7,
               BufferByteOffseta,
               NonCachedEndOfFileTransfer);
    if ( result >= 0 )
    {
LABEL_7:
      v22 = v9->FileObject;
      if ( v22->Flags & 1 )
        v22->CurrentByteOffset.QuadPart = v9->Parameters.Read.ByteOffset.QuadPart + ReadLength;
      v8->IoStatus.Information = ReadLength;
      result = 0;
    }
  }
  return result;
}