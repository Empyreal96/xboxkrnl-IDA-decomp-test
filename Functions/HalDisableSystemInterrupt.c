unsigned __int8 __stdcall HalDisableSystemInterrupt(char a1)
{
  unsigned __int8 v1; // al
  int v2; // eax
  int v3; // eax
  unsigned __int8 result; // al

  _disable();
  HalpIDR |= 1 << a1;
  v1 = __inbyte(0xA1u);
  v2 = v1 << 8;
  LOBYTE(v2) = __inbyte(0x21u);
  v3 = (1 << a1) | v2;
  __outbyte(0x21u, v3);
  __outbyte(0xA1u, BYTE1(v3));
  result = __inbyte(0xA1u);
  _enable();
  return result;
}