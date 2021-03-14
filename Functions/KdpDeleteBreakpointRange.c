char __userpurge KdpDeleteBreakpointRange@<al>(int *a1@<edi>, void *Lower, void *Upper)
{
  char v3; // bl
  unsigned int v4; // esi
  unsigned int v5; // eax

  v3 = 0;
  v4 = 0;
  do
  {
    if ( *(_BYTE *)(8 * v4 - 2147105872) & 1 )
    {
      v5 = *(_DWORD *)(8 * v4 - 2147105868);
      if ( v5 >= (unsigned int)Lower && v5 <= (unsigned int)Upper && KdpDeleteBreakpoint(a1, v4 + 1) )
        v3 = 1;
    }
    ++v4;
  }
  while ( v4 < 0x20 );
  return v3;
}