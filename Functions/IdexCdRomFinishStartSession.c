void __usercall IdexCdRomFinishStartSession(char a1@<dl>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  _IRP *v4; // ecx
  _DWORD *v5; // edx

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0x6E3u,
      0);
  v4 = Irp;
  if ( Irp->IoStatus.Status >= 0 )
  {
    v5 = Irp->UserBuffer;
    *v5 = (unsigned int)(unsigned __int8)byte_80051307 >> 6;
    v4->IoStatus.Status = 0;
    LOBYTE(v5) = 1;
    IofCompleteRequest(v4, (int)v5, a3);
    dword_80051354();
  }
  else
  {
    IdexCdRomFinishGeneric(a1, a3, a4);
  }
}