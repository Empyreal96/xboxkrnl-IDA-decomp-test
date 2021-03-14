bool __usercall IdexDiskNoTransferInterrupt@<al>(int *a1@<edi>)
{
  _IRP *v1; // ecx
  unsigned __int8 v2; // al

  v1 = Irp;
  v2 = __inbyte(0x1F7u);
  IdexChannelObject.InterruptRoutine = 0;
  Irp->IoStatus.Status = (v2 & 1) != 0 ? 0xC0000185 : 0;
  return KeInsertQueueDpc(0, (int)v1, a1, &Dpc, 0, 0);
}