int __userpurge NtReleaseSemaphore@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *SemaphoreHandle, int ReleaseCount, int *PreviousCount)
{
  int v8; // edx
  int v9; // ecx
  int v10; // edi
  int v11; // esi
  int v12; // edx
  void *Semaphore; // [esp+14h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+18h] [ebp-18h]

  if ( ReleaseCount <= 0 )
    return -1073741811;
  v10 = ObReferenceObjectByHandle(a1, a2, a3, a4, SemaphoreHandle, &ExSemaphoreObjectType, &Semaphore);
  if ( v10 >= 0 )
  {
    ms_exc.registration.TryLevel = 0;
    v11 = KeReleaseSemaphore(v9, v8, (_KSEMAPHORE *)Semaphore, 1, ReleaseCount, 0);
    ObfDereferenceObject(Semaphore, v12);
    if ( PreviousCount )
      *PreviousCount = v11;
    ms_exc.registration.TryLevel = -1;
  }
  return v10;
}