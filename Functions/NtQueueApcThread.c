int __userpurge NtQueueApcThread@<eax>(int a1@<edx>, _ETHREAD *a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *ThreadHandle, void (__stdcall *ApcRoutine)(void *, void *, void *), void *ApcArgument1, void *ApcArgument2, void *ApcArgument3)
{
  int v9; // edx
  int v10; // ST20_4
  int v11; // edx
  int v12; // ecx
  int v13; // ebx
  int *v14; // eax
  int v15; // edx
  _KAPC *v16; // esi
  int v17; // edx
  int v18; // ecx
  _ETHREAD *Thread; // [esp+0h] [ebp-4h]

  Thread = a2;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v9, v10, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\ps\\psctx.c", 0x50u, 0);
  }
  v13 = ObReferenceObjectByHandle(a1, (int)a2, a3, a4, ThreadHandle, &PsThreadObjectType, (void **)&Thread);
  if ( v13 >= 0 )
  {
    v14 = ExAllocatePoolWithTag(v11, v12, a4, 0x28u, 0x70617350u);
    v16 = (_KAPC *)v14;
    if ( v14 )
    {
      KeInitializeApc(
        (_KAPC *)v14,
        &Thread->Tcb,
        (void (__stdcall *)(_KAPC *, void (__stdcall **)(void *, void *, void *), void **, void **, void **))PspQueueApcSpecialApc,
        0,
        ApcRoutine,
        1,
        ApcArgument1);
      if ( !KeInsertQueueApc(v18, v17, v16, ApcArgument2, ApcArgument3, 0) )
      {
        ExFreePool(v16);
        v13 = -1073741823;
      }
    }
    else
    {
      v13 = -1073741801;
    }
    ObfDereferenceObject(Thread, v15);
  }
  return v13;
}