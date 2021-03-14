void __userpurge IoLockUserBuffer(int a1@<edx>, int a2@<ecx>, int a3@<esi>, _IRP *Irp, unsigned int Length)
{
  if ( !Length )
    RtlAssert(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      a3,
      "Length != 0",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0x863u,
      0);
  if ( Irp->Flags & 0x600 )
  {
    if ( Irp->LockedBufferLength != Length )
      RtlAssert(
        a1,
        a2,
        (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        (int)Irp,
        "Irp->LockedBufferLength == Length",
        "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        0x87Au,
        0);
  }
  else
  {
    if ( !Irp->UserBuffer )
      RtlAssert(
        a1,
        a2,
        (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        (int)Irp,
        "Irp->UserBuffer != NULL",
        "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        0x871u,
        0);
    MmLockUnlockBufferPages(
      a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      (int)Irp,
      Irp->UserBuffer,
      Length,
      0);
    BYTE1(Irp->Flags) |= 2u;
    Irp->LockedBufferLength = Length;
  }
}