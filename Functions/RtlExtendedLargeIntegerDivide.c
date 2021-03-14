LARGE_INTEGER __stdcall RtlExtendedLargeIntegerDivide(LARGE_INTEGER Dividend, ULONG Divisor, PULONG Remainder)
{
  int v3; // ecx
  LARGE_INTEGER result; // rax
  signed int v5; // ecx
  unsigned int v6; // esi
  unsigned __int8 v7; // cf
  unsigned __int8 v8; // tt
  ULONG v9; // esi
  unsigned __int8 v10; // tt
  int v11; // edi

  result = Dividend;
  if ( !Divisor )
    RtlRaiseStatus(v3, Dividend.HighPart, -1073741676);
  v5 = 64;
  v6 = 0;
  do
  {
    v8 = __CFRCL__(result.HighPart, __CFSHL__(result.LowPart, 1));
    result.HighPart = __RCL__(result.HighPart, __CFSHL__(result.LowPart, 1));
    v7 = v8;
    v10 = __CFRCL__(v6, v8);
    v9 = __RCL__(v6, v7);
    v11 = -(v9 >= Divisor) | -v10;
    result.LowPart = 2 * result.LowPart - v11;
    v6 = v9 - (Divisor & v11);
    --v5;
  }
  while ( v5 );
  if ( Remainder )
    *Remainder = v6;
  return result;
}