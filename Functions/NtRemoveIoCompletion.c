_LARGE_INTEGER *__fastcall NtRemoveIoCompletion(int a1, int a2, void *IoCompletionHandle, void **KeyContext, void **ApcContext, _IO_STATUS_BLOCK *IoStatusBlock, _LARGE_INTEGER *Timeout)
{
  _LARGE_INTEGER *v7; // esi
  int v8; // edx
  int v9; // ecx
  _LARGE_INTEGER *v10; // eax
  int v11; // edx
  bool v12; // zf
  void *v13; // esi
  void *v14; // edi
  int v15; // ebx
  _IO_STATUS_BLOCK *v16; // eax
  int LocalIoStatusBlock_4; // [esp+Ch] [ebp-4h]

  v7 = 0;
  if ( Timeout )
    v7 = Timeout;
  Timeout = (_LARGE_INTEGER *)ObReferenceObjectByHandle(
                                a2,
                                a1,
                                0,
                                (int)v7,
                                IoCompletionHandle,
                                &IoCompletionObjectType,
                                &IoCompletionHandle);
  if ( (signed int)Timeout >= 0 )
  {
    v10 = (_LARGE_INTEGER *)KeRemoveQueue(v8, v9, (int)v7, (_KQUEUE *)IoCompletionHandle, 0, v7);
    if ( v10 == (_LARGE_INTEGER *)258 || v10 == (_LARGE_INTEGER *)192 )
    {
      Timeout = v10;
    }
    else
    {
      v12 = v10[1].LowPart == 0;
      Timeout = 0;
      if ( v12 )
      {
        v13 = (void *)v10[-5].LowPart;
        v14 = (void *)v10[-3].LowPart;
        v15 = v10[-9].HighPart;
        LocalIoStatusBlock_4 = v10[-8].LowPart;
        IoFreeIrp(LocalIoStatusBlock_4, v11, (_IRP *)((char *)&v10[-11].QuadPart + 4));
      }
      else
      {
        v13 = (void *)v10[2].LowPart;
        v14 = (void *)v10[1].HighPart;
        v15 = v10[2].HighPart;
        LocalIoStatusBlock_4 = v10[3].LowPart;
        ExFreePool(v10);
      }
      *ApcContext = v13;
      *KeyContext = v14;
      v16 = IoStatusBlock;
      IoStatusBlock->Status = v15;
      v16->Information = LocalIoStatusBlock_4;
    }
    ObfDereferenceObject(IoCompletionHandle, v11);
  }
  return Timeout;
}