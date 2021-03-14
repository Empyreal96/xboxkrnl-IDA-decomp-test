int __usercall IdexChannelAbortCurrentPacket@<eax>(char a1@<dl>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  _IRP *v4; // ecx

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x474u,
      0);
  v4 = Irp;
  Irp->IoStatus.Status = -1073741248;
  IofCompleteRequest(v4, 0, a3);
  return dword_80051354();
}