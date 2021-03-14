char __stdcall KdpReportLoadSymbolsStateChange(_STRING *PathName, _KD_SYMBOLS_INFO *SymbolInfo, char UnloadSymbols, _X86_NT5_CONTEXT *ContextRecord)
{
  unsigned int v4; // ecx
  _STRING *v5; // eax
  unsigned int v6; // eax
  int v7; // eax
  _DBGKD_WAIT_STATE_CHANGE64_X86_NT5 WaitStateChange; // [esp+Ch] [ebp-3C8h]
  _STRING MessageData; // [esp+3C4h] [ebp-10h]
  _STRING MessageHeader; // [esp+3CCh] [ebp-8h]

  do
  {
    WaitStateChange.Processor = 0;
    WaitStateChange.Thread = (signed int)thread;
    WaitStateChange.ProgramCounter = (signed int)ContextRecord->Eip;
    WaitStateChange.NewState = 12337;
    WaitStateChange.ProcessorLevel = 6;
    WaitStateChange.NumberProcessors = 1;
    KdpSetLoadState(&WaitStateChange, ContextRecord);
    v4 = SymbolInfo->CheckSum;
    WaitStateChange.u.LoadSymbols.UnloadSymbols = UnloadSymbols;
    WaitStateChange.u.Exception.ExceptionRecord.ExceptionRecord = (signed int)SymbolInfo->BaseOfDll;
    WaitStateChange.u.Exception.ExceptionRecord.ExceptionAddress = SymbolInfo->ProcessId;
    v5 = 0;
    WaitStateChange.u.Exception.ExceptionRecord.NumberParameters = v4;
    WaitStateChange.u.Exception.ExceptionRecord.__unusedAlignment = SymbolInfo->SizeOfImage;
    if ( PathName )
    {
      v6 = KdpMoveMemory(KdpPathBuffer, PathName->Buffer, PathName->Length, 1) + 1;
      WaitStateChange.u.Exception.ExceptionRecord.ExceptionCode = v6;
      MessageData.Length = v6;
      MessageData.Buffer = KdpPathBuffer;
      *((_BYTE *)&KdpInternalBPs[19].ReturnAddress + (unsigned __int16)v6 + 7) = 0;
      v5 = &MessageData;
    }
    else
    {
      WaitStateChange.u.Exception.ExceptionRecord.ExceptionCode = 0;
    }
    MessageHeader.Length = 952;
    MessageHeader.Buffer = (char *)&WaitStateChange;
    LOBYTE(v7) = KdpSendWaitContinue((int)SymbolInfo, 7u, &MessageHeader, v5, ContextRecord);
  }
  while ( v7 == 2 );
  return v7;
}