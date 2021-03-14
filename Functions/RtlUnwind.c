void __stdcall RtlUnwind(void *TargetFrame, void *TargetIp, _EXCEPTION_RECORD *ExceptionRecord, void *ReturnValue)
{
  _EXCEPTION_RECORD *v4; // esi
  int v5; // edx
  int v6; // ecx
  unsigned int v7; // ebx
  unsigned int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  char v13; // [esp-4h] [ebp-2F0h]
  _CONTEXT ContextRecord1; // [esp+8h] [ebp-2E4h]
  _EXCEPTION_RECORD ExceptionRecord1; // [esp+240h] [ebp-ACh]
  _EXCEPTION_RECORD ExceptionRecord2; // [esp+290h] [ebp-5Ch]
  _DISPATCHER_CONTEXT DispatcherContext; // [esp+2E0h] [ebp-Ch]
  unsigned int LowLimit; // [esp+2E4h] [ebp-8h]
  unsigned int HighLimit; // [esp+2E8h] [ebp-4h]
  int savedregs; // [esp+2ECh] [ebp+0h]

  RtlpGetStackLimits((void **)&LowLimit, &HighLimit);
  v4 = ExceptionRecord;
  if ( !ExceptionRecord )
  {
    v4 = &ExceptionRecord1;
    ExceptionRecord1.ExceptionCode = -1073741785;
    ExceptionRecord1.ExceptionFlags = 0;
    ExceptionRecord1.ExceptionRecord = 0;
    ExceptionRecord1.ExceptionAddress = (void *)RtlpGetReturnAddress((int)&savedregs);
    ExceptionRecord1.NumberParameters = 0;
  }
  if ( TargetFrame )
    v4->ExceptionFlags |= 2u;
  else
    v4->ExceptionFlags |= 6u;
  ContextRecord1.ContextFlags = 65543;
  RtlpCaptureContext(&savedregs, (int)&ContextRecord1);
  ContextRecord1.Esp += 16;
  ContextRecord1.Eax = (unsigned int)ReturnValue;
  v7 = RtlpGetRegistrationHead();
  while ( v7 != -1 )
  {
    if ( (void *)v7 == TargetFrame )
    {
      ZwContinue((int)&ContextRecord1, 0);
    }
    else if ( TargetFrame && (unsigned int)TargetFrame < v7 )
    {
      ExceptionRecord2.NumberParameters = 0;
      ExceptionRecord2.ExceptionCode = -1073741783;
      ExceptionRecord2.ExceptionFlags = 1;
      ExceptionRecord2.ExceptionRecord = v4;
      RtlRaiseException((int)&ExceptionRecord2, v5, v6, (int)&ExceptionRecord2, v13);
    }
    v8 = v7 + 8;
    if ( v7 < LowLimit || v8 > HighLimit )
    {
      if ( v7 & 3
        || (unsigned __int8)dword_8004C5D0 < 2u
        || !dword_8004C604
        || (v6 = dword_8004C608, v8 > dword_8004C608)
        || v7 < dword_8004C608 - 12288 )
      {
LABEL_26:
        ExceptionRecord2.NumberParameters = 0;
        ExceptionRecord2.ExceptionCode = -1073741784;
        ExceptionRecord2.ExceptionFlags = 1;
        ExceptionRecord2.ExceptionRecord = v4;
        RtlRaiseException((int)&ExceptionRecord2, v5, v6, (int)&ExceptionRecord2, v13);
      }
      HighLimit = dword_8004C608;
      LowLimit = dword_8004C608 - 12288;
    }
    else
    {
      if ( v7 & 3 )
        goto LABEL_26;
      v9 = RtlpExecuteHandlerForUnwind((int)v4, v7, (int)&ContextRecord1, (int)&DispatcherContext, *(_DWORD *)(v7 + 4))
         - 1;
      if ( v9 )
      {
        if ( v9 != 2 )
        {
          ExceptionRecord2.NumberParameters = 0;
          ExceptionRecord2.ExceptionCode = -1073741786;
          ExceptionRecord2.ExceptionFlags = 1;
          ExceptionRecord2.ExceptionRecord = v4;
          RtlRaiseException((int)&ExceptionRecord2, v10, v11, (int)&ExceptionRecord2, v13);
        }
        v7 = (unsigned int)DispatcherContext.RegistrationPointer;
      }
      v12 = v7;
      v7 = *(_DWORD *)v7;
      RtlpUnlinkHandler(v12);
    }
  }
  if ( TargetFrame != (void *)-1 )
    ZwRaiseException((int)v4, (unsigned int)&ContextRecord1, 0);
  ZwContinue((int)&ContextRecord1, 0);
}