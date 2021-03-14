void __stdcall KdpSuspendBreakpoint(unsigned int Handle)
{
  char *v1; // ecx
  char v2; // al

  v1 = (char *)(8 * (Handle - 1) - 2147105872);
  v2 = *v1;
  if ( *v1 & 1 )
  {
    if ( !(v2 & 4) )
    {
      *v1 = v2 | 4;
      KdpLowWriteContent(Handle - 1);
    }
  }
}