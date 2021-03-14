int __fastcall IdexDiskFlushBuffers(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  *(_BYTE *)(Irp->Tail.Overlay.PacketType + 3) |= 1u;
  dword_80051350(Irp, a2, DeviceObject, Irp);
  return 259;
}