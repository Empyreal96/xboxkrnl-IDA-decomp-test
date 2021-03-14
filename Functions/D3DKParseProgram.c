unsigned int *__stdcall D3DK::ParseProgram(unsigned int *pDst, const unsigned int *pProgram, unsigned int Dwords)
{
  unsigned int *result; // eax
  unsigned int v4; // ecx
  signed int v5; // ebx
  bool v6; // zf

  result = pDst;
  v4 = Dwords;
  do
  {
    v5 = v4;
    if ( v4 >= 0x20 )
      v5 = 32;
    *result = (v5 << 18) + 2816;
    qmemcpy(result + 1, pProgram, 4 * ((unsigned int)(4 * v5) >> 2));
    result = &pDst[v5 + 1];
    v4 = Dwords - v5;
    v6 = Dwords == v5;
    pProgram += v5;
    pDst += v5 + 1;
    Dwords -= v5;
  }
  while ( !v6 );
  return result;
}