int __userpurge NtQuerySemaphore@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *SemaphoreHandle, _SEMAPHORE_BASIC_INFORMATION *SemaphoreInformation)
{
  int v6; // edx
  int v7; // ebx
  int v8; // esi
  int v9; // edi
  _SEMAPHORE_BASIC_INFORMATION *v10; // eax

  v7 = ObReferenceObjectByHandle(a1, a2, a3, a4, SemaphoreHandle, &ExSemaphoreObjectType, &SemaphoreHandle);
  if ( v7 >= 0 )
  {
    v8 = *((_DWORD *)SemaphoreHandle + 1);
    v9 = *((_DWORD *)SemaphoreHandle + 4);
    ObfDereferenceObject(SemaphoreHandle, v6);
    v10 = SemaphoreInformation;
    SemaphoreInformation->MaximumCount = v9;
    v10->CurrentCount = v8;
  }
  return v7;
}