void __stdcall KdpSuspendAllBreakpoints()
{
  unsigned int v0; // esi

  BreakpointsSuspended = 1;
  v0 = 1;
  do
    KdpSuspendBreakpoint(v0++);
  while ( v0 <= 0x20 );
}