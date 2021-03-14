bool __stdcall IdexDiskPollResetComplete()
{
  unsigned __int8 v0; // al
  bool result; // al

  result = 0;
  if ( IdexCdRomPollResetComplete() )
  {
    __outbyte(0x1F6u, 0xA0u);
    v0 = __inbyte(0x1F7u);
    if ( (v0 & 0x80u) == 0 )
    {
      if ( v0 & 0x40 )
        result = 1;
    }
  }
  return result;
}