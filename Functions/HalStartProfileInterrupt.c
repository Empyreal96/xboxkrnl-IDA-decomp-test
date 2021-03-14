void __stdcall HalStartProfileInterrupt(int a1)
{
  unsigned __int8 v1; // al
  unsigned __int8 v2; // al
  unsigned __int8 v3; // al

  HalpProfilingStopped = 0;
  HalpAcquireCmosSpinLock();
  __outbyte(0x70u, 0xAu);
  __outbyte(0x71u, RegisterAProfileValue);
  __outbyte(0x70u, 0xBu);
  v1 = __inbyte(0x71u);
  __outbyte(0x70u, 0xBu);
  __outbyte(0x71u, v1 & 1 | 0x42);
  __outbyte(0x70u, 0xCu);
  v2 = __inbyte(0x71u);
  __outbyte(0x70u, 0xDu);
  v3 = __inbyte(0x71u);
  HalpReleaseCmosSpinLock();
}