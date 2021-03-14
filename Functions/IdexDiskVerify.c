int __stdcall IdexDiskVerify(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IO_STACK_LOCATION *v2; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  __int64 v6; // rax

  v2 = Irp->Tail.Overlay.CurrentStackLocation;
  if ( v2->Parameters.Read.ByteOffset.LowPart < 0x10 )
    return -1073741820;
  v4 = v2->Parameters.Create.Options;
  v5 = *(_DWORD *)(v4 + 8);
  if ( v5 > 0x20000 )
    return -1073741808;
  v6 = *(_QWORD *)v4 + *(_QWORD *)((char *)DeviceObject->DeviceExtension + 4);
  v2->Parameters.Create.DesiredAccess = v5;
  v6 >>= 9;
  v2->Parameters.Read.ByteOffset.LowPart = v6;
  LODWORD(v6) = Irp->Tail.Overlay.CurrentStackLocation;
  Irp->IoStatus.Information = 0;
  *(_BYTE *)(v6 + 3) |= 1u;
  dword_80051350(v4, HIDWORD(v6), DeviceObject, Irp);
  return 259;
}