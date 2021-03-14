void __usercall IdexDiskFinishGeneric(char a1@<dl>, int *a2@<edi>, int a3@<esi>)
{
  int v3; // edx
  int v4; // ecx

  if ( Irp->IoStatus.Status == -1073741643 )
  {
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        a1,
        (int)Irp,
        a2,
        a3,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        0x1FAu,
        0);
    KfRaiseIrql(NewIrql);
    IdexDiskResetDevice(v3, v4, a2, a3);
  }
  else
  {
    IofCompleteRequest(Irp, 1, a2);
    dword_80051354();
  }
}