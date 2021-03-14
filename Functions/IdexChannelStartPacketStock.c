void __userpurge IdexChannelStartPacketStock(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _LIST_ENTRY *v6; // edx
  char v7; // cl
  char OldIrql; // [esp+1h] [ebp-1h]

  if ( IdexChannelQuickRebooting )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "!IdexChannelQuickRebooting",
      "d:\\xbox-apr03\\private\\ntos\\idex\\channel.c",
      0x3D2u,
      "I/O cannot be started after reboot was requested\n");
  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( !KeInsertDeviceQueue(v7, v6, &DeviceQueue, &Irp->Tail.Overlay.DeviceQueueEntry) )
  {
    unk_8005135D = 0;
    ::Irp = Irp;
    unk_8005135E = 4;
    unk_8005135A = 1;
    DeviceObject->DriverObject->DriverStartIo(DeviceObject, Irp);
    unk_8005135A = 0;
    if ( unk_8005135B )
      dword_80051354();
  }
  KfLowerIrql(OldIrql);
}