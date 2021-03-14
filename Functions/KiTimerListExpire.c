void __fastcall KiTimerListExpire(_LIST_ENTRY *ExpiredListHead, char OldIrql)
{
  _LIST_ENTRY *v2; // eax
  bool v3; // zf
  void (__stdcall **v4)(_KDPC *, void *, void *, void *); // edi
  _KTIMER *v5; // esi
  _LIST_ENTRY *v6; // eax
  _LIST_ENTRY *v7; // ecx
  int v8; // eax
  _LARGE_INTEGER v9; // rax
  _KDPC *v10; // esi
  void (__stdcall *v11)(_KDPC *, void *, void *, void *); // eax
  void (__stdcall *v12)(_KDPC *, void *, void *, void *); // eax
  int *v13; // edi
  void **v14; // esi
  int v15; // edx
  int v16; // ecx
  _DPC_ENTRY DpcList[16]; // [esp+0h] [ebp-DCh]
  _LARGE_INTEGER Interval; // [esp+C0h] [ebp-1Ch]
  _LARGE_INTEGER SystemTime; // [esp+C8h] [ebp-14h]
  _LIST_ENTRY *v20; // [esp+D0h] [ebp-Ch]
  int Count; // [esp+D4h] [ebp-8h]
  KIRQL NewIrql; // [esp+D8h] [ebp-4h]

  NewIrql = OldIrql;
  v20 = ExpiredListHead;
  while ( 1 )
  {
    SystemTime = *(_LARGE_INTEGER *)&KeSystemTime.LowPart;
    if ( KeSystemTime.High1Time == KeSystemTime.High2Time )
      break;
    _mm_pause();
  }
  while ( 1 )
  {
    v2 = v20->Flink;
    v3 = v20->Flink == v20;
    Count = 0;
    if ( v3 )
      break;
    v4 = &DpcList[0].Routine;
    do
    {
      v5 = (_KTIMER *)&v2[-3];
      v6 = v2->Flink;
      v7 = v5->TimerListEntry.Blink;
      v5->Header.Inserted = 0;
      v7->Flink = v6;
      v6->Blink = v7;
      v3 = v5->Header.WaitListHead.Flink == &v5->Header.WaitListHead;
      v5->TimerListEntry.Flink = 0;
      v5->TimerListEntry.Blink = 0;
      v5->Header.SignalState = 1;
      if ( !v3 )
        KiWaitTest(v5, 0);
      v8 = v5->Period;
      if ( v8 )
      {
        v9.QuadPart = -10000i64 * v8;
        Interval = v9;
        while ( !KiInsertTreeTimer(v5, v9.HighPart, Interval) )
          ;
      }
      v10 = v5->Dpc;
      if ( v10 )
      {
        v11 = v10->DeferredRoutine;
        ++Count;
        *v4 = v11;
        v12 = (void (__stdcall *)(_KDPC *, void *, void *, void *))v10->DeferredContext;
        *(v4 - 1) = (void (__stdcall *)(_KDPC *, void *, void *, void *))v10;
        v4[1] = v12;
        v4 += 3;
        if ( Count == 16 )
          break;
      }
      v2 = v20->Flink;
    }
    while ( v20->Flink != v20 );
    if ( !Count )
      break;
    KiUnlockDispatcherDatabase(2);
    v13 = 0;
    v14 = &DpcList[0].Context;
    do
    {
      unk_8004C5F0 = 0;
      ((void (__stdcall *)(_DWORD, void *, unsigned int, int))*(v14 - 1))(
        *(v14 - 2),
        *v14,
        SystemTime.LowPart,
        SystemTime.HighPart);
      v13 = (int *)((char *)v13 + 1);
      v14 += 3;
    }
    while ( (signed int)v13 < Count );
    if ( Count != 16 )
    {
      KfLowerIrql(NewIrql);
      return;
    }
    if ( (_BYTE)dword_8004C5D0 != 2 )
      RtlAssert(
        v15,
        v16,
        v13,
        (int)v14,
        "KeGetCurrentIrql() == DISPATCH_LEVEL",
        "d:\\xbox-apr03\\private\\ntos\\ke\\dpcsup.c",
        0x1CCu,
        0);
  }
  KiUnlockDispatcherDatabase(NewIrql);
}