void __stdcall __noreturn ExRaiseStatus(NTSTATUS Status)
{
  unsigned int v1; // eax
  unsigned int v2; // edx
  unsigned int v3; // ecx
  unsigned int v4; // et0
  _EXCEPTION_RECORD ExceptionRecord; // [esp+0h] [ebp-294h]
  _CONTEXT ContextRecord; // [esp+50h] [ebp-244h]
  unsigned int v7; // [esp+290h] [ebp-4h]
  unsigned int vars0; // [esp+294h] [ebp+0h]
  void *retaddr; // [esp+298h] [ebp+4h]

  v4 = __readeflags();
  v7 = v4;
  ContextRecord.Eax = v1;
  ContextRecord.Ecx = v3;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Edx = v2;
  ContextRecord.Esp = (unsigned int)&Status;
  ContextRecord.Ebp = vars0;
  ContextRecord.EFlags = v4;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegSs) = __SS__;
  ContextRecord.ContextFlags = 65543;
  ExceptionRecord.ExceptionAddress = retaddr;
  ExceptionRecord.ExceptionCode = Status;
  ExceptionRecord.NumberParameters = 0;
  ExceptionRecord.ExceptionRecord = 0;
  ExceptionRecord.ExceptionFlags = 1;
  RtlDispatchException(&ExceptionRecord, &ContextRecord);
  ZwRaiseException((int)&ExceptionRecord, (unsigned int)&ContextRecord, 1);
}