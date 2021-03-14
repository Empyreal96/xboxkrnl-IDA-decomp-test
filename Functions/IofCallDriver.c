int __fastcall IofCallDriver(_DEVICE_OBJECT *DeviceObject, _IRP *Irp)
{
  _IRP *v2; // esi
  _DEVICE_OBJECT *v3; // edi
  unsigned __int8 *v4; // eax

  v2 = Irp;
  v3 = DeviceObject;
  if ( Irp->Type != 6 )
    RtlAssert(
      (int)Irp,
      (int)DeviceObject,
      (int *)&DeviceObject->Type,
      (int)Irp,
      "Irp->Type == IO_TYPE_IRP",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0x1CEu,
      0);
  if ( --v2->CurrentLocation <= 0 )
    KeBugCheckEx(0x35u, (unsigned int)v2, 0, 0, 0);
  v4 = (unsigned __int8 *)(v2->Tail.Overlay.PacketType - 36);
  v2->Tail.Overlay.PacketType = (unsigned int)v4;
  *((_DWORD *)v4 + 5) = v3;
  return v3->DriverObject->MajorFunction[*v4](v3, v2);
}