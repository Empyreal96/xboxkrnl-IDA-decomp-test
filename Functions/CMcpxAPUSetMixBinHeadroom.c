int __stdcall CMcpxAPU::SetMixBinHeadroom(unsigned int dwMixBinMask, unsigned int dwHeadroom)
{
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 0x20; ++i )
  {
    if ( (1 << i) & dwMixBinMask )
    {
      while ( MEMORY[0xFE820010] < 4u )
        ;
      *(_DWORD *)(4 * i - 25034240) = dwHeadroom & 7;
    }
  }
  return 0;
}