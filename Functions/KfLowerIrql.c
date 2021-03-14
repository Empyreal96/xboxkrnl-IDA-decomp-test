void __fastcall KfLowerIrql(KIRQL NewIrql)
{
  unsigned int v1; // et0
  unsigned int v2; // [esp-4h] [ebp-4h]

  *(_DWORD *)&NewIrql = (unsigned __int8)NewIrql;
  if ( (unsigned __int8)NewIrql > (unsigned __int8)dword_8004C5D0 )
  {
    LOBYTE(dword_8004C5D0) = 31;
    KeBugCheck(0xAu);
  }
  v1 = __readeflags();
  v2 = v1;
  _disable();
  dword_8004C5D0 = NewIrql;
  if ( *(_DWORD *)(4 * NewIrql - 2147370500) & HalpIRR )
  {
    _BitScanReverse((unsigned int *)&NewIrql, *(_DWORD *)(4 * NewIrql - 2147370500) & HalpIRR);
    if ( (unsigned int)NewIrql <= 2 )
      (*(void (__cdecl **)(unsigned int))(4 * NewIrql - 2147173764))(v2);
    __outbyte(0x21u, HalpIDR);
    __outbyte(0xA1u, BYTE1(HalpIDR));
    HalpIRR ^= 1 << NewIrql;
    (*(void (__cdecl **)(unsigned int))(4 * NewIrql - 2147173764))(v2);
  }
  if ( ListHead.Next.Next )
  {
    if ( !NewIrql )
    {
      if ( ((int (__fastcall *)(_DWORD, _DWORD, unsigned int))ListHead.Next.Next)(0, 0, v2) )
      {
        _enable();
        __debugbreak();
      }
    }
    __writeeflags(v2);
  }
  else
  {
    __writeeflags(v2);
  }
}