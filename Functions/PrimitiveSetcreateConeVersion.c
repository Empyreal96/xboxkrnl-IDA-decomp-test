void __fastcall PrimitiveSet::createConeVersion(PrimitiveSet *this, int a2, ConeVers *pcone, char *pbase, char *pextra, unsigned __int16 *pi, int idx, int ndet_bias)
{
  ConeVers *v8; // ebx
  signed int v9; // edi
  int v10; // esi
  float fDeltaTheta; // ST38_4
  int v12; // edx
  int v13; // ecx
  int *v14; // eax
  char *v15; // edx
  float *v16; // esi
  double v17; // st7
  double v18; // st7
  double v19; // st6
  int v20; // eax
  char *v21; // esi
  double v22; // st6
  double v23; // st5
  ShaderTypes v24; // ecx
  float *v25; // eax
  float v26; // ecx
  ShaderTypes v27; // ecx
  _D3DVECTOR *v28; // eax
  int v29; // edi
  double v30; // st7
  int v31; // edi
  int v32; // ebx
  double v33; // st6
  float *v34; // edi
  double v35; // st6
  ShaderTypes v36; // ecx
  double v37; // st7
  double v38; // st7
  double v39; // st6
  double v40; // st5
  float v41; // edi
  float v42; // ST1C_4
  double v43; // st7
  double v44; // st7
  double v45; // st6
  double v46; // st5
  float v47; // edi
  float v48; // ST1C_4
  unsigned __int16 v49; // ax
  unsigned __int16 *v50; // ecx
  signed int v51; // edx
  signed int v52; // edx
  float fDeltaZ; // [esp+Ch] [ebp-34h]
  float *v54; // [esp+1Ch] [ebp-24h]
  _D3DVECTOR *ppts_top; // [esp+20h] [ebp-20h]
  int nsides; // [esp+24h] [ebp-1Ch]
  int j; // [esp+28h] [ebp-18h]
  PrimitiveSet *v58; // [esp+2Ch] [ebp-14h]
  int *ppts_bot; // [esp+30h] [ebp-10h]
  float fZ; // [esp+34h] [ebp-Ch]
  float fSinTheta; // [esp+38h] [ebp-8h]
  float fTheta; // [esp+3Ch] [ebp-4h]
  char *pextraa; // [esp+50h] [ebp+10h]
  char *pextrab; // [esp+50h] [ebp+10h]
  int i; // [esp+5Ch] [ebp+1Ch]
  int ia; // [esp+5Ch] [ebp+1Ch]
  int ib; // [esp+5Ch] [ebp+1Ch]

  v8 = pcone;
  v58 = this;
  LOBYTE(this) = ndet_bias;
  v9 = pcone->nSides >> ndet_bias;
  nsides = v9;
  v10 = 4 * (3 * v9 + 3);
  ppts_bot = MemAlloc(a2, (int)this, v10, v10);
  v14 = MemAlloc(v12, v13, v10, v10);
  v15 = pbase;
  i = 0;
  ppts_top = (_D3DVECTOR *)v14;
  if ( v9 + 1 > 0 )
  {
    v54 = (float *)v14;
    v16 = (float *)(ppts_bot + 2);
    do
    {
      fDeltaTheta = 6.2831855 / (double)v9;
      fTheta = (double)i * fDeltaTheta;
      fZ = cos(fTheta);
      fSinTheta = sin(fTheta);
      v17 = fSinTheta * pcone->fRad1;
      ++i;
      *(v16 - 2) = fZ * pcone->fRad1;
      *(v16 - 1) = v17;
      v18 = fTheta * 0.15915494;
      *v16 = v18;
      v19 = fSinTheta * pcone->fRad2;
      *v54 = fZ * pcone->fRad2;
      v54 += 3;
      *(v54 - 2) = v19;
      *(float *)((char *)v16 + (char *)v14 - (char *)ppts_bot) = v18;
      v16 += 3;
    }
    while ( i < v9 + 1 );
    v8 = pcone;
  }
  fDeltaZ = 1.0 / (double)v8->nHeightSeg;
  if ( v9 - 1 < 0 )
  {
    v21 = pextra;
  }
  else
  {
    v20 = (int)&v14[3 * (v9 - 1)];
    v21 = pextra;
    ia = v9;
    do
    {
      v22 = v8->fHeight;
      v23 = *(float *)(v20 + 4);
      *(_DWORD *)v15 = *(_DWORD *)v20;
      *((float *)v15 + 1) = v23;
      *((float *)v15 + 2) = v22;
      v24 = v58->shaderType;
      if ( v24 )
      {
        if ( v24 == 1 )
        {
          *(float *)v21 = *(float *)v20 + 0.5;
          v21 += 44;
          *((float *)v21 - 10) = *(float *)(v20 + 4) + 0.5;
          *((float *)v21 - 9) = 1.0;
          *((float *)v21 - 8) = 0.0;
          *((float *)v21 - 7) = 0.0;
          *((float *)v21 - 6) = 0.0;
          *((float *)v21 - 5) = 1.0;
          *((float *)v21 - 4) = 0.0;
          *((float *)v21 - 3) = 0.0;
          *((float *)v21 - 2) = 0.0;
          *((float *)v21 - 1) = 1.0;
        }
      }
      else
      {
        *(float *)v21 = 1.0;
        v21 += 36;
        *((float *)v21 - 8) = 0.0;
        *((float *)v21 - 7) = 0.0;
        *((float *)v21 - 6) = 0.0;
        *((float *)v21 - 5) = 1.0;
        *((float *)v21 - 4) = 0.0;
        *((float *)v21 - 3) = 0.0;
        *((float *)v21 - 2) = 0.0;
        *((float *)v21 - 1) = 1.0;
      }
      v15 += 12;
      v20 -= 12;
      --ia;
    }
    while ( ia );
    pbase = v15;
  }
  if ( v9 > 0 )
  {
    v25 = (float *)ppts_bot;
    pextraa = (char *)v9;
    do
    {
      v26 = *v25;
      *((float *)v15 + 1) = v25[1];
      *(float *)v15 = v26;
      *((float *)v15 + 2) = 0.0;
      v27 = v58->shaderType;
      if ( v27 )
      {
        if ( v27 == 1 )
        {
          *(float *)v21 = *v25 + 0.5;
          v21 += 44;
          *((float *)v21 - 10) = v25[1] + 0.5;
          *((float *)v21 - 9) = 1.0;
          *((float *)v21 - 8) = 0.0;
          *((float *)v21 - 7) = 0.0;
          *((float *)v21 - 6) = 0.0;
          *((float *)v21 - 5) = -1.0;
          *((float *)v21 - 4) = 0.0;
          *((float *)v21 - 3) = 0.0;
          *((float *)v21 - 2) = 0.0;
          *((float *)v21 - 1) = -1.0;
        }
      }
      else
      {
        *(float *)v21 = 1.0;
        v21 += 36;
        *((float *)v21 - 8) = 0.0;
        *((float *)v21 - 7) = 0.0;
        *((float *)v21 - 6) = 0.0;
        *((float *)v21 - 5) = -1.0;
        *((float *)v21 - 4) = 0.0;
        *((float *)v21 - 3) = 0.0;
        *((float *)v21 - 2) = 0.0;
        *((float *)v21 - 1) = -1.0;
      }
      v15 += 12;
      v25 += 3;
      --pextraa;
    }
    while ( pextraa );
    pbase = v15;
  }
  ib = 0;
  if ( v8->nHeightSeg + 1 <= 0 )
    goto LABEL_33;
  do
  {
    j = 0;
    fZ = (double)ib * fDeltaZ;
    if ( v9 + 1 <= 0 )
      goto LABEL_32;
    LODWORD(fTheta) = v21 + 12;
    v28 = (_D3DVECTOR *)(v21 + 8);
    v29 = 0;
    pextrab = v21 + 8;
    LODWORD(fSinTheta) = v21 + 20;
    do
    {
      v30 = fZ * v8->fHeight;
      v31 = 3 * v29;
      v32 = (int)&ppts_top[v31 / 3u];
      v33 = ppts_top[v31 / 3u].y;
      v34 = (float *)&ppts_bot[v31];
      v35 = (v33 - v34[1]) * fZ + v34[1];
      *(float *)v15 = (*(float *)v32 - *v34) * fZ + *v34;
      *((float *)v15 + 1) = v35;
      *((float *)v15 + 2) = v30;
      v36 = v58->shaderType;
      if ( v36 )
      {
        if ( v36 != 1 )
          goto LABEL_30;
        v37 = *(float *)v32;
        v28->x = -*(float *)(v32 + 4);
        v28->y = v37;
        v28->z = 0.0;
        Normalize(v28);
        v38 = pcone->fHeight;
        v39 = *(float *)(v32 + 4) - v34[1];
        v40 = *(float *)v32 - *v34;
        v41 = fSinTheta;
        v42 = fSinTheta;
        *(float *)LODWORD(fSinTheta) = v40;
        *(float *)(LODWORD(v41) + 4) = v39;
        *(float *)(LODWORD(v41) + 8) = v38;
        Normalize((_D3DVECTOR *)LODWORD(v42));
        Cross((_D3DVECTOR *)pextrab, (_D3DVECTOR *)LODWORD(v41), (_D3DVECTOR *)(v21 + 32));
        *(_DWORD *)v21 = *(_DWORD *)(v32 + 8);
        *((float *)v21 + 1) = fZ;
        pextrab += 44;
        v21 += 44;
        LODWORD(fTheta) += 44;
        LODWORD(fSinTheta) = LODWORD(v41) + 44;
      }
      else
      {
        v43 = *(float *)v32;
        *(float *)v21 = -*(float *)(v32 + 4);
        *((float *)v21 + 1) = v43;
        v28->x = 0.0;
        Normalize((_D3DVECTOR *)v21);
        v44 = pcone->fHeight;
        v45 = *(float *)(v32 + 4) - v34[1];
        v46 = *(float *)v32 - *v34;
        v47 = fTheta;
        v48 = fTheta;
        *(float *)LODWORD(fTheta) = v46;
        *(float *)(LODWORD(v47) + 4) = v45;
        *(float *)(LODWORD(v47) + 8) = v44;
        Normalize((_D3DVECTOR *)LODWORD(v48));
        Cross((_D3DVECTOR *)v21, (_D3DVECTOR *)LODWORD(v47), (_D3DVECTOR *)v21 + 2);
        LODWORD(fSinTheta) += 36;
        pextrab += 36;
        v21 += 36;
        LODWORD(fTheta) = LODWORD(v47) + 36;
      }
      v28 = (_D3DVECTOR *)pextrab;
      v15 = pbase;
LABEL_30:
      v8 = pcone;
      v15 += 12;
      v29 = (unsigned __int16)++j;
      pbase = v15;
    }
    while ( (unsigned __int16)j < nsides + 1 );
    v9 = nsides;
LABEL_32:
    ++ib;
  }
  while ( ib < v8->nHeightSeg + 1 );
LABEL_33:
  MemFree(ppts_bot);
  MemFree(ppts_top);
  v49 = v58->aVersRecs[idx].dwVertexStart;
  v50 = pi;
  if ( v9 > 0 )
  {
    v51 = v9;
    do
    {
      *v50 = v49;
      ++v50;
      ++v49;
      --v51;
    }
    while ( v51 );
    if ( v9 > 0 )
    {
      v52 = v9;
      do
      {
        *v50 = v49;
        ++v50;
        ++v49;
        --v52;
      }
      while ( v52 );
    }
  }
  CreateTristripForMesh(v50, v9, v8->nHeightSeg, 0, 0, v49, 0, 0);
}