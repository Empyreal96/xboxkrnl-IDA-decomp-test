char __stdcall HalSetRealTimeClock(int a1)
{
  int v1; // ecx
  signed int v3; // ecx
  char v4; // al
  __int16 v11; // t2
  int v12; // ST00_4
  int v17; // [esp-4h] [ebp-4h]

_HalSetRealTimeClock@4:
  v1 = 100;
kwctwait:
  v17 = v1;
  HalpAcquireCmosSpinLock();
  v3 = 100;
  while ( 1 )
  {
    __outbyte(0x70u, 0xAu);
    v4 = __inbyte(0x71u);
    if ( v4 >= 0 )
      break;
    if ( !--v3 )
    {
      HalpReleaseCmosSpinLock();
      v1 = v17 - 1;
      if ( v17 != 1 )
        goto kwctwait;
      DbgBreakPoint();
      goto _HalSetRealTimeClock@4;
    }
  }
  LOBYTE(_EAX) = *(_BYTE *)(a1 + 10);
  __asm { aam }
  LOBYTE(_EAX) = __ROL1__(_EAX, 4);
  BYTE1(_EAX) = __ROR2__(_EAX, 4);
  __outbyte(0x70u, 0);
  __outbyte(0x71u, BYTE1(_EAX));
  LOBYTE(_EAX) = *(_BYTE *)(a1 + 8);
  __asm { aam }
  LOBYTE(_EAX) = __ROL1__(_EAX, 4);
  BYTE1(_EAX) = __ROR2__(_EAX, 4);
  __outbyte(0x70u, 2u);
  __outbyte(0x71u, BYTE1(_EAX));
  LOBYTE(_EAX) = *(_BYTE *)(a1 + 6);
  __asm { aam }
  LOBYTE(_EAX) = __ROL1__(_EAX, 4);
  BYTE1(_EAX) = __ROR2__(_EAX, 4);
  __outbyte(0x70u, 4u);
  __outbyte(0x71u, BYTE1(_EAX));
  LOBYTE(_EAX) = *(_BYTE *)(a1 + 14);
  __asm { aam }
  LOBYTE(_EAX) = __ROL1__(_EAX, 4);
  BYTE1(_EAX) = __ROR2__(_EAX, 4);
  __outbyte(0x70u, 6u);
  __outbyte(0x71u, BYTE1(_EAX));
  LOBYTE(_EAX) = *(_BYTE *)(a1 + 4);
  __asm { aam }
  LOBYTE(_EAX) = __ROL1__(_EAX, 4);
  BYTE1(_EAX) = __ROR2__(_EAX, 4);
  __outbyte(0x70u, 7u);
  __outbyte(0x71u, BYTE1(_EAX));
  LOBYTE(_EAX) = *(_BYTE *)(a1 + 2);
  __asm { aam }
  LOBYTE(_EAX) = __ROL1__(_EAX, 4);
  __outbyte(0x70u, 8u);
  __outbyte(0x71u, __ROR2__(_EAX, 4));
  LOWORD(_EAX) = *(_WORD *)a1;
  if ( *(_WORD *)a1 > 0x270Fu )
    LOWORD(_EAX) = 9999;
  v11 = (unsigned __int16)_EAX % 0x64u;
  LOBYTE(_EAX) = (unsigned __int16)_EAX / 0x64u;
  BYTE1(_EAX) = v11;
  v12 = _EAX;
  __asm { aam }
  LOBYTE(_EAX) = __ROL1__(_EAX, 4);
  __outbyte(0x70u, 0x7Fu);
  __outbyte(0x71u, __ROR2__(_EAX, 4));
  _EAX = v12;
  LOBYTE(_EAX) = BYTE1(_EAX);
  __asm { aam }
  LOBYTE(_EAX) = __ROL1__(_EAX, 4);
  __outbyte(0x70u, 9u);
  __outbyte(0x71u, __ROR2__(_EAX, 4));
  HalpReleaseCmosSpinLock();
  return 1;
}