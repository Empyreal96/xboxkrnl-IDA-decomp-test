void __stdcall KdpSetStateChange(_DBGKD_WAIT_STATE_CHANGE64_X86_NT5 *WaitStateChange, _EXCEPTION_RECORD *ExceptionRecord, _X86_NT5_CONTEXT *ContextRecord, char SecondChance)
{
  void *v4; // ST04_4
  unsigned int v5; // eax

  WaitStateChange->Processor = 0;
  WaitStateChange->NewState = 12336;
  WaitStateChange->ProcessorLevel = 6;
  WaitStateChange->NumberProcessors = 1;
  WaitStateChange->Thread = (signed int)thread;
  WaitStateChange->ProgramCounter = (signed int)ContextRecord->Eip;
  ExceptionRecord32To64((_EXCEPTION_RECORD32 *)ExceptionRecord, &WaitStateChange->u.Exception.ExceptionRecord);
  v4 = (void *)WaitStateChange->ProgramCounter;
  WaitStateChange->u.Exception.FirstChance = SecondChance == 0;
  WaitStateChange->ControlReport.InstructionCount = KdpMoveMemory(
                                                      WaitStateChange->ControlReport.InstructionStream,
                                                      v4,
                                                      0x10u,
                                                      1);
  KdpMoveMemory(&WaitStateChange->Context, ContextRecord, 0x2CCu, 1);
  if ( KdpDeleteBreakpointRange(
         (int *)ContextRecord,
         (void *)WaitStateChange->ProgramCounter,
         (void *)(WaitStateChange->ControlReport.InstructionCount + LODWORD(WaitStateChange->ProgramCounter) - 1)) == 1 )
    KdpMoveMemory(
      WaitStateChange->ControlReport.InstructionStream,
      (void *)WaitStateChange->ProgramCounter,
      WaitStateChange->ControlReport.InstructionCount,
      1);
  WaitStateChange->ControlReport.Dr6 = KdProcessorState.SpecialRegisters.KernelDr6;
  WaitStateChange->ControlReport.Dr7 = KdProcessorState.SpecialRegisters.KernelDr7;
  WaitStateChange->ControlReport.SegCs = ContextRecord->SegCs;
  WaitStateChange->ControlReport.SegDs = 16;
  WaitStateChange->ControlReport.SegEs = 16;
  WaitStateChange->ControlReport.SegFs = 32;
  v5 = ContextRecord->EFlags;
  WaitStateChange->ControlReport.ReportFlags = 1;
  WaitStateChange->ControlReport.EFlags = v5;
}