int __userpurge NtSetIoCompletion@<eax>(int a1@<edx>, void *a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *IoCompletionHandle, void *KeyContext, void *ApcContext, int IoStatus, unsigned int IoStatusInformation)
{
  int v9; // edx
  int v10; // ST14_4
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  int v14; // edx
  void *IoCompletion; // [esp+0h] [ebp-4h]

  IoCompletion = a2;
  if ( (unsigned __int8)dword_8004C5D0 > 1u )
  {
    DbgPrint(a3, "EX: Pageable code called at IRQL %d\n", (unsigned __int8)dword_8004C5D0);
    RtlAssert(v9, v10, a3, a4, "FALSE", "d:\\xbox-apr03\\private\\ntos\\io\\complete.c", 0xE0u, 0);
  }
  v13 = ObReferenceObjectByHandle(a1, (int)a2, a3, a4, IoCompletionHandle, &IoCompletionObjectType, &IoCompletion);
  if ( v13 >= 0 )
  {
    v13 = IoSetIoCompletion(v11, v12, a3, v13, IoCompletion, KeyContext, ApcContext, IoStatus, IoStatusInformation);
    ObfDereferenceObject(IoCompletion, v14);
  }
  return v13;
}