int __fastcall BenalohModRoot(int a1, int a2, unsigned int *M, unsigned int *C, unsigned int *PP, unsigned int *QQ, unsigned int *DP, unsigned int *DQ, unsigned int *CR, unsigned int PSize)
{
  unsigned int *v10; // eax
  unsigned int *v12; // ebp
  unsigned int *v13; // edx
  unsigned int *v14; // edx
  int v15; // ecx
  unsigned int *t1; // [esp+8h] [ebp-128h]
  int fSuccess; // [esp+Ch] [ebp-124h]
  unsigned int *pdwSlowBuffer; // [esp+10h] [ebp-120h]
  int v19; // [esp+14h] [ebp-11Ch]
  unsigned int dwTemp[68]; // [esp+20h] [ebp-110h]

  pdwSlowBuffer = 0;
  fSuccess = 0;
  if ( 16 * PSize <= 0x110 )
  {
    v10 = dwTemp;
  }
  else
  {
    v10 = (unsigned int *)RSA32Alloc(a2, a1, PSize, 16 * PSize);
    pdwSlowBuffer = v10;
    if ( !v10 )
      return 0;
  }
  v12 = &v10[PSize];
  v19 = 2 * PSize;
  t1 = v10;
  if ( Mod((int)v10, PP, C, PP, &v12[2 * PSize], 2 * PSize - 1, PSize)
    && BenalohModExp(2 * PSize - 1, t1, &v12[2 * PSize], DP, PP, PSize)
    && Mod((int)C, v13, C, QQ, &v12[2 * PSize], 2 * PSize - 1, PSize)
    && BenalohModExp((int)QQ, v12, &v12[2 * PSize], DQ, QQ, PSize) )
  {
    if ( Sub((int)&v12[2 * PSize], (int)t1, v12, PSize) )
    {
      while ( !Add((int)&v12[2 * PSize], (int)&v12[2 * PSize], PP, PSize) )
        ;
    }
    Multiply(M, &v12[2 * PSize], CR, PSize);
    if ( Mod(v15, v14, M, PP, &v12[2 * PSize], v19 - 1, PSize) )
    {
      Multiply(M, &v12[2 * PSize], QQ, PSize);
      memset(&v12[PSize], 0, 4 * PSize);
      Add((int)M, (int)M, v12, v19);
      fSuccess = 1;
    }
  }
  memset(t1, 0, 16 * PSize);
  if ( pdwSlowBuffer )
    RSA32Free(pdwSlowBuffer);
  return fSuccess;
}