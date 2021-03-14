void __stdcall KiDispatchException(_EXCEPTION_RECORD *ExceptionRecord, _KTRAP_FRAME *ExceptionFrame, _KTRAP_FRAME *TrapFrame, char FirstChance)
{
  _CONTEXT ContextFrame; // [esp+8h] [ebp-238h]

  ContextFrame.ContextFlags = 65579;
  KeContextFromKframes(TrapFrame, &ContextFrame);
  if ( ExceptionRecord->ExceptionCode == -2147483645 )
    --ContextFrame.Eip;
  if ( (FirstChance != 1
     || (!KiDebugRoutine || !KiDebugRoutine(TrapFrame, ExceptionFrame, ExceptionRecord, &ContextFrame, 0))
     && RtlDispatchException(ExceptionRecord, &ContextFrame) != 1)
    && (!KiDebugRoutine || !KiDebugRoutine(TrapFrame, ExceptionFrame, ExceptionRecord, &ContextFrame, 1)) )
  {
    KeBugCheckEx(
      0x1Eu,
      ExceptionRecord->ExceptionCode,
      (unsigned int)ExceptionRecord->ExceptionAddress,
      ExceptionRecord->ExceptionInformation[0],
      ExceptionRecord->ExceptionInformation[1]);
  }
  KeContextToKframes(TrapFrame, &ContextFrame, ContextFrame.ContextFlags);
}