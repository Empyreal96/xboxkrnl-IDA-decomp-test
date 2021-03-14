void __userpurge IopDecrementDeviceObjectRef(int *a1@<edi>, _DEVICE_OBJECT *DeviceObject)
{
  int v2; // edx
  int v3; // ecx
  bool v4; // zf
  char irql; // [esp+4h] [ebp-4h]

  irql = KeRaiseIrqlToDpcLevel();
  if ( DeviceObject->ReferenceCount <= 0 )
    RtlAssert(
      v2,
      v3,
      a1,
      (int)DeviceObject,
      "DeviceObject->ReferenceCount > 0",
      "d:\\xbox-apr03\\private\\ntos\\io\\internal.c",
      0x2E9u,
      0);
  v4 = DeviceObject->ReferenceCount-- == 1;
  if ( v4 && DeviceObject->DeletePending )
    IopCompleteUnloadOrDelete(DeviceObject, irql);
  else
    KfLowerIrql(irql);
}