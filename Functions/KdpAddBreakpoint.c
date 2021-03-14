unsigned int __stdcall KdpAddBreakpoint(void *Address)
{
  void *v1; // edi
  unsigned int v2; // ecx
  unsigned int v3; // esi
  unsigned int result; // eax
  _BYTE *v5; // edx
  void *v6; // eax
  char v7; // cl
  void *AccessAddress; // [esp+8h] [ebp-8h]
  _HARDWARE_PTE Opaque; // [esp+Ch] [ebp-4h]

  v1 = Address;
  v2 = 0;
  do
  {
    if ( *(_BYTE *)(8 * v2 - 2147105872) & 1 && *(void **)(8 * v2 - 2147105868) == Address )
    {
      v5 = (_BYTE *)(8 * v2 - 2147105872);
      if ( *v5 & 8 )
      {
        *v5 &= 0xF7u;
        result = v2 + 1;
      }
      else
      {
        KdpDprintf((int *)Address, "KD: Attempt to set breakpoint %08x twice!\n", Address);
        result = 0;
      }
      return result;
    }
    ++v2;
  }
  while ( v2 < 0x20 );
  v3 = 0;
  do
  {
    if ( !*(_BYTE *)(8 * v3 - 2147105872) )
      break;
    ++v3;
  }
  while ( v3 < 0x20 );
  if ( v3 == 32 )
  {
    KdpDprintf((int *)Address, "KD: ran out of breakpoints!\n");
    return 0;
  }
  if ( KdpMoveMemory((char *)&Address + 3, Address, 1u, 1) == 1 )
  {
    v6 = MmDbgWriteCheck(v1, &Opaque);
    AccessAddress = v6;
    if ( !v6 )
    {
      KdpDprintf((int *)v1, "KD: memory not writable!\n");
      return 0;
    }
    v7 = HIBYTE(Address);
    *(_DWORD *)(8 * v3 - 2147105868) = v1;
    *(_BYTE *)(8 * v3 - 2147105871) = v7;
    *(_BYTE *)(8 * v3 - 2147105872) = 1;
    if ( KdpMoveMemory(v6, &KdpBreakpointInstruction, 1u, 0) != 1 )
      KdpDprintf((int *)v1, "KD: KdpMoveMemory failed writing BP!\n");
    MmDbgReleaseAddress((int *)v1, AccessAddress, &Opaque);
  }
  else
  {
    *(_DWORD *)(8 * v3 - 2147105868) = v1;
    *(_BYTE *)(8 * v3 - 2147105872) = 3;
    KdpOweBreakpoint = 1;
  }
  return v3 + 1;
}