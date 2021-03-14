char __stdcall HalQueryRealTimeClock(unsigned __int16 *a1)
{
  int v1; // ecx
  signed int v2; // ecx
  char v3; // al
  unsigned __int8 v5; // al
  __int16 v13; // ST00_2
  unsigned __int16 v15; // ax
  int v17; // [esp-4h] [ebp-4h]

_HalQueryRealTimeClock@4:
  v1 = 100;
krctwait:
  v17 = v1;
  HalpAcquireCmosSpinLock();
  v2 = 100;
  while ( 1 )
  {
    __outbyte(0x70u, 0xAu);
    v3 = __inbyte(0x71u);
    if ( v3 >= 0 )
      break;
    if ( !--v2 )
    {
      HalpReleaseCmosSpinLock();
      v1 = v17 - 1;
      if ( v17 != 1 )
        goto krctwait;
      DbgBreakPoint();
      goto _HalQueryRealTimeClock@4;
    }
  }
  HIWORD(_EAX) = 0;
  a1[6] = 500;
  __outbyte(0x70u, 0);
  v5 = __inbyte(0x71u);
  LOWORD(_EAX) = __ROL2__(v5, 4);
  LOBYTE(_EAX) = __ROR1__(_EAX, 4);
  __asm { aad }
  a1[5] = _EAX;
  __outbyte(0x70u, 2u);
  LOBYTE(_EAX) = __inbyte(0x71u);
  LOWORD(_EAX) = __ROL2__((unsigned __int8)_EAX, 4);
  LOBYTE(_EAX) = __ROR1__(_EAX, 4);
  __asm { aad }
  a1[4] = _EAX;
  __outbyte(0x70u, 4u);
  LOBYTE(_EAX) = __inbyte(0x71u);
  LOWORD(_EAX) = __ROL2__((unsigned __int8)_EAX, 4);
  LOBYTE(_EAX) = __ROR1__(_EAX, 4);
  __asm { aad }
  a1[3] = _EAX;
  __outbyte(0x70u, 6u);
  LOBYTE(_EAX) = __inbyte(0x71u);
  LOWORD(_EAX) = __ROL2__((unsigned __int8)_EAX, 4);
  LOBYTE(_EAX) = __ROR1__(_EAX, 4);
  __asm { aad }
  a1[7] = _EAX;
  __outbyte(0x70u, 7u);
  LOBYTE(_EAX) = __inbyte(0x71u);
  LOWORD(_EAX) = __ROL2__((unsigned __int8)_EAX, 4);
  LOBYTE(_EAX) = __ROR1__(_EAX, 4);
  __asm { aad }
  a1[2] = _EAX;
  __outbyte(0x70u, 8u);
  LOBYTE(_EAX) = __inbyte(0x71u);
  LOWORD(_EAX) = __ROL2__((unsigned __int8)_EAX, 4);
  LOBYTE(_EAX) = __ROR1__(_EAX, 4);
  __asm { aad }
  a1[1] = _EAX;
  __outbyte(0x70u, 9u);
  LOBYTE(_EAX) = __inbyte(0x71u);
  LOWORD(_EAX) = __ROL2__((unsigned __int8)_EAX, 4);
  LOBYTE(_EAX) = __ROR1__(_EAX, 4);
  __asm { aad }
  v13 = _EAX;
  __outbyte(0x70u, 0x7Fu);
  LOBYTE(_EAX) = __inbyte(0x71u);
  LOWORD(_EAX) = __ROL2__((unsigned __int8)_EAX, 4);
  LOBYTE(_EAX) = __ROR1__(_EAX, 4);
  __asm { aad }
  v15 = v13 + 100 * (unsigned __int8)_EAX;
  if ( v15 >= 0x76Cu && v15 < 0x780u )
    v15 += 100;
  *a1 = v15;
  HalpReleaseCmosSpinLock();
  return 1;
}