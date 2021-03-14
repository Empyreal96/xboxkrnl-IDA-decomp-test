void __userpurge KdSetInternalBreakpoint(int *a1@<edi>, _DBGKD_MANIPULATE_STATE64 *m)
{
  _DBGKD_MANIPULATE_STATE64 *v2; // ecx
  int v3; // esi
  DBGKD_INTERNAL_BREAKPOINT *v4; // esi
  unsigned int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // eax
  char v8; // dl
  unsigned int v9; // eax
  int **ma; // [esp+10h] [ebp+8h]

  v2 = m;
  v3 = 0;
  if ( !KdpNumInternalBreakpoints )
    goto LABEL_8;
  ma = (int **)KdpInternalBPs;
  while ( 1 )
  {
    a1 = *ma;
    if ( *ma == (int *)v2->u.GetContext.Unused )
    {
      a1 = ma[1];
      if ( a1 == (int *)v2->u.Continue2.ControlSet.TraceFlag )
        break;
    }
    ma += 14;
    if ( ++v3 >= KdpNumInternalBreakpoints )
      goto LABEL_8;
  }
  v4 = &KdpInternalBPs[v3];
  if ( !v4 )
  {
LABEL_8:
    v5 = 0;
    if ( !KdpNumInternalBreakpoints )
      goto LABEL_14;
    a1 = (int *)&KdpInternalBPs[0].Flags;
    while ( !(*(_BYTE *)a1 & 2) )
    {
      ++v5;
      a1 += 14;
      if ( v5 >= KdpNumInternalBreakpoints )
        goto LABEL_14;
    }
    v4 = &KdpInternalBPs[v5];
    if ( !v4 )
    {
LABEL_14:
      if ( KdpNumInternalBreakpoints >= 0x14 )
        return;
      v4 = &KdpInternalBPs[KdpNumInternalBreakpoints];
      v6 = KdpNumInternalBreakpoints + 1;
      v4->Flags |= 2u;
      KdpNumInternalBreakpoints = v6;
    }
  }
  v7 = v4->Flags;
  if ( v7 & 2 )
  {
    if ( v2->u.Continue2.ControlSet.Dr7 & 2 )
      return;
    v4->TotalInstructions = 0;
    v4->MaxInstructions = 0;
    v4->Calls = 0;
    v4->MaxCallsPerPeriod = 0;
    v4->CallsLastCheck = 0;
    v4->MinInstructions = -1;
    v4->Handle = 0;
    v4->Thread = 0;
  }
  v8 = v7;
  v4->Flags = v2->u.ReadMemory.TransferCount;
  LODWORD(v4->Addr) = v2->u.GetContext.Unused;
  HIDWORD(v4->Addr) = v2->u.Continue2.ControlSet.TraceFlag;
  v9 = v4->Flags;
  if ( v9 & 6 )
  {
    if ( v9 & 2 && v4->Thread )
      v4->Flags = v9 & 0xFFFFFFFD | 8;
    if ( v4->Handle )
      KdpDeleteBreakpoint(a1, v4->Handle);
    v4->Handle = 0;
  }
  else
  {
    if ( v8 & 6 )
      v4->Handle = KdpAddBreakpoint((void *)v4->Addr);
    if ( BreakpointsSuspended )
      KdpSuspendBreakpoint(v4->Handle);
  }
}