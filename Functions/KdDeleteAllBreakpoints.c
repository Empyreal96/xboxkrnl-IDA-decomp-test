char __usercall KdDeleteAllBreakpoints@<al>(int *a1@<edi>)
{
  unsigned int v1; // esi
  char result; // al

  if ( KdDebuggerEnabled )
  {
    BreakpointsSuspended = 0;
    v1 = 1;
    do
      result = KdpDeleteBreakpoint(a1, v1++);
    while ( v1 <= 0x20 );
  }
  return result;
}