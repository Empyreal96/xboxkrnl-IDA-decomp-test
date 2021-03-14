void __stdcall KdSetOwedBreakpoints()
{
  char v0; // al
  void **v1; // esi
  int *v2; // eax
  int *v3; // edi
  int v4; // eax
  void *v5; // [esp-Ch] [ebp-1Ch]
  char Enable; // [esp+4h] [ebp-Ch]
  _HARDWARE_PTE Opaque; // [esp+8h] [ebp-8h]
  char Content; // [esp+Fh] [ebp-1h]

  if ( !KdpOweBreakpoint )
    return;
  v0 = KdEnterDebugger(0, 0);
  KdpOweBreakpoint = 0;
  Enable = v0;
  v1 = (void **)dword_8005C3B4;
  while ( !(*(_BYTE *)(v1 - 1) & 0xA) )
  {
LABEL_16:
    v1 += 2;
    if ( (signed int)v1 >= (signed int)&unk_8005C4B4 )
      goto LABEL_19;
  }
  v2 = (int *)MmDbgWriteCheck(*v1, &Opaque);
  v3 = v2;
  if ( v2 )
  {
    if ( KdpMoveMemory(&Content, v2, 1u, 1) != 1 )
    {
      KdpDprintf(v3, "KD: read from 0x%08x failed\n", *v1);
      KdpOweBreakpoint = 1;
LABEL_15:
      MmDbgReleaseAddress(v3, v3, &Opaque);
      goto LABEL_16;
    }
    if ( *(_BYTE *)(v1 - 1) & 2 )
    {
      *((_BYTE *)v1 - 3) = Content;
      v4 = KdpMoveMemory(v3, &KdpBreakpointInstruction, 1u, 0);
      v5 = *v1;
      if ( v4 == 1 )
      {
        *((_BYTE *)v1 - 4) = 1;
        KdpDprintf(v3, "KD: write to 0x%08x ok\n", v5);
        goto LABEL_15;
      }
    }
    else
    {
      if ( KdpMoveMemory(v3, (char *)v1 - 3, 1u, 0) == 1 )
      {
        *((_BYTE *)v1 - 4) = (*(_BYTE *)(v1 - 1) & 4) != 0 ? 5 : 0;
        goto LABEL_15;
      }
      v5 = *v1;
    }
    KdpOweBreakpoint = 1;
    KdpDprintf(v3, "KD: write to 0x%08x failed\n", v5);
    goto LABEL_15;
  }
  KdpOweBreakpoint = 1;
LABEL_19:
  KdExitDebugger(Enable);
}