void __thiscall PrimitiveSet::createSphereVersion(PrimitiveSet *this, SphereVers *psphere, char *pbase, char *pextra, unsigned __int16 *pi, int idx, int ndet_bias)
{
  signed int v7; // edi
  float *v8; // esi
  int v9; // edx
  char *v10; // edx
  double v11; // st7
  double v12; // st6
  ShaderTypes v13; // eax
  char *v14; // edi
  int v15; // ST08_4
  char *v16; // ST04_4
  _DWORD *v17; // esi
  char *v18; // eax
  double v19; // st7
  _D3DVECTOR *v20; // edi
  _D3DVECTOR *v21; // ST04_4
  float *v22; // esi
  char *v23; // edx
  SphereVers *v24; // eax
  unsigned __int16 *v25; // ecx
  int v26; // ebx
  int v27; // esi
  _WORD *v28; // ecx
  float fV; // [esp+Ch] [ebp-50h]
  float fDeltaTheta; // [esp+1Ch] [ebp-40h]
  float fDeltaPhi; // [esp+2Ch] [ebp-30h]
  PrimitiveSet *v32; // [esp+30h] [ebp-2Ch]
  int nSlices; // [esp+34h] [ebp-28h]
  char *pbase_stream; // [esp+38h] [ebp-24h]
  int nSegs; // [esp+3Ch] [ebp-20h]
  float fCosTheta; // [esp+40h] [ebp-1Ch]
  int i; // [esp+44h] [ebp-18h]
  int j; // [esp+48h] [ebp-14h]
  float fTheta; // [esp+4Ch] [ebp-10h]
  float fSinTheta; // [esp+50h] [ebp-Ch]
  float fCosPhi; // [esp+54h] [ebp-8h]
  _D3DVECTOR *b; // [esp+58h] [ebp-4h]

  v32 = this;
  v7 = psphere->nSegs >> ndet_bias;
  v8 = (float *)pbase;
  i = 0;
  pbase_stream = pbase;
  nSegs = v7;
  v9 = v7 / 2;
  nSlices = v7 / 2;
  fDeltaTheta = 6.2831855 / (double)v7;
  fDeltaPhi = 3.1415927 / ((double)(v7 / 2) - 1.0);
  if ( v7 / 2 <= 0 )
    goto LABEL_12;
  do
  {
    *(float *)&psphere = (double)i * fDeltaPhi;
    fCosPhi = cos(*(float *)&psphere);
    *(float *)&ndet_bias = sin(*(float *)&psphere);
    j = 0;
    fV = *(float *)&psphere * 0.31830987;
    if ( v7 <= 0 )
      goto LABEL_11;
    v10 = pextra;
    b = (_D3DVECTOR *)(pextra + 24);
    pbase = pextra + 32;
    do
    {
      fTheta = (double)j * fDeltaTheta;
      fCosTheta = cos(fTheta);
      fSinTheta = sin(fTheta);
      v11 = fCosTheta;
      v12 = *(float *)&ndet_bias;
      *v8 = fCosPhi;
      v8[1] = v12 * v11;
      v8[2] = fSinTheta * *(float *)&ndet_bias;
      v13 = v32->shaderType;
      if ( v13 )
      {
        if ( v13 != 1 )
          goto LABEL_9;
        v14 = pbase;
        *((float *)v10 + 2) = 0.0;
        v15 = (int)(v10 + 20);
        v16 = pbase;
        *(float *)(v15 - 8) = -fSinTheta;
        *(float *)(v15 - 4) = v11;
        *(float *)v14 = *v8;
        v17 = v8 + 1;
        v14 += 4;
        *(_DWORD *)v14 = *v17;
        *((_DWORD *)v14 + 1) = v17[1];
        Cross((_D3DVECTOR *)(v10 + 8), (_D3DVECTOR *)v16, (_D3DVECTOR *)(v10 + 20));
        v18 = pextra;
        v19 = fTheta * 0.15915494;
        pbase += 44;
        *((float *)pextra + 1) = fV;
        *(float *)v18 = v19;
        b = (_D3DVECTOR *)((char *)b + 44);
        pextra = v18 + 44;
      }
      else
      {
        v20 = b;
        *(float *)v10 = 0.0;
        v21 = b;
        *((float *)v10 + 1) = -fSinTheta;
        *((float *)v10 + 2) = v11;
        v20->x = *v8;
        v22 = v8 + 1;
        v20 = (_D3DVECTOR *)((char *)v20 + 4);
        v20->x = *v22;
        v20->y = v22[1];
        Cross((_D3DVECTOR *)v10, v21, (_D3DVECTOR *)v10 + 1);
        pextra += 36;
        pbase += 36;
        b += 3;
      }
      v8 = (float *)pbase_stream;
      v10 = pextra;
      v7 = nSegs;
LABEL_9:
      v8 += 3;
      ++j;
      pbase_stream = (char *)v8;
    }
    while ( j < v7 );
    v9 = nSlices;
LABEL_11:
    ++i;
  }
  while ( i < v9 );
LABEL_12:
  v23 = (char *)(v9 - 1);
  v24 = (SphereVers *)LOWORD(v32->aVersRecs[idx].dwVertexStart);
  if ( (signed int)v23 > 0 )
  {
    v25 = pi;
    v26 = v7 + 1;
    pextra = v23;
    do
    {
      v27 = 0;
      psphere = v24;
      if ( v26 > 0 )
      {
        do
        {
          *v25 = v7 + (_WORD)v24;
          v28 = v25 + 1;
          *v28 = (_WORD)v24;
          v25 = v28 + 1;
          if ( v27 >= v7 - 1 )
            v24 = psphere;
          else
            ++v24;
          ++v27;
          v26 = v7 + 1;
        }
        while ( v27 < v7 + 1 );
      }
      v24 += v7;
      --pextra;
    }
    while ( pextra );
  }
}