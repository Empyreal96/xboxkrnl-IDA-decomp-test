void __userpurge IdexDiskStartIo(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  _IO_STACK_LOCATION *v9; // eax
  char v10; // cl
  _STRING *v11; // eax

  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\idex\\disk.c",
      0x4EEu,
      0);
  if ( HalIsResetOrShutdownPending() )
  {
    IdexChannelAbortCurrentPacket(v6, v7, a3, a4);
    return;
  }
  IoMarkIrpMustComplete(v6, v7, a3, (int)Irp, Irp);
  v9 = Irp->Tail.Overlay.CurrentStackLocation;
  v10 = v9->MajorFunction;
  if ( v9->MajorFunction < 2u )
    goto LABEL_20;
  if ( (unsigned __int8)v10 <= 3u )
  {
    IdexDiskStartReadWrite(Irp, v8);
    return;
  }
  if ( v10 == 6 )
  {
    IdexDiskStartFlushBuffers(Irp, v8, a3);
    return;
  }
  if ( v10 != 10 )
LABEL_20:
    IdexBugCheckWorker(0x30526u, (unsigned int)Irp);
  v11 = v9->Parameters.Create.RemainingName;
  if ( v11 == (_STRING *)315432 )
  {
    IdexChannelStartIdePassThrough(v8, a3, Irp, 0, (void (__stdcall *)())IdexDiskResetDevice);
  }
  else
  {
    if ( v11 != (_STRING *)458772 )
      IdexBugCheckWorker(0x30520u, (unsigned int)Irp);
    IdexDiskStartVerify(Irp, v8);
  }
}