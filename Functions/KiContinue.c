int __stdcall KiContinue(_CONTEXT *ContextRecord, _KTRAP_FRAME *ExceptionFrame, _KTRAP_FRAME *TrapFrame)
{
  char v3; // bl
  char OldIrql; // [esp+7h] [ebp-1h]

  v3 = 0;
  if ( (unsigned __int8)dword_8004C5D0 < 1u )
  {
    v3 = 1;
    OldIrql = KfRaiseIrql(1);
  }
  KeContextToKframes(TrapFrame, ContextRecord, ContextRecord->ContextFlags);
  if ( v3 )
    KfLowerIrql(OldIrql);
  return 0;
}