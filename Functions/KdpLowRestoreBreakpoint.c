char __stdcall KdpLowRestoreBreakpoint(unsigned int Index)
{
  unsigned int v1; // esi
  char v2; // al

  v1 = 8 * Index;
  v2 = KdpBreakpointTable[Index].Flags;
  if ( v2 & 8 )
  {
    KdpBreakpointTable[v1 / 8].Flags = v2 & 0xF7;
  }
  else if ( byte_8005C3B1[v1] != KdpBreakpointInstruction )
  {
    if ( KdpMoveMemory((void *)dword_8005C3B4[v1 / 4], &KdpBreakpointInstruction, 1u, 0) != 1 )
    {
      KdpBreakpointTable[v1 / 8].Flags |= 2u;
      KdpOweBreakpoint = 1;
      return 0;
    }
    KdpBreakpointTable[v1 / 8].Flags &= 0xFDu;
  }
  return 1;
}