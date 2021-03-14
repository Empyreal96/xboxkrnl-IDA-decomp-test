_KTHREAD *__fastcall KiQuantumEnd(int a1, int a2)
{
  _KTHREAD *v2; // esi
  _KPROCESS *v3; // eax
  _KTHREAD *v4; // eax
  int v5; // esi

  v2 = thread;
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      a1,
      (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
      (int)thread,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\dpcsup.c",
      0x54u,
      0);
  if ( v2->Quantum <= 0 )
  {
    v3 = v2->ApcState.Process;
    if ( v3->DisableQuantum && v2->Priority >= 16 )
    {
      v2->Quantum = 0x7FFFFFFF;
    }
    else
    {
      a1 = v2->Priority;
      v2->Quantum = v3->ThreadQuantum;
      a2 = a1;
      if ( a1 < 16 )
      {
        a2 = a1 - v2->PriorityDecrement - 1;
        if ( a2 < v2->BasePriority )
          a2 = v2->BasePriority;
        v2->PriorityDecrement = 0;
      }
      if ( a1 == a2 )
      {
        if ( dword_8004C5D8 )
        {
          v2->Preempted = 0;
        }
        else
        {
          v4 = KiFindReadyThread(a1);
          if ( v4 )
          {
            v4->State = 3;
            dword_8004C5D8 = (int)v4;
          }
        }
      }
      else
      {
        KiSetPriorityThread(v2, a2, (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL");
      }
    }
  }
  v5 = dword_8004C5D8;
  if ( !dword_8004C5D8 && (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      a2,
      a1,
      (int *)"KeGetCurrentIrql() == DISPATCH_LEVEL",
      dword_8004C5D8,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\dpcsup.c",
      0xA2u,
      0);
  return (_KTHREAD *)v5;
}