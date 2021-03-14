int __stdcall NtYieldExecution()
{
  signed int v0; // edi
  _KTHREAD *v1; // esi
  signed int v2; // ecx
  int v3; // eax
  _LIST_ENTRY *v4; // edi

  v0 = 1073741860;
  if ( KiReadySummary )
  {
    v1 = thread;
    v1->WaitIrql = KeRaiseIrqlToDpcLevel();
    if ( dword_8004C5D8 || (dword_8004C5D8 = (int)KiFindReadyThread(1)) != 0 )
    {
      v2 = v1->Priority;
      v1->Quantum = v1->ApcState.Process->ThreadQuantum;
      v1->State = 1;
      if ( v2 < 16 )
      {
        v2 += -1 - v1->PriorityDecrement;
        if ( v2 < v1->BasePriority )
          v2 = v1->BasePriority;
        v1->PriorityDecrement = 0;
      }
      v3 = 8 * v2 - 2147151840;
      v1->Priority = v2;
      v4 = *(_LIST_ENTRY **)(v3 + 4);
      v1->WaitListEntry.Flink = (_LIST_ENTRY *)v3;
      v1->WaitListEntry.Blink = v4;
      v4->Flink = &v1->WaitListEntry;
      *(_DWORD *)(v3 + 4) = (char *)v1 + 92;
      KiReadySummary |= 1 << v2;
      KiSwapThread();
      v0 = 0;
    }
    else
    {
      KiUnlockDispatcherDatabase(v1->WaitIrql);
    }
  }
  return v0;
}