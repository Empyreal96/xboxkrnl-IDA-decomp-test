int __userpurge BenalohModExp@<eax>(int a1@<ebx>, unsigned int *A, unsigned int *B, unsigned int *C, unsigned int *D, unsigned int len)
{
  int v6; // esi
  int result; // eax
  unsigned int v8; // edi
  int v9; // edx
  int *v10; // ebx
  int v11; // edx
  unsigned int *v12; // ebp
  unsigned int *v13; // edi
  bool v14; // zf
  int v15; // eax
  unsigned int v16; // edi
  int v17; // ecx
  int v18; // esi
  int v19; // ecx
  int v20; // edi
  unsigned int *v21; // esi
  unsigned int v22; // edi
  int powerTableSize; // [esp+8h] [ebp-30h]
  unsigned int v24; // [esp+Ch] [ebp-2Ch]
  int i; // [esp+10h] [ebp-28h]
  int ia; // [esp+10h] [ebp-28h]
  int N; // [esp+14h] [ebp-24h]
  int prevPosition; // [esp+18h] [ebp-20h]
  int firstTime; // [esp+1Ch] [ebp-1Ch]
  int mask; // [esp+20h] [ebp-18h]
  BenalohData BenalohContext; // [esp+24h] [ebp-14h]
  unsigned int *Ba; // [esp+40h] [ebp+8h]
  unsigned int *Bb; // [esp+40h] [ebp+8h]

  v6 = BitLen(C, len);
  if ( !v6 )
  {
    SetValDWORD(a1, A, 1u, len);
    return 1;
  }
  v8 = DigitLen(D, len);
  N = v8;
  if ( !BenalohSetup(&BenalohContext, D, v8) )
    return 0;
  if ( v6 > 17 )
  {
    if ( v6 > 32 )
    {
      if ( v6 > 64 )
      {
        if ( v6 > 128 )
          powerTableSize = v6 > 256 ? 32 : 16;
        else
          powerTableSize = 8;
      }
      else
      {
        powerTableSize = 4;
      }
    }
    else
    {
      powerTableSize = 2;
    }
  }
  else
  {
    powerTableSize = 1;
  }
  v10 = RSA32Alloc(v9, 4 * v8 * (powerTableSize + 1), v6, 4 * v8 * (powerTableSize + 1));
  if ( !v10 )
  {
    RSA32Free(BenalohContext.M);
    return 0;
  }
  v24 = v8;
  v11 = 4 * v8;
  qmemcpy(&v10[v8], B, 4 * v8);
  v12 = BenalohContext.product;
  if ( powerTableSize > 1 )
  {
    BenalohModSquare(&BenalohContext, (unsigned int *)v10, B);
    if ( powerTableSize > 1 )
    {
      v13 = (unsigned int *)&v10[v24];
      Ba = (unsigned int *)&v10[v24 + v24];
      i = powerTableSize - 1;
      do
      {
        Multiply(v12, v13, (unsigned int *)v10, BenalohContext.N);
        BenalohMod(&BenalohContext, v12, Ba);
        v13 = (unsigned int *)((char *)v13 + v24 * 4);
        v14 = i == 1;
        Ba = (unsigned int *)((char *)Ba + v24 * 4);
        --i;
      }
      while ( !v14 );
    }
  }
  v15 = v6 - 1;
  v16 = 1 << (v6 - 1) % 32;
  v17 = v6 - 1;
  v18 = 0;
  firstTime = 1;
  prevPosition = v15;
  ia = v15;
  if ( v15 >= 0 )
  {
    while ( 1 )
    {
      v11 = (int)C;
      v18 *= 2;
      if ( v16 & C[v17 / 32] )
        ++v18;
      mask = (v16 >> 1) | (v16 << 31);
      if ( !v17 || v18 >= powerTableSize )
      {
        v19 = prevPosition - ia;
        Bb = 0;
        for ( prevPosition = ia; v18; Bb = (unsigned int *)((char *)Bb + 1) )
        {
          v11 = v18 % 2;
          if ( v18 % 2 )
            break;
          --v19;
          v18 /= 2;
          v11 = (int)Bb + 1;
        }
        if ( firstTime )
        {
          v11 = N * (v18 - 1) / 2;
          qmemcpy(v10, &v10[v24 + v11], v24 * 4);
          firstTime = 0;
        }
        else
        {
          if ( v19 )
          {
            v20 = v19;
            do
            {
              Square(v12, (unsigned int *)v10, BenalohContext.N);
              BenalohMod(&BenalohContext, v12, (unsigned int *)v10);
              --v20;
            }
            while ( v20 );
          }
          if ( v18 )
          {
            Multiply(v12, (unsigned int *)v10, (unsigned int *)&v10[v24 + N * (v18 - 1) / 2], BenalohContext.N);
            BenalohMod(&BenalohContext, v12, (unsigned int *)v10);
          }
        }
        v21 = Bb;
        if ( Bb )
        {
          v22 = BenalohContext.N;
          do
          {
            Square(v12, (unsigned int *)v10, v22);
            BenalohMod(&BenalohContext, v12, (unsigned int *)v10);
            v21 = (unsigned int *)((char *)v21 - 1);
          }
          while ( v21 );
        }
        v17 = ia;
        v18 = 0;
      }
      ia = --v17;
      if ( v17 < 0 )
        break;
      v16 = mask;
    }
  }
  if ( Mod(v17, (unsigned int *)v11, (unsigned int *)v10, D, A, N, N) )
  {
    memset(&A[v24], 0, 4 * (len - N));
    RSA32Free(BenalohContext.M);
    RSA32Free(v10);
    result = 1;
  }
  else
  {
    RSA32Free(BenalohContext.M);
    RSA32Free(v10);
    result = 0;
  }
  return result;
}