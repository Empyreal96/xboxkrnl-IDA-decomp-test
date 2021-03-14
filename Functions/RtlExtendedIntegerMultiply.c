LARGE_INTEGER __stdcall RtlExtendedIntegerMultiply(LARGE_INTEGER Multiplicand, LONG Multiplier)
{
  int v2; // esi
  bool v3; // cf
  unsigned int v4; // ecx
  int v5; // eax

  v2 = Multiplicand.HighPart ^ Multiplier;
  if ( Multiplicand.HighPart < 0 )
  {
    v3 = Multiplicand.LowPart != 0;
    Multiplicand.LowPart = -Multiplicand.LowPart;
    Multiplicand.HighPart = -Multiplicand.HighPart - v3;
  }
  if ( Multiplier < 0 )
    Multiplier = -Multiplier;
  v4 = Multiplicand.LowPart * Multiplier;
  v5 = Multiplicand.QuadPart * (unsigned __int64)(unsigned int)Multiplier >> 32;
  if ( v2 < 0 )
  {
    v4 = -v4;
    v5 = -v5 - (v4 != 0);
  }
  return (LARGE_INTEGER)__PAIR__(v5, v4);
}