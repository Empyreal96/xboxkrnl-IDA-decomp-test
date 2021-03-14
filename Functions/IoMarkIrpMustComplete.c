void __userpurge IoMarkIrpMustComplete(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _IRP *Irp)
{
  _IO_STACK_LOCATION *v5; // ecx
  char v6; // al

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0x89Au,
      0);
  v5 = Irp->Tail.Overlay.CurrentStackLocation;
  v6 = v5->Control;
  if ( !(v6 & 2) )
  {
    v5->Control = v6 | 2;
    ++IoPendingMustCompletePackets;
  }
}