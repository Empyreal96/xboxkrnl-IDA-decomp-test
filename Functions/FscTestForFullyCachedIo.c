char __userpurge FscTestForFullyCachedIo@<al>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _IRP *Irp, unsigned int ByteOffsetLowPart, unsigned int IoLength, char NonCachedEndOfFileTransfer)
{
  _IO_STACK_LOCATION *v7; // eax
  unsigned int v8; // ecx
  unsigned int v9; // ecx

  if ( !IoLength )
    RtlAssert(a1, a2, a3, 0, "IoLength != 0", "d:\\xbox-apr03\\private\\ntos\\mmx\\fscache.c", 0x689u, 0);
  v7 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v7->FileObject->Flags & 0x40 )
    return 1;
  v8 = v7->DeviceObject->AlignmentRequirement;
  if ( v8 & v7->Parameters.Read.ByteOffset.LowPart || v8 & (_DWORD)Irp->UserBuffer & 0xFFF )
    return 1;
  if ( !NonCachedEndOfFileTransfer )
  {
    if ( IoLength < 0x1000 )
      return 1;
    v9 = (ByteOffsetLowPart + 4095) ^ (ByteOffsetLowPart + IoLength);
    goto LABEL_12;
  }
  if ( !(ByteOffsetLowPart & 0xFFF) )
    return 0;
  if ( (ByteOffsetLowPart + IoLength) & 0xFFF )
  {
    v9 = ByteOffsetLowPart ^ (ByteOffsetLowPart + IoLength);
LABEL_12:
    if ( v9 & 0xFFFFF000 )
      return 0;
  }
  return 1;
}