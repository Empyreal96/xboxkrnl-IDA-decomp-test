void __fastcall IdexDiskStartReadWrite(_IRP *Irp, int a2)
{
  _IRP *v2; // ebx
  _IO_STACK_LOCATION *v3; // esi
  unsigned int v4; // edi
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  unsigned __int8 v11; // al

  v2 = Irp;
  v3 = Irp->Tail.Overlay.CurrentStackLocation;
  v4 = v3->Parameters.Create.DesiredAccess;
  if ( v4 > 0x20000 )
    v4 = 0x20000;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      (int)Irp,
      (int *)v4,
      (int)v3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0x30Au,
      0);
  KfRaiseIrql(NewIrql);
  if ( IdexDiskSelectDeviceAndSpinWhileBusy(v5, v6, (int *)v4, (int)v3) )
  {
    if ( v2->Flags & 0x400 && v3->Flags >= 0 )
      IdexChannelPrepareScatterGatherTransfer(
        v8,
        v7,
        v2->SegmentArray,
        v3->Parameters.FileSystemControl.FsControlCode,
        v4);
    else
      IdexChannelPrepareBufferTransfer(
        (char *)(v3->Parameters.Create.Options + v3->Parameters.Read.ByteOffset.HighPart),
        v4);
    __outbyte(0x1F6u, *((_BYTE *)&v3->Parameters.Scsi + 11) & 0xF | 0xE0);
    __outbyte(0x1F3u, *((_BYTE *)&v3->Parameters.SetVolume + 8));
    __outbyte(0x1F4u, BYTE1(v3->Parameters.FileSystemControl.InputBufferLength));
    __outbyte(0x1F5u, BYTE2(v3->Parameters.DeviceIoControl.InputBufferLength));
    __outbyte(0x1F2u, v4 >> 9);
    if ( v3->MajorFunction == 2 )
    {
      __outbyte(0x1F7u, 0xC8u);
      v11 = 9;
    }
    else
    {
      __outbyte(0x1F7u, 0xCAu);
      v11 = 1;
    }
    LOWORD(v9) = -160;
    __outbyte(0xFF60u, v11);
    if ( IdexChannelObject.InterruptRoutine )
      RtlAssert(
        v9,
        v10,
        (int *)v4,
        (int)v3,
        "IdexChannelObject.InterruptRoutine == NULL",
        "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
        0x337u,
        0);
    IdexChannelObject.InterruptRoutine = (void (__stdcall *)())IdexDiskTransferInterrupt;
    dword_80051344 = (void (__stdcall *)(_KDPC *, void *, void *, void *))IdexDiskFinishReadWrite;
    unk_80051359 = 1;
    unk_8005135C = 10;
    KfLowerIrql(2);
  }
  else
  {
    IdexDiskFinishReadWrite(v8, v7);
  }
}