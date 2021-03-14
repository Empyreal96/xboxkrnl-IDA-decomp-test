int __stdcall IdexDiskGetDriveGeometry(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  unsigned int v3; // edx
  _DWORD *v4; // eax

  if ( *(_DWORD *)(Irp->Tail.Overlay.PacketType + 4) < 0x18u )
    return -1073741789;
  v3 = IdexDiskUserAddressableSectors;
  v4 = Irp->UserBuffer;
  v4[1] = 0;
  *v4 = v3;
  v4[2] = 12;
  v4[3] = 1;
  v4[4] = 1;
  v4[5] = 512;
  Irp->IoStatus.Information = 24;
  return 0;
}