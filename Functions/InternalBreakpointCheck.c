void __fastcall InternalBreakpointCheck(int a1, int a2, _KDPC *Dpc, void *DeferredContext, void *SystemArgument1, void *SystemArgument2)
{
  unsigned int *v6; // eax
  unsigned int v7; // esi
  int v8; // ecx
  unsigned int v9; // edx
  unsigned int v10; // ecx

  KeSetTimer(-1, a2, &InternalBreakpointTimer, (_LARGE_INTEGER)-10000000i64, &InternalBreakpointCheckDpc);
  if ( KdpNumInternalBreakpoints )
  {
    v6 = &KdpInternalBPs[0].Calls;
    v7 = KdpNumInternalBreakpoints;
    do
    {
      v8 = *(v6 - 1);
      if ( !(v8 & 2) && v8 & 1 )
      {
        v9 = *v6;
        v10 = *v6 - v6[1];
        if ( v10 > v6[2] )
          v6[2] = v10;
        v6[1] = v9;
      }
      v6 += 14;
      --v7;
    }
    while ( v7 );
  }
}