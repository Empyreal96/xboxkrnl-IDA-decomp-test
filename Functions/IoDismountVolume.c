int *__stdcall IoDismountVolume(_DEVICE_OBJECT *DeviceObject)
{
  KIRQL v1; // al
  _DEVICE_OBJECT *v2; // esi
  int *v3; // edi

  v1 = KeRaiseIrqlToDpcLevel();
  v2 = DeviceObject->MountedOrSelfDevice;
  if ( v2 )
  {
    if ( v2->DriverObject->DriverDismountVolume )
    {
      ++v2->ReferenceCount;
      v3 = 0;
    }
    else
    {
      v2 = 0;
      v3 = (int *)-1073741808;
    }
  }
  else
  {
    v3 = (int *)-1073741202;
  }
  KfLowerIrql(v1);
  if ( v2 )
  {
    v3 = (int *)v2->DriverObject->DriverDismountVolume(v2);
    IopDecrementDeviceObjectRef(v3, v2);
  }
  return v3;
}