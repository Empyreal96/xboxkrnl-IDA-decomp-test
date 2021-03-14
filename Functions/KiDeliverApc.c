void __stdcall KiDeliverApc()
{
  _KTHREAD *v0; // esi
  unsigned __int8 v1; // bl
  bool v2; // zf
  _LIST_ENTRY *v3; // eax
  unsigned int v4; // esi
  _LIST_ENTRY *v5; // edi
  _LIST_ENTRY *v6; // ecx
  _LIST_ENTRY *v7; // eax
  _LIST_ENTRY *v8; // ecx
  _LIST_ENTRY *v9; // eax
  void *NormalContext; // [esp+Ch] [ebp-14h]
  void *SystemArgument1; // [esp+10h] [ebp-10h]
  void *SystemArgument2; // [esp+14h] [ebp-Ch]
  _KTHREAD *Thread; // [esp+18h] [ebp-8h]
  void (__stdcall *NormalRoutine)(void *, void *, void *); // [esp+1Ch] [ebp-4h]

  v0 = thread;
  Thread = thread;
  v1 = KeRaiseIrqlToSynchLevel();
  v2 = v0->ApcState.ApcListHead[0].Flink == v0->ApcState.ApcListHead;
  v0->ApcState.KernelApcPending = 0;
  if ( !v2 )
  {
    while ( 1 )
    {
      v3 = v0->ApcState.ApcListHead[0].Flink;
      v4 = (unsigned int)&v3[-1];
      v5 = v3[1].Flink;
      NormalRoutine = (void (__stdcall *)(void *, void *, void *))v3[2].Flink;
      NormalContext = v3[2].Blink;
      SystemArgument1 = v3[3].Flink;
      SystemArgument2 = v3[3].Blink;
      if ( NormalRoutine )
      {
        if ( Thread->ApcState.KernelApcInProgress || Thread->KernelApcDisable )
          break;
        v8 = v3->Flink;
        v9 = v3->Blink;
        v9->Flink = v8;
        v8->Blink = v9;
        *(_BYTE *)(v4 + 3) = 0;
        KfLowerIrql(v1);
        ((void (__stdcall *)(unsigned int, void (__stdcall **)(void *, void *, void *), void **, void **, void **))v5)(
          v4,
          &NormalRoutine,
          &NormalContext,
          &SystemArgument1,
          &SystemArgument2);
        if ( (_BYTE)dword_8004C5D0 != v1 )
          KeBugCheckEx(
            0xC8u,
            ((v1 | ((unsigned __int8)dword_8004C5D0 << 8)) << 8) | 1,
            (unsigned int)v5,
            v4,
            (unsigned int)NormalRoutine);
        if ( NormalRoutine )
        {
          Thread->ApcState.KernelApcInProgress = 1;
          KfLowerIrql(0);
          NormalRoutine(NormalContext, SystemArgument1, SystemArgument2);
          KfRaiseIrql(1);
        }
        v1 = KeRaiseIrqlToSynchLevel();
        Thread->ApcState.KernelApcInProgress = 0;
      }
      else
      {
        v6 = v3->Flink;
        v7 = v3->Blink;
        v7->Flink = v6;
        v6->Blink = v7;
        *(_BYTE *)(v4 + 3) = 0;
        KfLowerIrql(v1);
        ((void (__stdcall *)(unsigned int, void (__stdcall **)(void *, void *, void *), void **, void **, void **))v5)(
          v4,
          &NormalRoutine,
          &NormalContext,
          &SystemArgument1,
          &SystemArgument2);
        if ( (_BYTE)dword_8004C5D0 != v1 )
          KeBugCheckEx(
            0xC8u,
            (v1 | ((unsigned __int8)dword_8004C5D0 << 8)) << 8,
            (unsigned int)v5,
            v4,
            (unsigned int)NormalRoutine);
        v1 = KeRaiseIrqlToSynchLevel();
      }
      if ( (_KAPC_STATE *)Thread->ApcState.ApcListHead[0].Flink == &Thread->ApcState )
        break;
      v0 = Thread;
    }
  }
  KfLowerIrql(v1);
}