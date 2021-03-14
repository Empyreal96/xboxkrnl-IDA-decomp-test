unsigned int __stdcall HalEnableSystemInterrupt(unsigned __int8 a1, char a2)
{
  unsigned int result; // eax

  _bittestandreset(&HalpEisaELCR, a1);
  if ( !a2 )
  {
    _bittestandset(&HalpEisaELCR, a1);
    *(_DWORD *)(4 * a1 - 2147173488) = *(_DWORD *)(4 * a1 - 2147364512);
  }
  __outbyte(0x4D0u, HalpEisaELCR);
  __outbyte(0x4D1u, BYTE1(HalpEisaELCR));
  _disable();
  HalpIDR &= ~(1 << a1);
  __outbyte(0x21u, HalpIDR | KiI8259MaskTable);
  result = (HalpIDR | KiI8259MaskTable) >> 8;
  __outbyte(0xA1u, result);
  _enable();
  return result;
}