void __userpurge IopStartNextPacketDeferred(_LIST_ENTRY *a1@<edx>, int a2@<ecx>, int a3@<esi>, _DEVICE_OBJECT *DeviceObject)
{
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      (int)a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      a3,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0xAB4u,
      0);
  if ( DeviceObject->StartIoFlags & 1 )
    RtlAssert(
      (int)a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      (int)DeviceObject,
      "!(DeviceObject->StartIoFlags & DO_STARTIO_BUSY)",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0xAB6u,
      0);
  if ( !(DeviceObject->StartIoFlags & 2) )
    RtlAssert(
      (int)a1,
      a2,
      (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      (int)DeviceObject,
      "DeviceObject->StartIoFlags & DO_STARTIO_REQUESTED",
      "d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
      0xAB7u,
      0);
  do
  {
    DeviceObject->StartIoFlags &= 0xFDu;
    if ( DeviceObject->StartIoFlags & 4 )
      IopStartNextPacketByKey(
        (int)a1,
        a2,
        (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c",
        (int)DeviceObject,
        DeviceObject,
        DeviceObject->StartIoKey);
    else
      IopStartNextPacket(a1, a2, (int *)"d:\\xbox-apr03\\private\\ntos\\io\\iosubs.c", (int)DeviceObject, DeviceObject);
  }
  while ( DeviceObject->StartIoFlags & 2 );
}