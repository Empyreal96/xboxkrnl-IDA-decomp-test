void __stdcall IopCompleteUnloadOrDelete(_DEVICE_OBJECT *DeviceObject, char Irql)
{
  int v2; // edx
  void (__stdcall *v3)(_DEVICE_OBJECT *); // eax

  if ( DeviceObject->DeletePending )
  {
    KfLowerIrql(Irql);
    v3 = DeviceObject->DriverObject->DriverDeleteDevice;
    if ( v3 )
      v3(DeviceObject);
    else
      ObfDereferenceObject(DeviceObject, v2);
  }
}