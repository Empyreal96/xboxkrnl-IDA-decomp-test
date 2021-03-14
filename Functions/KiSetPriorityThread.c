void __usercall KiSetPriorityThread(_KTHREAD *Thread@<ecx>, int Priority@<edx>, int *a3@<edi>)
{
  int v3; // ebx
  _KTHREAD *v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  _KTHREAD *v8; // eax
  _KTHREAD *v9; // eax
  _LIST_ENTRY *v10; // edi
  _LIST_ENTRY *v11; // eax
  _LIST_ENTRY *v12; // edx
  int v13; // ecx
  _LIST_ENTRY *v14; // edx

  v3 = Priority;
  v4 = Thread;
  if ( Priority > 31 )
    RtlAssert(
      Priority,
      (int)Thread,
      a3,
      (int)Thread,
      "Priority <= HIGH_PRIORITY",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredsup.c",
      0x182u,
      0);
  v5 = v4->Priority;
  if ( v3 != v5 )
  {
    v6 = (unsigned __int8)v4->State - 1;
    v4->Priority = v3;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 == 1 && v3 < v5 )
        {
          v8 = KiFindReadyThread(v3);
          if ( v8 )
          {
            v8->State = 3;
            dword_8004C5D8 = (int)v8;
LABEL_10:
            KiReadyThread(v4);
            return;
          }
        }
      }
      else if ( !dword_8004C5D8 && v3 < v5 )
      {
        v9 = KiFindReadyThread(v3);
        if ( v9 )
        {
          v9->State = 3;
          dword_8004C5D8 = (int)v9;
        }
      }
    }
    else
    {
      v10 = v4->WaitListEntry.Blink;
      v11 = &v4->WaitListEntry;
      v12 = v4->WaitListEntry.Flink;
      v10->Flink = v12;
      v12->Blink = v10;
      if ( *(_DWORD *)(8 * v5 - 2147151840) == 8 * v5 - 2147151840 )
        KiReadySummary &= ~(1 << v5);
      if ( v3 >= v5 )
        goto LABEL_10;
      v13 = 8 * v3 - 2147151840;
      v14 = *(_LIST_ENTRY **)(v13 + 4);
      v11->Flink = (_LIST_ENTRY *)v13;
      v4->WaitListEntry.Blink = v14;
      v14->Flink = v11;
      *(_DWORD *)(v13 + 4) = v11;
      KiReadySummary |= 1 << v3;
    }
  }
}