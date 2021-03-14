void __fastcall KiReadyThread(_KTHREAD *Thread)
{
  _KTHREAD *v1; // eax
  signed int v2; // ecx
  char v3; // bl
  int v4; // edx
  _LIST_ENTRY *v5; // esi
  _LIST_ENTRY *v6; // edx
  _LIST_ENTRY *v7; // edi
  _LIST_ENTRY *v8; // edi

  v1 = Thread;
  v2 = Thread->Priority;
  v3 = v1->Preempted;
  v1->Preempted = 0;
  v1->WaitTime = KeTickCount;
  while ( 1 )
  {
    if ( KiIdleSummary )
    {
      KiIdleSummary = 0;
LABEL_9:
      dword_8004C5D8 = (int)v1;
      v1->State = 3;
      return;
    }
    v4 = dword_8004C5D8;
    if ( !dword_8004C5D8 )
      break;
    if ( v2 <= *(char *)(dword_8004C5D8 + 50) )
      goto LABEL_10;
    *(_BYTE *)(dword_8004C5D8 + 118) = 1;
    dword_8004C5D8 = (int)v1;
    v1->State = 3;
    v3 = *(_BYTE *)(v4 + 118);
    *(_BYTE *)(v4 + 118) = 0;
    v2 = *(char *)(v4 + 50);
    v1 = (_KTHREAD *)v4;
    *(_DWORD *)(v4 + 100) = KeTickCount;
  }
  if ( v2 > thread->Priority )
  {
    thread->Preempted = 1;
    goto LABEL_9;
  }
LABEL_10:
  v1->State = 1;
  v5 = &v1->WaitListEntry;
  v6 = (_LIST_ENTRY *)(8 * v2 - 2147151840);
  if ( v3 )
  {
    v7 = v6->Flink;
    v5->Flink = v6->Flink;
    v1->WaitListEntry.Blink = v6;
    v7->Blink = v5;
    v6->Flink = v5;
  }
  else
  {
    v8 = v6->Blink;
    v5->Flink = v6;
    v1->WaitListEntry.Blink = v8;
    v8->Flink = v5;
    v6->Blink = v5;
  }
  KiReadySummary |= 1 << v2;
}