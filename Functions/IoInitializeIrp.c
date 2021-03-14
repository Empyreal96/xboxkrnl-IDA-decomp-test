void __stdcall IoInitializeIrp(_IRP *Irp, unsigned __int16 PacketSize, char StackSize)
{
  _IRP *v3; // edx

  v3 = Irp;
  memset(Irp, 0, PacketSize);
  Irp->CurrentLocation = StackSize + 1;
  v3->ThreadListEntry.Blink = &v3->ThreadListEntry;
  v3->ThreadListEntry.Flink = &v3->ThreadListEntry;
  Irp->Size = PacketSize;
  Irp->Type = 6;
  Irp->StackCount = StackSize;
  v3->Tail.Overlay.PacketType = (unsigned int)&v3[1] + 36 * StackSize;
}