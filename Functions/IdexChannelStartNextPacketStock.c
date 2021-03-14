void __usercall IdexChannelStartNextPacketStock(_LIST_ENTRY *a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>)
{
  _LIST_ENTRY *v4; // eax
  _LIST_ENTRY *v5; // ecx

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x35Au,
      0);
  Irp = 0;
  if ( unk_8005135A )
  {
    unk_8005135B = 1;
  }
  else
  {
    do
    {
      unk_8005135B = 0;
      v4 = KeRemoveDeviceQueue(a1, a2, a3, &DeviceQueue);
      if ( !v4 )
        break;
      v5 = v4[4].Flink[2].Blink;
      Irp = (_IRP *)&v4[-8].Blink;
      unk_8005135D = 0;
      unk_8005135E = 4;
      unk_8005135A = 1;
      ((void (__stdcall *)(_LIST_ENTRY *, _LIST_ENTRY **))v5[1].Flink->Flink)(v5, &v4[-8].Blink);
      unk_8005135A = 0;
    }
    while ( unk_8005135B );
  }
}