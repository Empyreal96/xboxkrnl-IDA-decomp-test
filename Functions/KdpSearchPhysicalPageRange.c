unsigned int __stdcall KdpSearchPhysicalPageRange()
{
  unsigned int v0; // edi
  unsigned int i; // esi

  v0 = 0;
  if ( !KdpSearchInProgress )
    return 0;
  if ( KdpSearchEndPageFrame == KdpSearchStartPageFrame )
  {
    ++KdpSearchEndPageFrame;
    v0 = 1;
  }
  for ( i = KdpSearchStartPageFrame; i < KdpSearchEndPageFrame; ++i )
    KdpSearchPhysicalPage(i, KdpSearchAddressRangeStart, KdpSearchAddressRangeEnd, v0);
  return 1;
}