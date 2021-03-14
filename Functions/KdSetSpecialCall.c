void __stdcall KdSetSpecialCall(_DBGKD_MANIPULATE_STATE64 *m, _X86_NT5_CONTEXT *ContextRecord)
{
  unsigned int v2; // eax

  v2 = KdNumberOfSpecialCalls;
  if ( KdNumberOfSpecialCalls < 0xA )
  {
    *(_DWORD *)(4 * KdNumberOfSpecialCalls - 2147115272) = m->u.GetContext.Unused;
    KdNumberOfSpecialCalls = v2 + 1;
    NextTraceDataSym = 0;
    NumTraceDataSyms = 0;
    KdpNextCallLevelChange = 0;
    if ( ContextRecord )
    {
      if ( !InstrCountInternal )
        InitialSP = ContextRecord->Esp;
    }
  }
}