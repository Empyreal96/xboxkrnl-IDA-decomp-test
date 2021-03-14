void __userpurge IoStartNextPacket(_LIST_ENTRY *a1@<edx>, int a2@<ecx>, int *a3@<edi>, _DEVICE_OBJECT *DeviceObject)
{
  char v4; // al
  _LIST_ENTRY *v5; // edx
  int v6; // ecx

  v4 = DeviceObject->StartIoFlags;
  if ( v4 & 1 )
  {
    if ( v4 & 2 )
      RtlAssert(
        (int)a1,
        a2,
        a3,
        (int)DeviceObject,
        "!(DeviceObject->StartIoFlags & DO_STARTIO_REQUESTED)",
        "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        0xB0Au,
        0);
    DeviceObject->StartIoFlags = DeviceObject->StartIoFlags & 0xFB | 2;
  }
  else
  {
    if ( v4 & 2 )
      RtlAssert(
        (int)a1,
        a2,
        a3,
        (int)DeviceObject,
        "!(DeviceObject->StartIoFlags & DO_STARTIO_REQUESTED)",
        "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        0xAF2u,
        0);
    IopStartNextPacket(a1, a2, a3, (int)DeviceObject, DeviceObject);
    if ( DeviceObject->StartIoFlags & 2 )
      IopStartNextPacketDeferred(v5, v6, (int)DeviceObject, DeviceObject);
  }
}