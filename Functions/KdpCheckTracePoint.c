char __stdcall KdpCheckTracePoint(_EXCEPTION_RECORD *ExceptionRecord, _CONTEXT *ContextRecord)
{
  int v2; // eax
  bool v3; // zf
  _CONTEXT *v4; // esi
  void *v5; // ecx
  unsigned int v6; // eax
  int v7; // ebx
  unsigned int v8; // eax
  signed int v9; // ebx
  unsigned int v10; // ecx
  DBGKD_INTERNAL_BREAKPOINT *v11; // eax
  int v12; // edi
  _CONTEXT *v13; // eax
  int v14; // eax
  _CONTEXT *v15; // eax
  unsigned int v16; // ebx
  int v17; // edi
  int v18; // eax
  int v20; // eax
  int BpNum; // [esp+Ch] [ebp-8h]
  unsigned int pc; // [esp+10h] [ebp-4h]

  v2 = ExceptionRecord->ExceptionCode;
  v3 = ExceptionRecord->ExceptionCode == -2147483644;
  v4 = ContextRecord;
  v5 = (void *)ContextRecord->Eip;
  pc = ContextRecord->Eip;
  HIBYTE(ContextRecord) = 0;
  if ( v3 )
  {
    if ( WatchStepOverSuspended )
    {
      v6 = KdpAddBreakpoint(WatchStepOverBreakAddr);
      WatchStepOverSuspended = 0;
LABEL_4:
      WatchStepOverHandle = v6;
LABEL_5:
      BYTE1(v4->EFlags) &= 0xFEu;
      return 1;
    }
    if ( !SymbolRecorded && KdpCurrentSymbolStart && KdpCurrentSymbolEnd )
    {
      PotentialNewSymbol(oldpc);
      SymbolRecorded = 1;
    }
    if ( !InstrCountInternal && SkippingWhichBP(thread, (unsigned int *)&BpNum) )
    {
      v7 = BpNum;
      if ( KdpInternalBPs[BpNum].Flags & 1 )
      {
        --IntBPsSkipping;
        KdpRestoreAllBreakpoints();
        BYTE1(v4->EFlags) &= 0xFEu;
        KdpInternalBPs[v7].Thread = 0;
        if ( KdpInternalBPs[v7].Flags & 8 )
        {
          KdpDeleteBreakpoint((int *)0x100, KdpInternalBPs[v7].Handle);
          KdpInternalBPs[v7].Flags |= 2u;
        }
        return 1;
      }
      v8 = KdpInternalBPs[v7].ReturnAddress;
      KdpCurrentSymbolEnd = 0;
      KdpCurrentSymbolStart = v8;
      v4->EFlags |= 0x100u;
      v9 = 1;
      InitialSP = v4->Esp;
      InstructionsTraced = 1;
      InstrCountInternal = 1;
LABEL_34:
      if ( ExceptionRecord->ExceptionCode != -2147483644 )
        goto LABEL_65;
      goto LABEL_35;
    }
LABEL_33:
    v9 = InstructionsTraced;
    goto LABEL_34;
  }
  if ( v2 != -2147483645 )
    goto LABEL_33;
  if ( !WatchStepOver || v5 != WatchStepOverBreakAddr )
  {
    BpNum = 0;
    if ( (signed int)KdpNumInternalBreakpoints > 0 )
    {
      v11 = KdpInternalBPs;
      do
      {
        if ( !(v11->Flags & 6) && LODWORD(v11->Addr) == pc && !HIDWORD(v11->Addr) )
          break;
        ++BpNum;
        ++v11;
      }
      while ( BpNum < (signed int)KdpNumInternalBreakpoints );
      if ( BpNum < (signed int)KdpNumInternalBreakpoints )
      {
        KdpProcessInternalBreakpoint(BpNum);
        v12 = BpNum;
        ++IntBPsSkipping;
        KdpInternalBPs[BpNum].Thread = thread;
        KdpSuspendAllBreakpoints();
        BYTE1(v4->EFlags) |= 1u;
        if ( !(KdpInternalBPs[v12].Flags & 1) )
        {
          v13 = KdpGetReturnAddress(v4);
          HIDWORD(KdpInternalBPs[v12].ReturnAddress) = 0;
          LODWORD(KdpInternalBPs[v12].ReturnAddress) = v13;
        }
        return 1;
      }
    }
    goto LABEL_33;
  }
  if ( WSOThread != thread || (v10 = v4->Esp, WSOEsp + 32 < v10) || v10 + 32 < WSOEsp )
  {
    WatchStepOverSuspended = 1;
    KdpDeleteBreakpoint((int *)0x100, WatchStepOverHandle);
    BYTE1(v4->EFlags) |= 1u;
    return 1;
  }
  WatchStepOver = 0;
  KdpDeleteBreakpoint((int *)0x100, WatchStepOverHandle);
  v4->EFlags |= 0x100u;
  v9 = InstructionsTraced;
  HIBYTE(ContextRecord) = 1;
LABEL_35:
  if ( KdpCurrentSymbolStart
    && (!KdpCurrentSymbolEnd && v4->Esp <= InitialSP || KdpCurrentSymbolStart <= pc && pc < KdpCurrentSymbolEnd) )
  {
    v14 = KdpLevelChange(pc, v4, (char *)&ExceptionRecord + 3);
    ++InstructionsTraced;
    CallLevelChange += v14;
    if ( HIBYTE(ExceptionRecord) )
    {
      if ( v14 != -1 )
        CallLevelChange -= v14;
      WatchStepOver = 1;
      v15 = KdpGetCallNextOffset(pc, v4);
      WatchStepOverBreakAddr = v15;
      WSOThread = thread;
      WSOEsp = v4->Esp;
LABEL_59:
      v6 = KdpAddBreakpoint(v15);
      goto LABEL_4;
    }
    goto LABEL_60;
  }
  if ( (HIBYTE(ContextRecord) || ExceptionRecord->ExceptionCode == -2147483644) && KdpCurrentSymbolStart )
  {
    v16 = v9 + 1;
    InstructionsTraced = v16;
    if ( InstrCountInternal )
    {
      SkippingWhichBP(thread, (unsigned int *)&BpNum);
      v17 = BpNum;
      ++KdpInternalBPs[v17].Calls;
      if ( KdpInternalBPs[v17].MinInstructions > v16 )
        KdpInternalBPs[v17].MinInstructions = v16;
      if ( KdpInternalBPs[v17].MaxInstructions < v16 )
        KdpInternalBPs[v17].MaxInstructions = v16;
      KdpInternalBPs[v17].TotalInstructions += v16;
      KdpInternalBPs[v17].Thread = 0;
      --IntBPsSkipping;
      KdpCurrentSymbolStart = 0;
      InstrCountInternal = 0;
      KdpRestoreAllBreakpoints();
      if ( KdpInternalBPs[v17].Flags & 8 )
      {
        KdpDeleteBreakpoint((int *)(v17 * 56), KdpInternalBPs[v17].Handle);
        KdpInternalBPs[v17].Flags |= 2u;
      }
      goto LABEL_5;
    }
    if ( TraceDataRecordCallInfo(v16, CallLevelChange, pc) )
    {
      v18 = KdpLevelChange(pc, v4, (char *)&ExceptionRecord + 3);
      InstructionsTraced = 0;
      CallLevelChange = v18;
      if ( HIBYTE(ExceptionRecord) )
      {
        if ( v18 != -1 )
          CallLevelChange = 0;
        WatchStepOver = 1;
        WSOThread = thread;
        v15 = KdpGetCallNextOffset(pc, v4);
        goto LABEL_59;
      }
LABEL_60:
      v4->EFlags |= 0x100u;
      return 1;
    }
    v20 = KdpLevelChange(pc, v4, (char *)&ExceptionRecord + 3);
    InstructionsTraced = 0;
    CallLevelChange = v20;
    if ( v20 && HIBYTE(ExceptionRecord) )
      KdpDprintf((int *)0x100, "Special call on first entry to symbol scope @ %x\n", pc);
  }
LABEL_65:
  oldpc = pc;
  SymbolRecorded = 0;
  return 0;
}