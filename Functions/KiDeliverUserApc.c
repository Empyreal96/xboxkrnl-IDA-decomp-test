void __stdcall KiDeliverUserApc()
{
  _KTHREAD *v0; // edi
  char v1; // al
  int *v2; // edi
  bool v3; // zf
  int *v4; // eax
  int v5; // esi
  void (__stdcall *v6)(int, void (__stdcall **)(void *, void *, void *), void **, void **, void **); // ebx
  int v7; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  int v10; // ecx
  char v11; // al
  void *NormalContext; // [esp+4h] [ebp-14h]
  void *SystemArgument1; // [esp+8h] [ebp-10h]
  void *SystemArgument2; // [esp+Ch] [ebp-Ch]
  void (__stdcall *NormalRoutine)(void *, void *, void *); // [esp+10h] [ebp-8h]
  char OldIrql; // [esp+17h] [ebp-1h]

  v0 = thread;
  v1 = KeRaiseIrqlToSynchLevel();
  v0->ApcState.UserApcPending = 0;
  v2 = (int *)&v0->ApcState.ApcListHead[1];
  v3 = *v2 == (_DWORD)v2;
  for ( OldIrql = v1; !v3; OldIrql = v11 )
  {
    v4 = (int *)*v2;
    v5 = *v2 - 8;
    v6 = *(void (__stdcall **)(int, void (__stdcall **)(void *, void *, void *), void **, void **, void **))(v5 + 16);
    NormalRoutine = *(void (__stdcall **)(void *, void *, void *))(v5 + 24);
    NormalContext = *(void **)(v5 + 28);
    SystemArgument1 = *(void **)(v5 + 32);
    SystemArgument2 = *(void **)(v5 + 36);
    v7 = *v4;
    v8 = (_DWORD *)v4[1];
    *v8 = v7;
    *(_DWORD *)(v7 + 4) = v8;
    LOBYTE(v7) = OldIrql;
    *(_BYTE *)(v5 + 3) = 0;
    KfLowerIrql(v7);
    v6(v5, &NormalRoutine, &NormalContext, &SystemArgument1, &SystemArgument2);
    if ( (_BYTE)dword_8004C5D0 != OldIrql )
      KeBugCheckEx(
        0xC8u,
        (((unsigned __int8)OldIrql | ((unsigned __int8)dword_8004C5D0 << 8)) << 8) | 1,
        (unsigned int)v6,
        v5,
        (unsigned int)NormalRoutine);
    if ( OldIrql )
      RtlAssert(v9, v10, v2, v5, "OldIrql == PASSIVE_LEVEL", "d:\\xbox-apr03\\private\\ntos\\ke\\apcsup.c", 0xEEu, 0);
    if ( NormalRoutine )
      NormalRoutine(NormalContext, SystemArgument1, SystemArgument2);
    v11 = KeRaiseIrqlToSynchLevel();
    v3 = *v2 == (_DWORD)v2;
  }
  KfLowerIrql(OldIrql);
}