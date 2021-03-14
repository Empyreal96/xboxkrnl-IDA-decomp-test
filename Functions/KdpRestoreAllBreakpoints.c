char __stdcall KdpRestoreAllBreakpoints()
{
  unsigned int v0; // esi
  char *v1; // ecx
  char result; // al

  BreakpointsSuspended = 0;
  v0 = 0;
  do
  {
    v1 = (char *)(8 * v0 - 2147105872);
    result = *v1;
    if ( *v1 & 1 )
    {
      if ( result & 4 )
      {
        *v1 = result & 0xFB;
        result = KdpLowRestoreBreakpoint(v0);
      }
    }
    ++v0;
  }
  while ( v0 < 0x20 );
  return result;
}