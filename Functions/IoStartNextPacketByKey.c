void __userpurge IoStartNextPacketByKey(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, _DEVICE_OBJECT *DeviceObject, unsigned int Key)
{
  char v5; // al
  _LIST_ENTRY *v6; // edx
  int v7; // ecx

  v5 = DeviceObject->StartIoFlags;
  if ( v5 & 1 )
  {
    if ( v5 & 2 )
      RtlAssert(
        a1,
        a2,
        a3,
        (int)DeviceObject,
        "!(DeviceObject->StartIoFlags & DO_STARTIO_REQUESTED)",
        "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        0xB54u,
        0);
    DeviceObject->StartIoFlags |= 6u;
    DeviceObject->StartIoKey = Key;
  }
  else
  {
    if ( v5 & 2 )
      RtlAssert(
        a1,
        a2,
        a3,
        (int)DeviceObject,
        "!(DeviceObject->StartIoFlags & DO_STARTIO_REQUESTED)",
        "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        0xB3Cu,
        0);
    IopStartNextPacketByKey(a1, a2, a3, (int)DeviceObject, DeviceObject, Key);
    if ( DeviceObject->StartIoFlags & 2 )
      IopStartNextPacketDeferred(v6, v7, (int)DeviceObject, DeviceObject);
  }
}