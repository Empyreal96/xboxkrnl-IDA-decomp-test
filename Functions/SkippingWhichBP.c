char __stdcall SkippingWhichBP(void *thread, unsigned int *BPNum)
{
  unsigned int v2; // edx
  void **v4; // ecx

  v2 = 0;
  if ( !IntBPsSkipping )
    return 0;
  if ( KdpNumInternalBreakpoints <= 0 )
    return 0;
  v4 = &KdpInternalBPs[0].Thread;
  while ( *(_BYTE *)(v4 - 8) & 2 || *v4 != thread )
  {
    ++v2;
    v4 += 14;
    if ( v2 >= KdpNumInternalBreakpoints )
      return 0;
  }
  *BPNum = v2;
  return 1;
}