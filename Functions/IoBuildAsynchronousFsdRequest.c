_IRP *__fastcall IoBuildAsynchronousFsdRequest(int a1, int a2, unsigned int MajorFunction, _DEVICE_OBJECT *DeviceObject, void *Buffer, unsigned int Length, _LARGE_INTEGER *StartingOffset, _IO_STATUS_BLOCK *IoStatusBlock)
{
  _IRP *result; // eax
  int v9; // edx
  int v10; // ecx
  _IRP *v11; // edi
  _IO_STACK_LOCATION *v12; // esi
  int v13; // esi

  result = IoAllocateIrp(a1, a2, DeviceObject->StackSize);
  v11 = result;
  if ( result )
  {
    v12 = result->Tail.Overlay.CurrentStackLocation;
    result->Tail.Overlay.Thread = (_ETHREAD *)thread;
    v13 = (int)&v12[-1];
    *(_BYTE *)v13 = MajorFunction;
    if ( MajorFunction != 6 && MajorFunction != 12 )
    {
      result->UserBuffer = Buffer;
      if ( DeviceObject->Flags & 4 )
      {
        if ( Length )
          IoLockUserBuffer(v9, v10, v13, result, Length);
      }
      *(_DWORD *)(v13 + 4) = Length;
      *(_LARGE_INTEGER *)(v13 + 12) = *StartingOffset;
    }
    v11->UserIosb = IoStatusBlock;
    result = v11;
  }
  return result;
}