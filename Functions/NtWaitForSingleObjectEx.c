int *__userpurge NtWaitForSingleObjectEx@<eax>(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, void *Handle, char WaitMode, char Alertable, _LARGE_INTEGER *Timeout)
{
  int v8; // edx
  int *v9; // esi
  char *v10; // eax
  int v11; // edx
  void *Object; // [esp+14h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+18h] [ebp-18h]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obwait.c",
      0x112u,
      0);
  v9 = (int *)ObReferenceObjectByHandle(a1, a2, a3, a4, Handle, 0, &Object);
  if ( (signed int)v9 >= 0 )
  {
    v10 = *(char **)(*((_DWORD *)Object - 2) + 20);
    if ( (signed int)v10 >= 0 )
      v10 = &v10[(_DWORD)Object];
    ms_exc.registration.TryLevel = 0;
    v9 = KeWaitForSingleObject((int)Object, v8, v10, UserRequest, WaitMode, Alertable, Timeout);
    ms_exc.registration.TryLevel = -1;
    ObfDereferenceObject(Object, v11);
  }
  return v9;
}