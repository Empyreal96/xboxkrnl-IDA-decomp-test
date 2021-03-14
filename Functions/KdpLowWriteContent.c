char __stdcall KdpLowWriteContent(unsigned int Index)
{
  unsigned int v1; // esi
  char v2; // al

  v1 = 8 * Index;
  v2 = KdpBreakpointTable[Index].Flags;
  if ( v2 & 2 )
  {
    KdpBreakpointTable[v1 / 8].Flags = v2 & 0xFD;
    return 1;
  }
  if ( byte_8005C3B1[v1] == KdpBreakpointInstruction
    || KdpMoveMemory((void *)dword_8005C3B4[v1 / 4], &byte_8005C3B1[v1], 1u, 0) == 1 )
  {
    return 1;
  }
  KdpBreakpointTable[v1 / 8].Flags |= 8u;
  KdpOweBreakpoint = 1;
  return 0;
}