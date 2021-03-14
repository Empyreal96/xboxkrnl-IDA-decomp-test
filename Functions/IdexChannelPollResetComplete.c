void __usercall IdexChannelPollResetComplete(int a1@<edx>, int a2@<ecx>, int *a3@<edi>)
{
  void *v3; // ecx
  int v4; // edx
  _IRP *v5; // ecx

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x24Cu,
      0);
  if ( unk_8005135C <= 0u )
    RtlAssert(
      a1,
      a2,
      a3,
      (int)"d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      "IdexChannelObject.Timeout > 0",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x24Du,
      0);
  if ( (unsigned __int8)dword_80051348(a2, a1) )
  {
    dword_80051348 = 0;
    IdexChannelSetTimerPeriod(v3, 1000);
    if ( unk_8005135D < unk_8005135E )
    {
      IdexChannelRetryCurrentPacket();
      return;
    }
  }
  else
  {
    if ( --unk_8005135C )
      return;
    dword_80051348 = 0;
    IdexChannelSetTimerPeriod(v3, 1000);
  }
  v5 = Irp;
  LOBYTE(v4) = 0;
  Irp->IoStatus.Status = -1073741461;
  IofCompleteRequest(v5, v4, a3);
  dword_80051354();
}