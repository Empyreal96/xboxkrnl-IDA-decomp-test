void __fastcall RawxDeleteVolumeDevice(int a1, int a2, _DEVICE_OBJECT *VolumeDeviceObject)
{
  void **v3; // esi

  v3 = (void **)VolumeDeviceObject->DeviceExtension;
  if ( *((_BYTE *)v3 + 4) )
    RtlAssert(
      a2,
      a1,
      (int *)&VolumeDeviceObject->Type,
      (int)v3,
      "VolumeExtension->ShareAccess.OpenCount == 0",
      "d:\\xbox-apr03\\private\\ntos\\rawx\\mountvol.c",
      0x2Du,
      0);
  if ( *v3 )
    ObfDereferenceObject(*v3, a2);
  IoDeleteDevice((int *)&VolumeDeviceObject->Type, VolumeDeviceObject);
}