unsigned int __stdcall KdpSearchPhysicalPage(unsigned int PageFrameIndex, unsigned int RangeStart, unsigned int RangeEnd, unsigned int Flags)
{
  unsigned int v4; // eax
  unsigned int v5; // esi
  unsigned int *v6; // ebx
  unsigned int v7; // edi
  unsigned int v8; // eax

  v4 = MmDbgTranslatePhysicalAddress64((_LARGE_INTEGER)((unsigned __int64)PageFrameIndex << 12));
  v5 = KdpSearchPageHitIndex;
  v6 = (unsigned int *)v4;
  v7 = 0;
  while ( 1 )
  {
    if ( (v8 = *v6, *v6 >= RangeStart) && v8 <= RangeEnd || KdpSearchHammingDistance(v8, RangeStart) == 1 )
    {
      if ( v5 < 0x1000 )
      {
        *(_DWORD *)(4 * v5 - 2147134024) = PageFrameIndex;
        *(_DWORD *)(4 * v5++ - 2147150408) = v7;
        KdpSearchPageHitIndex = v5;
      }
      if ( !(Flags & 1) )
        break;
    }
    ++v7;
    v6 = (unsigned int *)((char *)v6 + 1);
    if ( v7 >= 0xFFC )
      return 0;
  }
  return 1;
}