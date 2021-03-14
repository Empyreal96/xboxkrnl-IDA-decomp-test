void __stdcall KdpProcessInternalBreakpoint(unsigned int BreakpointNumber)
{
  int v1; // edx
  int v2; // ecx

  if ( KdpInternalBPs[BreakpointNumber].Flags & 1 )
  {
    if ( !timerStarted )
    {
      KeInitializeDpc(
        &InternalBreakpointCheckDpc,
        (void (__stdcall *)(_KDPC *, void *, void *, void *))InternalBreakpointCheck,
        0);
      KeInitializeTimerEx(&InternalBreakpointTimer, 0);
      KeSetTimer(v2, v1, &InternalBreakpointTimer, (_LARGE_INTEGER)-10000000i64, &InternalBreakpointCheckDpc);
      timerStarted = 1;
    }
    ++KdpInternalBPs[BreakpointNumber].Calls;
  }
}