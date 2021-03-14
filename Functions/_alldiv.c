int __stdcall _alldiv(__int64 a1, unsigned int a2, int a3)
{
  signed int v3; // edi
  int v4; // eax
  int result; // eax
  unsigned __int64 v6; // rtt
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  unsigned __int64 v9; // rax
  unsigned __int8 v10; // cf
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  unsigned __int64 v14; // rax

  v3 = 0;
  if ( a1 < 0 )
  {
    v3 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(signed int)a1;
  }
  v4 = a3;
  if ( a3 < 0 )
  {
    ++v3;
    v4 = -a3 - (a2 != 0);
    a3 = -a3 - (a2 != 0);
    a2 = -a2;
  }
  if ( v4 )
  {
    v7 = v4;
    v8 = a2;
    v9 = a1;
    do
    {
      v10 = v7 & 1;
      v7 >>= 1;
      v8 = __RCR__(v8, v10);
      v10 = BYTE4(v9) & 1;
      HIDWORD(v9) >>= 1;
      LODWORD(v9) = __RCR__(v9, v10);
    }
    while ( v7 );
    v11 = v9 / v8;
    v12 = v11;
    v13 = a3 * v11;
    v14 = (unsigned int)v11 * (unsigned __int64)a2;
    v10 = __CFADD__(v13, HIDWORD(v14));
    HIDWORD(v14) += v13;
    if ( v10 || HIDWORD(v14) > HIDWORD(a1) || HIDWORD(v14) >= HIDWORD(a1) && (unsigned int)v14 > (unsigned int)a1 )
      --v12;
    result = v12;
  }
  else
  {
    LODWORD(v6) = a1;
    HIDWORD(v6) = HIDWORD(a1) % a2;
    result = v6 / a2;
  }
  if ( v3 == 1 )
    result = -result;
  return result;
}