int *__userpurge IoCreateDevice@<eax>(int *a1@<edi>, int a2@<esi>, _DRIVER_OBJECT *DriverObject, unsigned int DeviceExtensionSize, _STRING *DeviceName, unsigned int DeviceType, char Exclusive, _DEVICE_OBJECT **DeviceObject)
{
  int v8; // edx
  int v9; // ST18_4
  _STRING *v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // esi
  int *v13; // edi
  _DEVICE_OBJECT *v14; // eax
  _DEVICE_OBJECT *v15; // edi
  char *v16; // edi
  int v17; // ecx
  int *v18; // edi
  _OBJECT_ATTRIBUTES objectAttributes; // [esp+0h] [ebp-14h]
  void *handle; // [esp+Ch] [ebp-8h]
  _DEVICE_OBJECT *deviceObject; // [esp+10h] [ebp-4h]
  bool deviceHasName_3; // [esp+27h] [ebp+13h]

  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a1, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v8, v9, a1, a2, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", 0x473u, 0);
  }
  v10 = DeviceName;
  deviceHasName_3 = DeviceName != 0;
  objectAttributes.RootDirectory = 0;
  objectAttributes.Attributes = 0;
  objectAttributes.ObjectName = v10;
  if ( Exclusive )
    objectAttributes.Attributes = 32;
  if ( deviceHasName_3 )
    objectAttributes.Attributes |= 0x10u;
  v11 = DeviceExtensionSize & 7;
  if ( DeviceExtensionSize & 7 )
    v11 = 8 - v11;
  v12 = DeviceExtensionSize + v11 + 72;
  v13 = (int *)ObCreateObject(&IoDeviceObjectType, &objectAttributes, v12, (void **)&deviceObject);
  v14 = 0;
  if ( (signed int)v13 >= 0 )
  {
    v15 = deviceObject;
    memset(deviceObject, 0, 4 * (v12 >> 2));
    v16 = (char *)v15 + 4 * (v12 >> 2);
    v17 = v12 & 3;
    memset(v16, 0, v17);
    v18 = (int *)&v16[v17];
    deviceObject->Type = 3;
    deviceObject->Size = DeviceExtensionSize + 72;
    if ( DeviceType != (unsigned __int8)DeviceType )
      RtlAssert(
        v12,
        0,
        v18,
        0,
        "DeviceType == (DEVICE_TYPE)(UCHAR)DeviceType",
        "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        0x4C8u,
        0);
    deviceObject->DeviceType = DeviceType;
    if ( DeviceType == 7 || DeviceType == 58 || DeviceType == 2 || DeviceType == 59 )
    {
      deviceObject->DeviceLock.Header.Type = 1;
      deviceObject->DeviceLock.Header.Size = 4;
      deviceObject->DeviceLock.Header.SignalState = 1;
      InitializeListHead(&deviceObject->DeviceLock.Header.WaitListHead);
      deviceObject->MountedOrSelfDevice = 0;
    }
    else
    {
      deviceObject->MountedOrSelfDevice = deviceObject;
    }
    deviceObject->AlignmentRequirement = 0;
    deviceObject->Flags = 16;
    if ( Exclusive )
      deviceObject->Flags |= 2u;
    if ( deviceHasName_3 )
      deviceObject->Flags |= 8u;
    if ( DeviceExtensionSize )
      deviceObject->DeviceExtension = &deviceObject[1];
    else
      deviceObject->DeviceExtension = 0;
    deviceObject->StackSize = 1;
    KeInitializeDeviceQueue(&deviceObject->DeviceQueue);
    v13 = (int *)ObInsertObject(deviceObject, &objectAttributes, 1u, &handle);
    if ( (signed int)v13 < 0 )
    {
      v14 = 0;
    }
    else
    {
      deviceObject->DriverObject = DriverObject;
      NtClose(v13, handle);
      v14 = deviceObject;
    }
  }
  *DeviceObject = v14;
  return v13;
}