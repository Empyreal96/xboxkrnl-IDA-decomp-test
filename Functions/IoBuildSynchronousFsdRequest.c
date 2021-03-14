_IRP *__fastcall IoBuildSynchronousFsdRequest(int a1, int a2, unsigned int MajorFunction, _DEVICE_OBJECT *DeviceObject, void *Buffer, unsigned int Length, _LARGE_INTEGER *StartingOffset, _KEVENT *Event, _IO_STATUS_BLOCK *IoStatusBlock)
{
  _IRP *result; // eax
  _IRP *v10; // esi
  KIRQL v11; // al
  _LIST_ENTRY *v12; // edx
  _LIST_ENTRY *v13; // ebx

  result = IoBuildAsynchronousFsdRequest(
             a1,
             a2,
             MajorFunction,
             DeviceObject,
             Buffer,
             Length,
             StartingOffset,
             IoStatusBlock);
  v10 = result;
  if ( result )
  {
    result->UserEvent = Event;
    v11 = KfRaiseIrql(1);
    v12 = &v10->Tail.Overlay.Thread->IrpList;
    v13 = v12->Flink;
    v10->ThreadListEntry.Flink = v12->Flink;
    v10->ThreadListEntry.Blink = v12;
    v13->Blink = &v10->ThreadListEntry;
    v12->Flink = &v10->ThreadListEntry;
    KfLowerIrql(v11);
    result = v10;
  }
  return result;
}