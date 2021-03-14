int __fastcall IoSynchronousFsdRequest(int a1, int a2, unsigned int MajorFunction, _DEVICE_OBJECT *DeviceObject, void *Buffer, unsigned int Length, _LARGE_INTEGER *StartingOffset)
{
  _IRP *v7; // eax
  int result; // eax
  int v9; // edx
  int v10; // ecx
  _KEVENT Event; // [esp+4h] [ebp-18h]
  _IO_STATUS_BLOCK IoStatusBlock; // [esp+14h] [ebp-8h]

  Event.Header.WaitListHead.Blink = &Event.Header.WaitListHead;
  Event.Header.WaitListHead.Flink = &Event.Header.WaitListHead;
  Event.Header.Type = 0;
  Event.Header.Size = 4;
  Event.Header.SignalState = 0;
  v7 = IoBuildSynchronousFsdRequest(
         a1,
         a2,
         MajorFunction,
         DeviceObject,
         Buffer,
         Length,
         StartingOffset,
         &Event,
         &IoStatusBlock);
  if ( !v7 )
    return -1073741670;
  result = IofCallDriver(DeviceObject, v7);
  if ( result == 259 )
  {
    KeWaitForSingleObject(v10, v9, &Event, 0, 0, 0, 0);
    result = IoStatusBlock.Status;
  }
  return result;
}