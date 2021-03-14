void __userpurge IoDeleteDevice(int *a1@<edi>, _DEVICE_OBJECT *DeviceObject)
{
  char v2; // al
  bool v3; // zf

  if ( DeviceObject->Flags & 8 )
    ObMakeTemporaryObject(a1, (int)DeviceObject, DeviceObject);
  v2 = KeRaiseIrqlToDpcLevel();
  v3 = DeviceObject->ReferenceCount == 0;
  DeviceObject->DeletePending = 1;
  if ( v3 )
    IopCompleteUnloadOrDelete(DeviceObject, v2);
  else
    KfLowerIrql(v2);
}