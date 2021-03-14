// local variable allocation has failed, the output may be wrong!
void __userpurge IdexChannelStartIdePassThrough(int a1@<edx>, int *a2@<edi>, _IRP *Irp, char TargetDevice, void (__stdcall *ResetDeviceRoutine)())
{
  _IO_STACK_LOCATION *v5; // eax
  int v6; // esi
  unsigned int v7; // eax
  int v8; // edx
  int v9; // edx
  int v10; // ecx
  int v11; // eax

  v5 = Irp->Tail.Overlay.CurrentStackLocation;
  v6 = v5->Parameters.Create.Options;
  if ( Irp->UserBuffer != (void *)v6
    || v5->Parameters.Read.ByteOffset.LowPart < 0x10
    || (v7 = v5->Parameters.Create.DesiredAccess, v7 < 0x10) )
  {
    IdexChannelInvalidParameterRequest(Irp, a2);
  }
  else
  {
    Irp->IoStatus.Information = v7;
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        a1,
        (int)Irp,
        (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
        v6,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
        0x53Bu,
        0);
    KfRaiseIrql(NewIrql);
    LOWORD(v8) = 502;
    __outbyte(0x1F6u, 16 * (TargetDevice | 0xFA));
    if ( !IdexChannelSpinWhileBusy(&TargetDevice + 3, v8, (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c") )
      goto LABEL_10;
    __outbyte(0x1F1u, *(_BYTE *)v6);
    __outbyte(0x1F2u, *(_BYTE *)(v6 + 1));
    __outbyte(0x1F3u, *(_BYTE *)(v6 + 2));
    __outbyte(0x1F4u, *(_BYTE *)(v6 + 3));
    __outbyte(0x1F5u, *(_BYTE *)(v6 + 4));
    LOWORD(v9) = 503;
    __outbyte(0x1F7u, *(_BYTE *)(v6 + 6));
    if ( *(_DWORD *)(v6 + 8) && *(_BYTE *)(v6 + 7) )
    {
      if ( !IdexChannelSpinWhileBusyAndNotDrq(
              &TargetDevice + 3,
              v9,
              (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c") )
      {
LABEL_10:
        ResetDeviceRoutine();
        return;
      }
      WRITE_PORT_BUFFER_USHORT((PUSHORT)0x1F0, *(PUSHORT *)(v6 + 12), *(_DWORD *)(v6 + 8) >> 1);
      v11 = *(_DWORD *)(v6 + 8);
      if ( v11 & 1 )
      {
        v10 = *(_DWORD *)(v6 + 12);
        LOWORD(v9) = 496;
        __outbyte(0x1F0u, *(_BYTE *)(v10 + v11 - 1));
      }
    }
    if ( IdexChannelObject.InterruptRoutine )
      RtlAssert(
        v9,
        v10,
        (int *)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
        v6,
        "IdexChannelObject.InterruptRoutine == NULL",
        "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
        0x577u,
        0);
    IdexChannelObject.InterruptRoutine = (void (__stdcall *)())IdexChannelIdePassThroughInterrupt;
    dword_80051344 = (void (__stdcall *)(_KDPC *, void *, void *, void *))IdexChannelFinishIdePassThrough;
    unk_8005135C = 10;
    KfLowerIrql(2);
  }
}