int *__stdcall IoDismountVolumeByName(_STRING *DeviceName)
{
  int *v1; // esi
  int v2; // edx

  v1 = ObReferenceObjectByName(DeviceName, 0, &IoDeviceObjectType, 0, (void **)&DeviceName);
  if ( (signed int)v1 >= 0 )
  {
    v1 = IoDismountVolume((_DEVICE_OBJECT *)DeviceName);
    ObfDereferenceObject(DeviceName, v2);
  }
  return v1;
}