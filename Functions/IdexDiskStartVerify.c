void __fastcall IdexDiskStartVerify(_IRP *Irp, int a2)
{
  _IO_STACK_LOCATION *v2; // esi
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  int v6; // ecx

  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      (int)Irp,
      (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      (int)v2,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0x222u,
      0);
  KfRaiseIrql(NewIrql);
  if ( IdexDiskSelectDeviceAndSpinWhileBusy(v3, v4, (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\disk.c", (int)v2) )
  {
    __outbyte(0x1F6u, *((_BYTE *)&v2->Parameters.Scsi + 11) & 0xF | 0xE0);
    __outbyte(0x1F3u, *((_BYTE *)&v2->Parameters.SetVolume + 8));
    __outbyte(0x1F4u, BYTE1(v2->Parameters.FileSystemControl.InputBufferLength));
    __outbyte(0x1F5u, BYTE2(v2->Parameters.DeviceIoControl.InputBufferLength));
    __outbyte(0x1F2u, v2->Parameters.Create.DesiredAccess >> 9);
    LOWORD(v5) = 503;
    __outbyte(0x1F7u, 0x40u);
    if ( IdexChannelObject.InterruptRoutine )
      RtlAssert(
        v5,
        v6,
        (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        (int)v2,
        "IdexChannelObject.InterruptRoutine == NULL",
        "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        0x23Bu,
        0);
    IdexChannelObject.InterruptRoutine = (void (__stdcall *)())IdexDiskNoTransferInterrupt;
    dword_80051344 = (void (__stdcall *)(_KDPC *, void *, void *, void *))IdexDiskFinishGeneric;
    unk_8005135C = 10;
    KfLowerIrql(2);
  }
  else
  {
    IdexDiskFinishGeneric(v5, (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\disk.c", (int)v2);
  }
}