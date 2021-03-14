char __stdcall IdexCdRomPollResetComplete()
{
  unsigned __int8 v0; // al

  __outbyte(0x1F6u, 0xB0u);
  v0 = __inbyte(0x1F7u);
  IdexCdRomExpectingBusReset = 1;
  return ~(v0 >> 7) & 1;
}