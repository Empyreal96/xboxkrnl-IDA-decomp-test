int __fastcall IoSynchronousDeviceIoControlRequest(int a1, int a2, unsigned int IoControlCode, _DEVICE_OBJECT *DeviceObject, void *InputBuffer, unsigned int InputBufferLength, void *OutputBuffer, unsigned int OutputBufferLength, unsigned int *ReturnedOutputBufferLength, char InternalDeviceIoControl)
{
  _IRP *v10; // eax
  int result; // eax
  int v12; // edx
  int v13; // ecx
  _KEVENT Event; // [esp+4h] [ebp-18h]
  _IO_STATUS_BLOCK IoStatusBlock; // [esp+14h] [ebp-8h]

  Event.Header.WaitListHead.Blink = &Event.Header.WaitListHead;
  Event.Header.WaitListHead.Flink = &Event.Header.WaitListHead;
  Event.Header.Type = 0;
  Event.Header.Size = 4;
  Event.Header.SignalState = 0;
  v10 = IoBuildDeviceIoControlRequest(
          a1,
          a2,
          IoControlCode,
          DeviceObject,
          InputBuffer,
          InputBufferLength,
          OutputBuffer,
          OutputBufferLength,
          InternalDeviceIoControl,
          &Event,
          &IoStatusBlock);
  if ( v10 )
  {
    result = IofCallDriver(DeviceObject, v10);
    if ( result == 259 )
    {
      KeWaitForSingleObject(v13, v12, &Event, 0, 0, 0, 0);
      result = IoStatusBlock.Status;
    }
  }
  else
  {
    result = -1073741670;
  }
  if ( ReturnedOutputBufferLength )
    *ReturnedOutputBufferLength = IoStatusBlock.Information;
  return result;
}