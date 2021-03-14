void __usercall IdexCdRomFinishGetDriveGeometry(char a1@<dl>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  _IRP *v4; // edi
  ULONG v5; // esi
  _DWORD *v6; // eax
  int *v7; // [esp-4h] [ebp-4h]

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0x5B1u,
      0);
  v7 = a3;
  v4 = Irp;
  if ( Irp->IoStatus.Status >= 0 )
  {
    v5 = RtlUlongByteSwap(IdexCdRomStaticTransferBuffer) + 1;
    IdexCdRomPartitionLength = (unsigned __int64)v5 << 11;
    v6 = v4->UserBuffer;
    v6[1] = 0;
    *v6 = v5;
    v6[2] = 11;
    v6[3] = 1;
    v6[4] = 1;
    v6[5] = 2048;
    v4->IoStatus.Status = 0;
    IofCompleteRequest(v4, 1, (int *)&v4->Type);
    dword_80051354();
  }
  else
  {
    IdexCdRomFinishGeneric(a1, v7, a4);
  }
}