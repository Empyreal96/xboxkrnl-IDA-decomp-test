int *__userpurge NtSignalAndWaitForSingleObjectEx@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, void *SignalHandle, void *WaitHandle, char WaitMode, char Alertable, _LARGE_INTEGER *Timeout)
{
  int v8; // edx
  int v9; // ecx
  int *v10; // esi
  int v11; // edx
  char *v12; // esi
  _OBJECT_TYPE *v13; // eax
  int v14; // edx
  int v15; // ecx
  void *SignalObject; // [esp+1Ch] [ebp-20h]
  void *WaitObject; // [esp+20h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+24h] [ebp-18h]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      0,
      a3,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obwait.c",
      0x49u,
      0);
  v10 = (int *)ObReferenceObjectByHandle(a1, a2, 0, a3, SignalHandle, 0, &SignalObject);
  if ( (signed int)v10 >= 0 )
  {
    v10 = (int *)ObReferenceObjectByHandle(v8, v9, 0, (int)v10, WaitHandle, 0, &WaitObject);
    if ( (signed int)v10 < 0 )
    {
LABEL_17:
      ObfDereferenceObject(SignalObject, v11);
      return v10;
    }
    v12 = *(char **)(*((_DWORD *)WaitObject - 2) + 20);
    if ( (signed int)v12 >= 0 )
      v12 = &v12[(_DWORD)WaitObject];
    v13 = (_OBJECT_TYPE *)*((_DWORD *)SignalObject - 2);
    if ( v13 == &ExEventObjectType )
    {
      KeSetEvent((int)SignalObject, v11, (_KEVENT *)SignalObject, 1, 1);
    }
    else
    {
      if ( v13 == &ExMutantObjectType )
      {
        ms_exc.registration.TryLevel = 0;
        KeReleaseMutant((int)SignalObject, v11, (_KMUTANT *)SignalObject, 1, 0, 1);
      }
      else
      {
        if ( v13 != &ExSemaphoreObjectType )
        {
          v10 = (int *)-1073741788;
          goto WaitExit;
        }
        ms_exc.registration.TryLevel = 1;
        KeReleaseSemaphore((int)SignalObject, v11, (_KSEMAPHORE *)SignalObject, 1, 1, 1);
      }
      ms_exc.registration.TryLevel = -1;
    }
    ms_exc.registration.TryLevel = 2;
    v10 = KeWaitForSingleObject(v15, v14, v12, UserRequest, WaitMode, Alertable, Timeout);
    ms_exc.registration.TryLevel = -1;
WaitExit:
    ObfDereferenceObject(WaitObject, v11);
    goto LABEL_17;
  }
  return v10;
}