void __usercall IdexDiskStartFlushBuffers(_IRP *Irp@<ecx>, int a2@<edx>, int *a3@<edi>)
{
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx

  unk_8005135E = 0;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      (int)Irp,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0x3EAu,
      0);
  KfRaiseIrql(NewIrql);
  if ( IdexDiskSelectDeviceAndSpinWhileBusy(v3, v4, a3, (int)"d:\\xbox-apr03\\private\\ntos\\idex\\disk.c") )
  {
    LOWORD(v5) = 503;
    __outbyte(0x1F7u, 0xE7u);
    if ( IdexChannelObject.InterruptRoutine )
      RtlAssert(
        v5,
        v6,
        a3,
        (int)"d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        "IdexChannelObject.InterruptRoutine == NULL",
        "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        0x3FFu,
        0);
    IdexChannelObject.InterruptRoutine = (void (__stdcall *)())IdexDiskNoTransferInterrupt;
    dword_80051344 = (void (__stdcall *)(_KDPC *, void *, void *, void *))IdexDiskFinishGeneric;
    unk_8005135C = 30;
    KfLowerIrql(2);
  }
  else
  {
    IdexDiskFinishGeneric(v5, a3, (int)"d:\\xbox-apr03\\private\\ntos\\idex\\disk.c");
  }
}