_IRP *__fastcall IoBuildDeviceIoControlRequest(int a1, int a2, unsigned int IoControlCode, _DEVICE_OBJECT *DeviceObject, void *InputBuffer, unsigned int InputBufferLength, void *OutputBuffer, unsigned int OutputBufferLength, char InternalDeviceIoControl, _KEVENT *Event, _IO_STATUS_BLOCK *IoStatusBlock)
{
  _IRP *result; // eax
  _IRP *v12; // esi
  unsigned int v13; // eax
  int v14; // ecx
  KIRQL v15; // al
  _LIST_ENTRY *v16; // edx
  _LIST_ENTRY *v17; // ebx

  result = IoAllocateIrp(a1, a2, DeviceObject->StackSize);
  v12 = result;
  if ( result )
  {
    result->UserBuffer = OutputBuffer;
    v13 = result->Tail.Overlay.PacketType - 36;
    *(_BYTE *)v13 = (InternalDeviceIoControl != 0) + 10;
    *(_DWORD *)(v13 + 12) = InputBufferLength;
    *(_DWORD *)(v13 + 4) = OutputBufferLength;
    *(_DWORD *)(v13 + 16) = IoControlCode;
    *(_DWORD *)(v13 + 8) = InputBuffer;
    if ( OutputBufferLength )
    {
      v14 = IoControlCode & 3;
      if ( v14 == 1 || v14 == 2 )
        IoLockUserBuffer(OutputBufferLength, v14, (int)v12, v12, OutputBufferLength);
    }
    v12->UserIosb = IoStatusBlock;
    v12->UserEvent = Event;
    v12->Tail.Overlay.Thread = (_ETHREAD *)thread;
    v15 = KfRaiseIrql(1);
    v16 = &v12->Tail.Overlay.Thread->IrpList;
    v17 = v16->Flink;
    v12->ThreadListEntry.Flink = v16->Flink;
    v12->ThreadListEntry.Blink = v16;
    v17->Blink = &v12->ThreadListEntry;
    v16->Flink = &v12->ThreadListEntry;
    KfLowerIrql(v15);
    result = v12;
  }
  return result;
}