void __stdcall HalpInitializeRealTimeClock()
{
  unsigned __int8 v0; // al
  unsigned __int8 v1; // al
  unsigned __int8 v2; // al

  HalpAcquireCmosSpinLock();
  __outbyte(0x70u, 0xAu);
  __outbyte(0x71u, 0x2Du);
  __outbyte(0x70u, 0xBu);
  v0 = __inbyte(0x71u);
  __outbyte(0x70u, 0xBu);
  __outbyte(0x71u, v0 & 1 | 2);
  __outbyte(0x70u, 0xCu);
  v1 = __inbyte(0x71u);
  __outbyte(0x70u, 0xDu);
  v2 = __inbyte(0x71u);
  HalpReleaseCmosSpinLock();
}