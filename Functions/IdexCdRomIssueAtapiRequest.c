void __userpurge IdexCdRomIssueAtapiRequest(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _CDB *Cdb, void *TransferBuffer, unsigned int TransferLength, char DataOut, void (__stdcall *FinishIoRoutine)())
{
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  unsigned __int8 v12; // al
  int v13; // edx
  int v14; // ecx
  unsigned __int8 v15; // al

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
      0x241u,
      0);
  KfRaiseIrql(NewIrql);
  if ( IdexCdRomSelectDeviceAndSpinWhileBusy(v8, v9, a3, (int)"d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c") )
  {
    if ( TransferLength )
    {
      IdexChannelPrepareBufferTransfer((char *)TransferBuffer, TransferLength);
      v12 = 1;
    }
    else
    {
      v12 = 0;
    }
    LOWORD(v10) = 497;
    __outbyte(0x1F1u, v12);
    if ( IdexCdRomWritePacket(v10, v11, (int *)TransferLength, (int)"d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c", Cdb) )
    {
      if ( TransferLength )
      {
        LOWORD(v13) = -160;
        v15 = 1;
        if ( !DataOut )
          v15 = 9;
        __outbyte(0xFF60u, v15);
      }
      if ( IdexChannelObject.InterruptRoutine )
        RtlAssert(
          v13,
          v14,
          (int *)TransferLength,
          (int)"d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
          "IdexChannelObject.InterruptRoutine == NULL",
          "d:\\xbox-apr03\\private\\ntos\\idex\\cdrom.c",
          0x271u,
          0);
      IdexChannelObject.InterruptRoutine = (void (__stdcall *)())IdexCdRomTransferInterrupt;
      if ( !TransferLength )
        IdexChannelObject.InterruptRoutine = (void (__stdcall *)())IdexCdRomNoTransferInterrupt;
      dword_80051344 = (void (__stdcall *)(_KDPC *, void *, void *, void *))FinishIoRoutine;
      unk_80051359 = 1;
      unk_8005135C = 12;
      KfLowerIrql(2);
    }
    else
    {
      FinishIoRoutine();
    }
  }
  else
  {
    FinishIoRoutine();
  }
}