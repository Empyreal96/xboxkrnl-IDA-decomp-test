void __stdcall KdpSetLoadState(_DBGKD_WAIT_STATE_CHANGE64_X86_NT5 *WaitStateChange, _X86_NT5_CONTEXT *ContextRecord)
{
  void *v2; // ST04_4
  int *v3; // edi
  int v4; // eax
  void *v5; // ST08_4

  v2 = (void *)WaitStateChange->ProgramCounter;
  WaitStateChange->ControlReport.Dr6 = KdProcessorState.SpecialRegisters.KernelDr6;
  WaitStateChange->ControlReport.Dr7 = KdProcessorState.SpecialRegisters.KernelDr7;
  v3 = (int *)KdpMoveMemory(WaitStateChange->ControlReport.InstructionStream, v2, 0x10u, 1);
  v4 = WaitStateChange->ProgramCounter;
  v5 = (void *)WaitStateChange->ProgramCounter;
  WaitStateChange->ControlReport.InstructionCount = (unsigned __int16)v3;
  if ( KdpDeleteBreakpointRange(v3, v5, (char *)v3 + v4 - 1) )
    KdpMoveMemory(
      WaitStateChange->ControlReport.InstructionStream,
      (void *)WaitStateChange->ProgramCounter,
      (unsigned int)v3,
      1);
  WaitStateChange->ControlReport.SegCs = ContextRecord->SegCs;
  WaitStateChange->ControlReport.SegDs = 16;
  WaitStateChange->ControlReport.SegEs = 16;
  WaitStateChange->ControlReport.SegFs = 32;
  WaitStateChange->ControlReport.EFlags = ContextRecord->EFlags;
  WaitStateChange->ControlReport.ReportFlags = 1;
  KdpMoveMemory(&WaitStateChange->Context, ContextRecord, 0x2CCu, 1);
}