void __userpurge KeSetSystemTime(int a1@<edx>, int a2@<ecx>, int *a3@<edi>, int a4@<esi>, _LARGE_INTEGER *NewTime, _LARGE_INTEGER *OldTime)
{
  KIRQL v6; // al
  int v7; // ecx
  unsigned int v8; // edi
  unsigned int v9; // ebx
  _LIST_ENTRY *v10; // edx
  _LIST_ENTRY *v11; // eax
  _LIST_ENTRY *v12; // ecx
  bool v13; // zf
  _LIST_ENTRY *v14; // esi
  _LIST_ENTRY *v15; // edx
  _LIST_ENTRY *v16; // ecx
  _LIST_ENTRY *v17; // eax
  _KTIMER *v18; // esi
  bool v19; // cf
  _LIST_ENTRY *v20; // ecx
  _ULARGE_INTEGER v21; // [esp-14h] [ebp-2Ch]
  int *v22; // [esp-Ch] [ebp-24h]
  int v23; // [esp-8h] [ebp-20h]
  _LIST_ENTRY ExpiredListHead; // [esp+0h] [ebp-18h]
  _LIST_ENTRY AbsoluteListHead; // [esp+8h] [ebp-10h]
  _LIST_ENTRY *NextEntry; // [esp+10h] [ebp-8h]
  char OldIrql1; // [esp+17h] [ebp-1h]
  _LARGE_INTEGER *NewTimea; // [esp+20h] [ebp+8h]
  _LIST_ENTRY *OldTimea; // [esp+24h] [ebp+Ch]

  if ( (unsigned __int8)dword_8004C5D0 >= 2u )
    RtlAssert(
      a1,
      a2,
      a3,
      a4,
      "KeGetCurrentIrql() < DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\miscc.c",
      0xCDu,
      0);
  v23 = a4;
  v22 = a3;
  OldIrql1 = KeRaiseIrqlToDpcLevel();
  v6 = KfRaiseIrql(31);
  v7 = KeSystemTime.High1Time;
  *OldTime = *(_LARGE_INTEGER *)&KeSystemTime.LowPart;
  if ( v7 != KeSystemTime.High2Time )
  {
    do
    {
      _mm_pause();
      *OldTime = *(_LARGE_INTEGER *)&KeSystemTime.LowPart;
    }
    while ( OldTime->HighPart != KeSystemTime.High2Time );
  }
  KeSystemTime.High2Time = NewTime->HighPart;
  *(_LARGE_INTEGER *)&KeSystemTime.LowPart = *NewTime;
  v8 = NewTime->LowPart - OldTime->LowPart;
  v9 = (unsigned __int64)(*(_QWORD *)NewTime - *(_QWORD *)OldTime) >> 32;
  KeBootTime.QuadPart += *(_QWORD *)NewTime - *(_QWORD *)OldTime;
  KeBootTimeBias += __PAIR__(v9, v8);
  KfLowerIrql(v6);
  AbsoluteListHead.Blink = &AbsoluteListHead;
  AbsoluteListHead.Flink = &AbsoluteListHead;
  OldTimea = KiTimerTableListHead;
  NewTimea = (_LARGE_INTEGER *)32;
  do
  {
    v11 = OldTimea->Flink;
    while ( v11 != OldTimea )
    {
      v12 = v11 - 3;
      v13 = BYTE1(v11[-3].Flink) == 0;
      v11 = v11->Flink;
      NextEntry = v11;
      if ( !v13 )
      {
        v14 = v12[3].Blink;
        v15 = v12[3].Flink;
        v14->Flink = v15;
        v15->Blink = v14;
        v10 = AbsoluteListHead.Blink;
        v12[3].Flink = &AbsoluteListHead;
        v12[3].Blink = v10;
        v10->Flink = v12 + 3;
        AbsoluteListHead.Blink = v12 + 3;
        v11 = NextEntry;
      }
    }
    ++OldTimea;
    NewTimea = (_LARGE_INTEGER *)((char *)NewTimea - 1);
  }
  while ( NewTimea );
  ExpiredListHead.Blink = &ExpiredListHead;
  ExpiredListHead.Flink = &ExpiredListHead;
  while ( !IsListEmpty(&AbsoluteListHead) )
  {
    v16 = AbsoluteListHead.Flink->Blink;
    v17 = AbsoluteListHead.Flink->Flink;
    v18 = (_KTIMER *)&AbsoluteListHead.Flink[-3];
    v18->Header.Inserted = 0;
    v16->Flink = v17;
    v17->Blink = v16;
    v18->TimerListEntry.Flink = 0;
    v18->TimerListEntry.Blink = 0;
    v19 = v18->DueTime.LowPart < v8;
    v18->DueTime.LowPart -= v8;
    v18->DueTime.HighPart -= v19 + v9;
    v21 = v18->DueTime;
    if ( !KiReinsertTreeTimer(v18, (int)v10, v21) )
    {
      v18->Header.Inserted = 1;
      v20 = ExpiredListHead.Blink;
      v10 = &ExpiredListHead;
      v18->TimerListEntry.Flink = &ExpiredListHead;
      v18->TimerListEntry.Blink = v20;
      v20->Flink = &v18->TimerListEntry;
      ExpiredListHead.Blink = &v18->TimerListEntry;
    }
  }
  KiTimerListExpire(&ExpiredListHead, OldIrql1);
}