char __stdcall KdpStub(_KTRAP_FRAME *TrapFrame, _KTRAP_FRAME *ExceptionFrame, _EXCEPTION_RECORD *ExceptionRecord, _CONTEXT *ContextRecord, char SecondChance)
{
  unsigned int v5; // eax
  char result; // al

  if ( ExceptionRecord->ExceptionCode == -2147483645
    && ExceptionRecord->NumberParameters
    && ((v5 = ExceptionRecord->ExceptionInformation[0], v5 == 3) || v5 == 4 || v5 == 7 || v5 == 8 || v5 == 11 || v5 == 1) )
  {
    ++ContextRecord->Eip;
    result = 1;
  }
  else if ( KdDebuggerEnabled )
  {
    result = KdpCheckTracePoint(ExceptionRecord, ContextRecord);
  }
  else
  {
    result = 0;
  }
  return result;
}