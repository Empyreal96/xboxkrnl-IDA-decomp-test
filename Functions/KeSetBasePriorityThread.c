int __fastcall KeSetBasePriorityThread(int a1, int a2, _KTHREAD *Thread, int Increment)
{
  _KTHREAD *v4; // esi
  KIRQL v5; // al
  _KPROCESS *v6; // edi
  int v7; // ebx
  char v8; // al
  char v9; // cl
  int v10; // eax
  int v11; // edx
  int v12; // eax
  signed int v14; // [esp-4h] [ebp-10h]
  KIRQL OldIrql_3; // [esp+17h] [ebp+Bh]

  v4 = Thread;
  if ( Thread->Header.Type != 6 )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "(Thread)->Header.Type == ThreadObject",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x3A7u,
      0);
  if ( (unsigned __int8)dword_8004C5D0 > 2u )
    RtlAssert(
      a2,
      a1,
      (int *)"d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      (int)Thread,
      "KeGetCurrentIrql() <= DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ke\\thredobj.c",
      0x3A8u,
      0);
  v5 = KeRaiseIrqlToDpcLevel();
  v6 = Thread->ApcState.Process;
  OldIrql_3 = v5;
  v7 = v4->BasePriority - v6->BasePriority;
  v8 = v4->Saturation;
  if ( v8 )
    v7 = 16 * v8;
  v4->Saturation = 0;
  if ( abs(Increment) >= 16 )
    v4->Saturation = 2 * (Increment > 0) - 1;
  v9 = v6->BasePriority;
  v10 = Increment + v9;
  if ( v9 >= 16 )
  {
    if ( v10 >= 16 )
    {
      if ( v10 <= 31 )
      {
LABEL_15:
        v11 = v10;
        goto LABEL_23;
      }
      v14 = 31;
    }
    else
    {
      v14 = 16;
    }
    v10 = v14;
    goto LABEL_15;
  }
  if ( v10 < 16 )
  {
    if ( v10 <= 0 )
      v10 = 1;
  }
  else
  {
    v10 = 15;
  }
  if ( v4->Saturation )
    goto LABEL_15;
  v11 = v10 + v4->Priority - v4->PriorityDecrement - v4->BasePriority;
  if ( v11 >= 16 )
    v11 = 15;
LABEL_23:
  v4->BasePriority = v10;
  v12 = v4->Priority;
  v4->DecrementCount = 0;
  v4->PriorityDecrement = 0;
  if ( v11 != v12 )
  {
    v4->Quantum = v6->ThreadQuantum;
    KiSetPriorityThread(v4, v11, (int *)v6);
  }
  KiUnlockDispatcherDatabase(OldIrql_3);
  return v7;
}