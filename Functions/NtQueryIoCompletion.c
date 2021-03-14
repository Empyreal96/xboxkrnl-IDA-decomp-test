int __userpurge NtQueryIoCompletion@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *IoCompletionHandle, _IO_COMPLETION_BASIC_INFORMATION *IoCompletionInformation)
{
  int v6; // edx
  int v7; // edi
  int v8; // esi

  v7 = ObReferenceObjectByHandle(a1, a2, a3, a4, IoCompletionHandle, &IoCompletionObjectType, &IoCompletionHandle);
  if ( v7 >= 0 )
  {
    v8 = *((_DWORD *)IoCompletionHandle + 1);
    ObfDereferenceObject(IoCompletionHandle, v6);
    IoCompletionInformation->Depth = v8;
  }
  return v7;
}