void __stdcall HalStopProfileInterrupt(int a1)
{
  unsigned __int8 v1; // al
  unsigned __int8 v2; // al

  HalpAcquireCmosSpinLock();
  __outbyte(0x70u, 0xBu);
  v1 = __inbyte(0x71u);
  __outbyte(0x70u, 0xBu);
  __outbyte(0x71u, v1 & 1 | 2);
  __outbyte(0x70u, 0xCu);
  v2 = __inbyte(0x71u);
  HalpProfilingStopped = 1;
  HalpReleaseCmosSpinLock();
}