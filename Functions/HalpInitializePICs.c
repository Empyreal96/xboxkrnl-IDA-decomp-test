unsigned __int16 __stdcall HalpInitializePICs()
{
  unsigned int v0; // et0
  unsigned __int16 result; // ax
  unsigned int v3; // [esp+0h] [ebp-8h]

  v0 = __readeflags();
  v3 = v0;
  _disable();
  result = PICsInitializationString;
  _ESI = &PICsInitializationString + 1;
  do
  {
    __asm
    {
      outsb
      outsb
      outsb
      outsb
    }
    __outbyte(result + 1, 0xFFu);
    result = *_ESI;
    ++_ESI;
  }
  while ( result );
  __writeeflags(v3 | 0x200);
  return result;
}