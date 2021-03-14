void __fastcall FatxDeleteVolumeDevice(int a1, int a2, _DEVICE_OBJECT *VolumeDeviceObject)
{
  void *v3; // esi
  int v4; // edx

  v3 = VolumeDeviceObject->DeviceExtension;
  if ( *((_DWORD *)v3 + 5) )
    RtlAssert(
      a2,
      a1,
      (int *)&VolumeDeviceObject->Type,
      (int)v3,
      "VolumeExtension->FileObjectCount == 0",
      "d:\\xbox-apr03\\private\\ntos\\fatx\\mountvol.c",
      0xB0u,
      0);
  if ( *((_DWORD *)v3 + 4) )
    FatxDereferenceFcb(a2, a1, (int *)&VolumeDeviceObject->Type, *((_FAT_FCB **)v3 + 4));
  FscInvalidateDevice((_FSCACHE_EXTENSION *)v3);
  if ( *(_DWORD *)v3 )
    ObfDereferenceObject(*(void **)v3, v4);
  IoDeleteDevice((int *)&VolumeDeviceObject->Type, VolumeDeviceObject);
}