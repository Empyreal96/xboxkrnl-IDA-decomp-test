void __fastcall __noreturn RtlRaiseStatus(int a1, int a2, int Status)
{
  _EXCEPTION_RECORD ExceptionRecord; // [esp+0h] [ebp-50h]

  ExceptionRecord.ExceptionRecord = 0;
  ExceptionRecord.NumberParameters = 0;
  ExceptionRecord.ExceptionFlags = 1;
  RtlRaiseException((int)&ExceptionRecord, a2, a1, (int)&ExceptionRecord, Status);
}