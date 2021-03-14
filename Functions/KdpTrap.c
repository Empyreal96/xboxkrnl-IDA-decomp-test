char __stdcall KdpTrap(_KTRAP_FRAME *TrapFrame, _KTRAP_FRAME *ExceptionFrame, _EXCEPTION_RECORD *ExceptionRecord, _CONTEXT *ContextRecord, char SecondChance)
{
  _EXCEPTION_RECORD *v5; // ebx
  int v6; // ecx
  bool v7; // zf
  unsigned int v8; // eax
  _CONTEXT *v10; // edi
  unsigned int v11; // eax
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  char szRipText[10]; // [esp+Ch] [ebp-30h]
  _STRING AssertString; // [esp+18h] [ebp-24h]
  _STRING ReplyString; // [esp+20h] [ebp-1Ch]
  _STRING String; // [esp+28h] [ebp-14h]
  unsigned int OldEip; // [esp+30h] [ebp-Ch]
  int UnloadSymbols; // [esp+34h] [ebp-8h]
  __int16 v23; // [esp+38h] [ebp-4h]
  char Enable; // [esp+48h] [ebp+Ch]
  char Enablea; // [esp+48h] [ebp+Ch]
  char Enableb; // [esp+48h] [ebp+Ch]

  v5 = ExceptionRecord;
  v6 = ExceptionRecord->ExceptionCode;
  v7 = ExceptionRecord->ExceptionCode == -2147483645;
  HIBYTE(v23) = 0;
  LOBYTE(UnloadSymbols) = 0;
  if ( v7 )
  {
    v8 = ExceptionRecord->ExceptionInformation[0];
    if ( v8 )
    {
      if ( KdDebuggerNotPresent && v8 != 2 && v8 != 5 && v8 != 6 )
      {
        ++ContextRecord->Eip;
        return 1;
      }
      v10 = ContextRecord;
      OldEip = ContextRecord->Eip;
      switch ( v8 )
      {
        case 1u:
        case 0xBu:
          v11 = ExceptionRecord->ExceptionInformation[1];
          *(_DWORD *)&String.Length = *(_DWORD *)v11;
          String.Buffer = *(char **)(v11 + 4);
          KdLogDbgPrint(&String);
          if ( byte_80051593 & 8 )
            goto $L15501_0;
          Enable = KdEnterDebugger(TrapFrame, ExceptionFrame);
          v12 = KdpPrintString(&String) != 0 ? 0x80000003 : 0;
          goto LABEL_18;
        case 2u:
          v14 = ExceptionRecord->ExceptionInformation[1];
          *(_DWORD *)&String.Length = *(_DWORD *)v14;
          String.Buffer = *(char **)(v14 + 4);
          v15 = ExceptionRecord->ExceptionInformation[2];
          *(_DWORD *)&ReplyString.Length = *(_DWORD *)v15;
          ReplyString.Buffer = *(char **)(v15 + 4);
          KdLogDbgPrint(&String);
          Enable = KdEnterDebugger(TrapFrame, ExceptionFrame);
          while ( KdpPromptString(&String, &ReplyString) == 1 )
            ;
          v12 = ReplyString.Length;
          goto LABEL_18;
        case 3u:
          goto $L15498_0;
        case 4u:
          LOBYTE(UnloadSymbols) = 1;
$L15498_0:
          Enableb = KdEnterDebugger(TrapFrame, ExceptionFrame);
          KdpSaveProcessorControlState(&KdProcessorState);
          KdpContextToNt5Context(v10, &KdProcessorState.ContextFrame);
          HIBYTE(v23) = KdpReportLoadSymbolsStateChange(
                          (_STRING *)v5->ExceptionInformation[1],
                          (_KD_SYMBOLS_INFO *)v5->ExceptionInformation[2],
                          UnloadSymbols,
                          &KdProcessorState.ContextFrame);
          KdpContextFromNt5Context(v10, &KdProcessorState.ContextFrame);
          KdpRestoreProcessorControlState((int)&KdProcessorState);
          KdExitDebugger(Enableb);
          break;
        case 5u:
          v13 = ExceptionRecord->ExceptionInformation[1];
          *(_DWORD *)&String.Length = *(_DWORD *)v13;
          String.Buffer = *(char **)(v13 + 4);
          RtlInitAnsiString(&AssertString, "Break, Ignore, or Terminate Thread (bit)? ");
          ReplyString.Buffer = (char *)&ExceptionRecord + 2;
          ReplyString.MaximumLength = 2;
          Enable = KdEnterDebugger(TrapFrame, ExceptionFrame);
          KdpPrintString(&String);
          while ( KdpPromptString(&AssertString, &ReplyString) == 1 )
            ;
          v12 = SBYTE2(ExceptionRecord);
LABEL_18:
          v10->Eax = v12;
          KdExitDebugger(Enable);
          goto $L15501_0;
        case 6u:
          strcpy(szRipText, "\n***RIP: ");
          String.Buffer = szRipText;
          v23 = 10;
          String.Length = 9;
          String.MaximumLength = 10;
          KdpPrintString(&String);
          String.Buffer = (char *)v5->ExceptionInformation[1];
          String.Length = strlen(String.Buffer);
          String.MaximumLength = String.Length + 1;
          KdpPrintString(&String);
          String.Buffer = (char *)&v23;
          String.Length = 1;
          String.MaximumLength = 2;
          KdpPrintString(&String);
          Enablea = KdEnterDebugger(TrapFrame, ExceptionFrame);
          goto RipBreak;
        case 7u:
        case 8u:
        case 9u:
        case 0xAu:
$L15501_0:
          HIBYTE(v23) = 1;
          break;
        default:
          break;
      }
      v16 = v10->Eip;
      if ( v16 == OldEip )
        v10->Eip = v16 + 1;
      return HIBYTE(v23);
    }
  }
  else if ( v6 != -2147483644 && !(KdGlobalFlag & 1) && !SecondChance )
  {
    return HIBYTE(v23);
  }
  if ( !SecondChance && (v6 == -1073741769 || v6 >= 0) )
    return 0;
  Enablea = KdEnterDebugger(TrapFrame, ExceptionFrame);
  HIBYTE(v23) = KdpCheckTracePoint(v5, ContextRecord);
  if ( !HIBYTE(v23) )
  {
RipBreak:
    KdpSaveProcessorControlState(&KdProcessorState);
    KdpContextToNt5Context(ContextRecord, &KdProcessorState.ContextFrame);
    HIBYTE(v23) = KdpReportExceptionStateChange(
                    (int)&KdProcessorState,
                    v5,
                    &KdProcessorState.ContextFrame,
                    SecondChance);
    KdpContextFromNt5Context(ContextRecord, &KdProcessorState.ContextFrame);
    KdpRestoreProcessorControlState((int)&KdProcessorState);
  }
  KdExitDebugger(Enablea);
  KdpControlCPressed = 0;
  return HIBYTE(v23);
}