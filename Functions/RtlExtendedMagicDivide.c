LARGE_INTEGER __stdcall RtlExtendedMagicDivide(LARGE_INTEGER Dividend, LARGE_INTEGER MagicDivisor, CCHAR ShiftCount)
{
  int v3; // esi
  bool v4; // cf
  unsigned __int64 v5; // rax
  CCHAR v6; // cl
  LARGE_INTEGER result; // rax

  v3 = Dividend.HighPart;
  if ( Dividend.HighPart < 0 )
  {
    v4 = Dividend.LowPart != 0;
    Dividend.LowPart = -Dividend.LowPart;
    Dividend.HighPart = -Dividend.HighPart - v4;
  }
  v5 = (unsigned int)((Dividend.HighPart * MagicDivisor.LowPart
                     + __PAIR__(
                         ((Dividend.LowPart * (unsigned __int64)MagicDivisor.LowPart >> 32)
                        + Dividend.LowPart * MagicDivisor.HighPart) >> 32,
                         MagicDivisor.QuadPart * (unsigned __int64)Dividend.LowPart >> 32)) >> 32)
     + ((unsigned int)Dividend.HighPart * (unsigned __int64)MagicDivisor.LowPart >> 32)
     + (Dividend.LowPart * (unsigned __int64)(unsigned int)MagicDivisor.HighPart >> 32)
     + (unsigned int)Dividend.HighPart * (unsigned __int64)(unsigned int)MagicDivisor.HighPart;
  v6 = ShiftCount;
  while ( (unsigned __int8)v6 > 0x1Fu )
  {
    v6 -= 31;
    v5 >>= 31;
  }
  result.QuadPart = v5 >> (v6 & 0x1F);
  if ( v3 < 0 )
  {
    result.LowPart = -result.LowPart;
    result.HighPart = -result.HighPart - (result.LowPart != 0);
  }
  return result;
}