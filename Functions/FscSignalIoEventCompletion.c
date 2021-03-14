int __fastcall FscSignalIoEventCompletion(int a1, int a2, _DEVICE_OBJECT *DeviceObject, _IRP *Irp, void *Context)
{
  KeSetEvent(a1, a2, (_KEVENT *)Context, 1, 0);
  return -1073741802;
}