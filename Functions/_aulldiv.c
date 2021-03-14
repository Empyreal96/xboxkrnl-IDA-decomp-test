__int64 __stdcall _aulldiv(unsigned __int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int64 v3; // rtt
  __int64 result; // rax
  unsigned int v5; // ecx
  unsigned int v6; // ebx
  unsigned __int64 v7; // rax
  unsigned __int8 v8; // cf
  unsigned int v9; // eax
  unsigned int v10; // esi
  int v11; // ecx
  unsigned __int64 v12; // rax

  if ( a3 )
  {
    v5 = a3;
    v6 = a2;
    v7 = a1;
    do
    {
      v8 = v5 & 1;
      v5 >>= 1;
      v6 = __RCR__(v6, v8);
      v8 = BYTE4(v7) & 1;
      HIDWORD(v7) >>= 1;
      LODWORD(v7) = __RCR__(v7, v8);
    }
    while ( v5 );
    v9 = v7 / v6;
    v10 = v9;
    v11 = a3 * v9;
    v12 = v9 * (unsigned __int64)a2;
    v8 = __CFADD__(v11, HIDWORD(v12));
    HIDWORD(v12) += v11;
    if ( v8 || HIDWORD(v12) > HIDWORD(a1) || HIDWORD(v12) >= HIDWORD(a1) && (unsigned int)v12 > (unsigned int)a1 )
      --v10;
    result = v10;
  }
  else
  {
    LODWORD(v3) = a1;
    HIDWORD(v3) = HIDWORD(a1) % a2;
    LODWORD(result) = v3 / a2;
    HIDWORD(result) = HIDWORD(a1) / a2;
  }
  return result;
}