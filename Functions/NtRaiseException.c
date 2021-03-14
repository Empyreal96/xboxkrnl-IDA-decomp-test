void __stdcall NtRaiseException(_EXCEPTION_RECORD *ExceptionRecord, _CONTEXT *ContextRecord, char FirstChance)
{
  _KTRAP_FRAME *TrapFrame; // [esp+0h] [ebp+0h]

  KiPCR = (unsigned int)TrapFrame->ExceptionList;
  KiRaiseException(ExceptionRecord, ContextRecord, 0, TrapFrame, FirstChance);
  JUMPOUT(&KiServiceExit2);
}