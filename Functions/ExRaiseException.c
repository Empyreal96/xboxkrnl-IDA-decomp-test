void __userpurge __noreturn ExRaiseException(unsigned int a1@<eax>, unsigned int a2@<edx>, unsigned int a3@<ecx>, _EXCEPTION_RECORD *ExceptionRecord, int a5, int a6, int a7)
{
  unsigned int v7; // et0
  int v8; // eax
  int v9; // eax
  _CONTEXT ContextRecord; // [esp+0h] [ebp-244h]
  unsigned int v11; // [esp+240h] [ebp-4h]
  unsigned int vars0; // [esp+244h] [ebp+0h]
  void *retaddr; // [esp+248h] [ebp+4h]

  v7 = __readeflags();
  v11 = v7;
  ContextRecord.Eax = a1;
  ContextRecord.Ecx = a3;
  ExceptionRecord->ExceptionAddress = retaddr;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Edx = a2;
  ContextRecord.Esp = (unsigned int)&ExceptionRecord;
  ContextRecord.Ebp = vars0;
  ContextRecord.EFlags = v11;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegSs) = __SS__;
  ContextRecord.ContextFlags = 65543;
  LOBYTE(v8) = RtlDispatchException(ExceptionRecord, &ContextRecord);
  if ( !v8 )
    ZwRaiseException((int)ExceptionRecord, (unsigned int)&ContextRecord, 0);
  v9 = ZwContinue((int)&ContextRecord, 0);
  ExRaiseStatus(v9);
}