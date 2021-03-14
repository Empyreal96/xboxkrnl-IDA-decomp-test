void __stdcall ExpTimerApcRoutine(_KAPC *Apc, void (__stdcall **NormalRoutine)(void *, void *, void *), void **NormalContext, void **SystemArgument1, void **SystemArgument2)
{
  int *v5; // edi
  _KAPC *v6; // esi
  int v7; // edx
  int v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  int v11; // edx
  char OldIrql; // [esp+Fh] [ebp-1h]
  char Dereference_3; // [esp+1Bh] [ebp+Bh]

  v5 = (int *)&thread->Header.Type;
  v6 = Apc - 1;
  Dereference_3 = 0;
  OldIrql = KeRaiseIrqlToDpcLevel();
  if ( (_BYTE)dword_8004C5D0 != 2 )
    RtlAssert(
      v7,
      v8,
      v5,
      (int)v6,
      "KeGetCurrentIrql() == DISPATCH_LEVEL",
      "d:\\xbox-apr03\\private\\ntos\\ex\\timer.c",
      0x8Bu,
      0);
  if ( LOBYTE(v6[3].Type) && v5 == (int *)v6[1].Thread )
  {
    if ( !v6[2].SystemArgument2 )
    {
      v9 = v6[2].NormalContext;
      v10 = v6[2].SystemArgument1;
      *v10 = v9;
      v9[1] = v10;
      LOBYTE(v6[3].Type) = 0;
      Dereference_3 = 1;
    }
  }
  else
  {
    *NormalRoutine = 0;
  }
  KfLowerIrql(OldIrql);
  if ( Dereference_3 )
    ObfDereferenceObject(v6, v11);
}