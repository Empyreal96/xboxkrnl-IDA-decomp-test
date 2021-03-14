void __usercall IdexCdRomFinishGenericWithOverrun(char a1@<dl>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  _IRP *v4; // ecx
  _IO_STATUS_BLOCK *v5; // eax

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0x4EFu,
      0);
  v4 = Irp;
  v5 = &Irp->IoStatus;
  if ( Irp->IoStatus.Status == -1073741764 )
    v5->Status = 0;
  if ( v5->Status >= 0 )
  {
    v5->Status = 0;
    IofCompleteRequest(v4, 1, a3);
    dword_80051354();
  }
  else
  {
    IdexCdRomFinishGeneric(a1, a3, a4);
  }
}