void __userpurge XGRAPHICS::GetMasks2(unsigned int a1@<eax>, int Width, int Height, unsigned int *pMaskU, unsigned int *pMaskV)
{
  unsigned int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // eax
  char v8; // cl
  int v9; // edx
  int v10; // ecx
  int v11; // esi
  unsigned int v12; // edx
  int v13; // eax

  v5 = XGRAPHICS::Log2(a1, Width);
  v6 = v5;
  v7 = XGRAPHICS::Log2(v5, Height);
  v8 = v6;
  if ( v6 >= v7 )
    v8 = v7;
  v9 = (1 << 2 * v8) - 1;
  v10 = ~v9;
  if ( v6 <= v7 )
    v11 = v9 & 0x55555555;
  else
    v11 = v10 | 0x55555555;
  if ( v6 >= v7 )
    v12 = v9 & 0xAAAAAAAA;
  else
    v12 = v10 | 0xAAAAAAAA;
  v13 = (1 << (v7 + v6)) - 1;
  *pMaskU = v11 & v13;
  *pMaskV = v12 & v13;
}