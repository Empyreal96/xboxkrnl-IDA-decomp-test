void __stdcall KdpGetStateChange(_DBGKD_MANIPULATE_STATE64 *ManipulateState, _X86_NT5_CONTEXT *ContextRecord)
{
  unsigned int v2; // ecx

  if ( (ManipulateState->u.GetContext.Unused & 0x80000000) == 0 )
  {
    if ( ManipulateState->u.Continue2.ControlSet.TraceFlag == 1 )
      BYTE1(ContextRecord->EFlags) |= 1u;
    else
      BYTE1(ContextRecord->EFlags) &= 0xFEu;
    v2 = ManipulateState->u.ReadMemory.TransferCount;
    KdProcessorState.SpecialRegisters.KernelDr6 = 0;
    KdProcessorState.SpecialRegisters.KernelDr7 = v2;
    if ( ManipulateState->u.ReadMemory.ActualBytesRead != 1 )
    {
      KdpCurrentSymbolStart = ManipulateState->u.ReadMemory.ActualBytesRead;
      KdpCurrentSymbolEnd = ManipulateState->u.Continue2.ControlSet.CurrentSymbolEnd;
    }
  }
}