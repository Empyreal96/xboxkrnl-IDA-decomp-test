void __stdcall AccumulateSquares(unsigned int *A, unsigned int *B, unsigned int blen)
{
  unsigned int *v3; // esi
  unsigned int *v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // edx
  int v9; // kr04_4
  unsigned int v10; // ebx
  unsigned __int64 v11; // rax

  v3 = B;
  v4 = A;
  v5 = blen;
  v6 = 0;
  do
  {
    v7 = *v3;
    ++v3;
    v8 = (v7 * (unsigned __int64)v7 + v6) >> 32;
    v9 = v7 * v7 + v6;
    v10 = v4[1];
    v11 = __PAIR__(v8, v9) + *(_QWORD *)v4;
    *(_QWORD *)v4 = v11;
    v6 = __CFADD__(v10, HIDWORD(v11));
    v4 += 2;
    --v5;
  }
  while ( v5 );
}