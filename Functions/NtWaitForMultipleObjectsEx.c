int *__userpurge NtWaitForMultipleObjectsEx@<eax>(unsigned int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, unsigned int Count, void **Handles, _WAIT_TYPE WaitType, char WaitMode, char Alertable, _LARGE_INTEGER *Timeout)
{
  unsigned int v10; // ebx
  void **v12; // esi
  int v13; // eax
  unsigned int v14; // eax
  void *v15; // eax
  int *v16; // esi
  unsigned int i; // edi
  void *Objects[64]; // [esp+Ch] [ebp-228h]
  $BF16CCDE09548A090BDCACE0A5BC0AD1 WaitState; // [esp+10Ch] [ebp-128h]
  int Status; // [esp+20Ch] [ebp-28h]
  unsigned int RefCount; // [esp+214h] [ebp-20h]
  _KWAIT_BLOCK *WaitBlockArray; // [esp+218h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+21Ch] [ebp-18h]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\obx\\obwait.c",
      0x189u,
      0);
  v10 = 0;
  if ( !Count || Count > 0x40 || WaitType != 1 && WaitType )
    return (int *)-1073741811;
  if ( Count <= 9 )
  {
    WaitBlockArray = WaitState.WaitBlocks;
  }
  else
  {
    WaitBlockArray = (_KWAIT_BLOCK *)ExAllocatePoolWithTag(a1, a2, a4, 24 * Count, 0x74696157u);
    if ( !WaitBlockArray )
      return (int *)-1073741670;
  }
  RefCount = 0;
  do
  {
    v12 = &Objects[v10];
    v13 = ObpGetObjectHandleReference(
            a1,
            a2,
            (int *)((char *)Handles - (char *)Objects),
            (int)v12,
            *(void **)((char *)v12 + (char *)Handles - (char *)Objects));
    if ( !v13 )
    {
      v16 = (int *)-1073741816;
      goto ServiceFailed;
    }
    ++RefCount;
    *v12 = (void *)v13;
    a2 = *(_DWORD *)(*(_DWORD *)(v13 - 8) + 20);
    if ( a2 >= 0 )
      a2 += v13;
    WaitState.WaitObjects[v10++] = (void *)a2;
  }
  while ( v10 < Count );
  if ( WaitType )
  {
LABEL_23:
    ms_exc.registration.TryLevel = 0;
    v16 = KeWaitForMultipleObjects(
            a1,
            a2,
            (int)v12,
            Count,
            WaitState.WaitObjects,
            WaitType,
            UserRequest,
            WaitMode,
            Alertable,
            Timeout,
            WaitBlockArray);
    Status = (int)v16;
    ms_exc.registration.TryLevel = -1;
  }
  else
  {
    v14 = 0;
    while ( 1 )
    {
      a1 = v14 + 1;
      a2 = v14 + 1;
      if ( v14 + 1 < Count )
        break;
LABEL_22:
      v14 = a1;
      if ( a1 >= Count )
        goto LABEL_23;
    }
    v15 = WaitState.WaitObjects[v14];
    while ( v15 != WaitState.WaitObjects[a2] )
    {
      if ( ++a2 >= Count )
        goto LABEL_22;
    }
    v16 = (int *)-1073741776;
  }
ServiceFailed:
  for ( i = RefCount; i; ObfDereferenceObject(Objects[i], a1) )
    --i;
  if ( WaitBlockArray != WaitState.WaitBlocks )
    ExFreePool(WaitBlockArray);
  return v16;
}