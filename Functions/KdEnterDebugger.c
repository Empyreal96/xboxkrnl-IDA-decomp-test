unsigned int __stdcall KdEnterDebugger(_KTRAP_FRAME *TrapFrame, _KTRAP_FRAME *ExceptionFrame)
{
  unsigned int result; // eax
  _LARGE_INTEGER *savedregs; // [esp+0h] [ebp+0h]

  if ( TrapFrame )
  {
    KdTimerStop = KeQueryPerformanceCounter(savedregs);
    KdTimerDifference.QuadPart = KdTimerStop.QuadPart - KdTimerStart.QuadPart;
  }
  else
  {
    KdTimerStop.QuadPart = 0i64;
  }
  result = KiDisableInterrupts();
  KdEnteredDebugger = 1;
  return result;
}