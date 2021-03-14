char __stdcall RtlDispatchException(_EXCEPTION_RECORD *ExceptionRecord, _CONTEXT *ContextRecord)
{
  unsigned int v2; // ebx
  _EXCEPTION_REGISTRATION_RECORD *v3; // edi
  unsigned int v4; // eax
  void *v5; // ecx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  char v10; // [esp+0h] [ebp-68h]
  _EXCEPTION_RECORD ExceptionRecord1; // [esp+Ch] [ebp-5Ch]
  unsigned int LowLimit; // [esp+5Ch] [ebp-Ch]
  unsigned int HighLimit; // [esp+60h] [ebp-8h]
  _DISPATCHER_CONTEXT DispatcherContext; // [esp+64h] [ebp-4h]

  RtlpGetStackLimits((void **)&LowLimit, &HighLimit);
  v2 = RtlpGetRegistrationHead();
  v3 = 0;
  if ( v2 == -1 )
    return 0;
  v4 = dword_8004C608;
  while ( 1 )
  {
    v5 = (void *)(v2 + 8);
    if ( v2 >= LowLimit && (unsigned int)v5 <= HighLimit )
      break;
    if ( v2 & 3 || (unsigned __int8)dword_8004C5D0 < 2u || !dword_8004C604 || (unsigned int)v5 > v4 || v2 < v4 - 12288 )
    {
LABEL_27:
      ExceptionRecord->ExceptionFlags |= 8u;
      return 0;
    }
    HighLimit = v4;
    LowLimit = v4 - 12288;
LABEL_24:
    if ( v2 == -1 )
      return 0;
  }
  if ( v2 & 3 )
    goto LABEL_27;
  v6 = RtlpExecuteHandlerForException(
         v5,
         (int)ExceptionRecord,
         v2,
         (int)ContextRecord,
         (int)&DispatcherContext,
         *(int (__stdcall **)(int, int, int, int, int, int))(v2 + 4));
  if ( v3 == (_EXCEPTION_REGISTRATION_RECORD *)v2 )
  {
    ExceptionRecord->ExceptionFlags &= 0xFFFFFFEF;
    v3 = 0;
  }
  if ( v6 )
  {
    v8 = v6 - 1;
    if ( v8 )
    {
      if ( v8 != 1 )
      {
        ExceptionRecord1.ExceptionCode = -1073741786;
        goto LABEL_16;
      }
      ExceptionRecord->ExceptionFlags |= 0x10u;
      if ( DispatcherContext.RegistrationPointer > v3 )
        v3 = DispatcherContext.RegistrationPointer;
    }
    v2 = *(_DWORD *)v2;
    v4 = dword_8004C608;
    goto LABEL_24;
  }
  if ( ExceptionRecord->ExceptionFlags & 1 )
  {
    ExceptionRecord1.ExceptionCode = -1073741787;
LABEL_16:
    ExceptionRecord1.NumberParameters = 0;
    ExceptionRecord1.ExceptionRecord = ExceptionRecord;
    ExceptionRecord1.ExceptionFlags = 1;
    RtlRaiseException((int)&ExceptionRecord1, v7, 0, (int)&ExceptionRecord1, v10);
  }
  return 1;
}