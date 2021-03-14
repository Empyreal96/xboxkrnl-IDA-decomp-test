unsigned __int16 __stdcall HalpInitializeSystemControlInterrupt()
{
  unsigned __int16 v0; // ax
  unsigned __int16 v1; // ax
  unsigned __int16 v2; // ax
  unsigned __int16 v3; // ax
  unsigned __int16 result; // ax

  v0 = __inword(0x8004u);
  __outword(0x8004u, v0 | 1);
  v1 = __inword(0x8022u);
  __outword(0x8022u, v1 | 2);
  v2 = __inword(0x8002u);
  __outword(0x8002u, v2 | 1);
  v3 = __inword(0x8028u);
  result = v3 | 1;
  __outword(0x8028u, result);
  return result;
}