int __fastcall HalRequestSoftwareInterrupt(char a1)
{
  unsigned int v1; // et0
  int result; // eax
  int v3; // edx
  unsigned int v4; // [esp-4h] [ebp-4h]

  v1 = __readeflags();
  v4 = v1;
  _disable();
  HalpIRR |= 1 << a1;
  result = HalpIRR & 3;
  v3 = (unsigned __int8)*(&SWInterruptLookUpTable + result);
  if ( (unsigned __int8)v3 > (unsigned __int8)dword_8004C5D0 )
    (*(void (__cdecl **)(unsigned int))(4 * v3 - 2147173764))(v4);
  __writeeflags(v4);
  return result;
}