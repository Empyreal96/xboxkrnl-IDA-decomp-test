unsigned int __stdcall EstimateQuotient(unsigned int r1, unsigned int r2, unsigned int m1, unsigned int m2)
{
  unsigned int v4; // ecx
  __int64 v5; // rax
  unsigned int v6; // edi

  v4 = r2;
  HIDWORD(v5) = r1;
  if ( !m2 || (m1 & 0x80000000) != 0 )
  {
    if ( r1 < m1 )
      return __PAIR__(r1, r2) / m1;
    goto LABEL_12;
  }
  if ( r1 >= m1 && (r1 > m1 || r2 >= m2) )
  {
LABEL_12:
    LODWORD(v5) = -1;
    return v5;
  }
  LODWORD(v5) = 0;
  v6 = 2147483648;
  do
  {
    HIDWORD(v5) = __PAIR__(HIDWORD(v5), v4) >> 31;
    v4 *= 2;
    if ( __PAIR__(HIDWORD(v5), v4) >= __PAIR__(m1, m2) )
    {
      HIDWORD(v5) = (__PAIR__(HIDWORD(v5), v4) - __PAIR__(m1, m2)) >> 32;
      v4 -= m2;
      LODWORD(v5) = v6 | v5;
    }
    v6 >>= 1;
  }
  while ( v6 );
  return v5;
}