void __stdcall IdexChannelRestartCurrentPacket()
{
  (**(void (__stdcall ***)(_DWORD, _IRP *))(*(_DWORD *)(Irp->Tail.Overlay.PacketType + 20) + 8))(
    *(_DWORD *)(Irp->Tail.Overlay.PacketType + 20),
    Irp);
}