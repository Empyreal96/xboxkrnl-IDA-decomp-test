int __stdcall KiRaiseException(_EXCEPTION_RECORD *ExceptionRecord, _CONTEXT *ContextRecord, _KTRAP_FRAME *ExceptionFrame, _KTRAP_FRAME *TrapFrame, char FirstChance)
{
  KeContextToKframes(TrapFrame, ContextRecord, ContextRecord->ContextFlags);
  HIBYTE(ExceptionRecord->ExceptionCode) &= 0xEFu;
  KiDispatchException(ExceptionRecord, ExceptionFrame, TrapFrame, FirstChance);
  return 0;
}