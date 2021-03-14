void __fastcall PrimitiveSet::createCylinderVersion(PrimitiveSet *this, int a2, CylinderVers *pcyl, char *pbase, char *pextra, unsigned __int16 *pi, int idx, int ndet_bias)
{
  int v8; // esi
  PrimitiveSet *v9; // edi
  float v10; // esi
  float fDeltaTheta; // ST40_4
  int *v12; // eax
  char *v13; // edx
  float *v14; // edi
  double v15; // st7
  char *v16; // eax
  _D3DVECTOR *v17; // ecx
  float v18; // ebx
  ShaderTypes v19; // ebx
  _D3DVECTOR *v20; // ecx
  float v21; // ebx
  ShaderTypes v22; // ebx
  CylinderVers *v23; // ebx
  int v24; // ecx
  double v25; // st7
  int v26; // ecx
  _D3DVECTOR *v27; // ecx
  float v28; // ebx
  ShaderTypes v29; // ebx
  double v30; // st6
  double v31; // st6
  float v32; // ecx
  double v33; // st6
  double v34; // st6
  float v35; // ecx
  int v36; // ecx
  unsigned __int16 v37; // ax
  unsigned __int16 *v38; // ecx
  float v39; // edx
  float v40; // edx
  float fDeltaZ; // [esp+Ch] [ebp-24h]
  PrimitiveSet *v42; // [esp+10h] [ebp-20h]
  float fSinTheta; // [esp+24h] [ebp-Ch]
  float fCosTheta; // [esp+28h] [ebp-8h]
  _D3DVECTOR *ppts; // [esp+2Ch] [ebp-4h]

  v8 = pcyl->nSides;
  v9 = this;
  LOBYTE(this) = ndet_bias;
  ndet_bias = pcyl->nHeightSeg;
  LODWORD(v10) = v8 >> (char)this;
  v42 = v9;
  fSinTheta = v10;
  fDeltaZ = 1.0 / (double)ndet_bias;
  v12 = MemAlloc(a2, (int)this, SLODWORD(v10), 4 * (3 * LODWORD(v10) + 3));
  ndet_bias = 0;
  v13 = pbase;
  ppts = (_D3DVECTOR *)v12;
  if ( LODWORD(v10) + 1 > 0 )
  {
    v14 = (float *)(v12 + 2);
    do
    {
      fDeltaTheta = 6.2831855 / (double)SLODWORD(v10);
      *(float *)&pbase = (double)ndet_bias * fDeltaTheta;
      fCosTheta = cos(*(float *)&pbase);
      fSinTheta = sin(*(float *)&pbase);
      v15 = *(float *)&pbase * 0.15915494;
      ++ndet_bias;
      *(v14 - 2) = fCosTheta;
      *(v14 - 1) = fSinTheta;
      *v14 = v15;
      v14 += 3;
    }
    while ( ndet_bias < LODWORD(v10) + 1 );
    v9 = v42;
  }
  if ( LODWORD(v10) - 1 < 0 )
  {
    v16 = pextra;
  }
  else
  {
    ndet_bias = LODWORD(v10);
    v16 = pextra;
    v17 = &ppts[LODWORD(v10) - 1];
    do
    {
      v18 = v17->x;
      *((float *)v13 + 1) = v17->y;
      *(float *)v13 = v18;
      *((float *)v13 + 2) = 1.0;
      v19 = v9->shaderType;
      if ( v19 )
      {
        if ( v19 == 1 )
        {
          *(float *)v16 = v17->x + 0.5;
          v16 += 44;
          *((float *)v16 - 10) = v17->y + 0.5;
          *((float *)v16 - 9) = 1.0;
          *((float *)v16 - 8) = 0.0;
          *((float *)v16 - 7) = 0.0;
          *((float *)v16 - 6) = 0.0;
          *((float *)v16 - 5) = 1.0;
          *((float *)v16 - 4) = 0.0;
          *((float *)v16 - 3) = 0.0;
          *((float *)v16 - 2) = 0.0;
          *((float *)v16 - 1) = 1.0;
        }
      }
      else
      {
        *(float *)v16 = 1.0;
        v16 += 36;
        *((float *)v16 - 8) = 0.0;
        *((float *)v16 - 7) = 0.0;
        *((float *)v16 - 6) = 0.0;
        *((float *)v16 - 5) = 1.0;
        *((float *)v16 - 4) = 0.0;
        *((float *)v16 - 3) = 0.0;
        *((float *)v16 - 2) = 0.0;
        *((float *)v16 - 1) = 1.0;
      }
      v13 += 12;
      --v17;
      --ndet_bias;
    }
    while ( ndet_bias );
  }
  if ( SLODWORD(v10) > 0 )
  {
    v20 = ppts;
    pextra = (char *)LODWORD(v10);
    do
    {
      v21 = v20->x;
      *((float *)v13 + 1) = v20->y;
      *(float *)v13 = v21;
      *((float *)v13 + 2) = 0.0;
      v22 = v9->shaderType;
      if ( v22 )
      {
        if ( v22 == 1 )
        {
          *(float *)v16 = v20->x + 0.5;
          v16 += 44;
          *((float *)v16 - 10) = v20->y + 0.5;
          *((float *)v16 - 9) = 1.0;
          *((float *)v16 - 8) = 0.0;
          *((float *)v16 - 7) = 0.0;
          *((float *)v16 - 6) = 0.0;
          *((float *)v16 - 5) = -1.0;
          *((float *)v16 - 4) = 0.0;
          *((float *)v16 - 3) = 0.0;
          *((float *)v16 - 2) = 0.0;
          *((float *)v16 - 1) = -1.0;
        }
      }
      else
      {
        *(float *)v16 = 1.0;
        v16 += 36;
        *((float *)v16 - 8) = 0.0;
        *((float *)v16 - 7) = 0.0;
        *((float *)v16 - 6) = 0.0;
        *((float *)v16 - 5) = -1.0;
        *((float *)v16 - 4) = 0.0;
        *((float *)v16 - 3) = 0.0;
        *((float *)v16 - 2) = 0.0;
        *((float *)v16 - 1) = -1.0;
      }
      v13 += 12;
      ++v20;
      --pextra;
    }
    while ( pextra );
  }
  v23 = pcyl;
  v24 = pcyl->nHeightSeg;
  ndet_bias = 0;
  if ( v24 + 1 > 0 )
  {
    do
    {
      pextra = 0;
      v25 = (double)ndet_bias * fDeltaZ;
      if ( LODWORD(v10) + 1 > 0 )
      {
        v26 = 0;
        do
        {
          v27 = &ppts[v26];
          v28 = v27->x;
          *((float *)v13 + 1) = v27->y;
          *(float *)v13 = v28;
          *((float *)v13 + 2) = v25;
          v29 = v9->shaderType;
          if ( v29 )
          {
            if ( v29 == 1 )
            {
              *(float *)v16 = v27->z * 4.0;
              v16 += 44;
              *((float *)v16 - 10) = 32.0 * v25;
              v30 = v27->x;
              *((float *)v16 - 9) = -v27->y;
              *((float *)v16 - 8) = v30;
              *((float *)v16 - 7) = 0.0;
              *((float *)v16 - 6) = 0.0;
              *((float *)v16 - 5) = 0.0;
              *((float *)v16 - 4) = 1.0;
              v31 = v27->y;
              v32 = v27->x;
              *((float *)v16 - 2) = v31;
              *((float *)v16 - 3) = v32;
              *((float *)v16 - 1) = 0.0;
            }
          }
          else
          {
            v33 = v27->x;
            *(float *)v16 = -v27->y;
            v16 += 36;
            *((float *)v16 - 8) = v33;
            *((float *)v16 - 7) = 0.0;
            *((float *)v16 - 6) = 0.0;
            *((float *)v16 - 5) = 0.0;
            *((float *)v16 - 4) = 1.0;
            v34 = v27->y;
            v35 = v27->x;
            *((float *)v16 - 2) = v34;
            *((float *)v16 - 3) = v35;
            *((float *)v16 - 1) = 0.0;
          }
          v13 += 12;
          v26 = (unsigned __int16)++pextra;
        }
        while ( (unsigned __int16)pextra < LODWORD(v10) + 1 );
      }
      v23 = pcyl;
      v36 = pcyl->nHeightSeg;
      ++ndet_bias;
    }
    while ( ndet_bias < v36 + 1 );
  }
  MemFree(ppts);
  v37 = v9->aVersRecs[idx].dwVertexStart;
  v38 = pi;
  if ( SLODWORD(v10) > 0 )
  {
    v39 = v10;
    do
    {
      *v38 = v37;
      ++v38;
      ++v37;
      --LODWORD(v39);
    }
    while ( v39 != 0.0 );
    if ( SLODWORD(v10) > 0 )
    {
      v40 = v10;
      do
      {
        *v38 = v37;
        ++v38;
        ++v37;
        --LODWORD(v40);
      }
      while ( v40 != 0.0 );
    }
  }
  CreateTristripForMesh(v38, SLODWORD(v10), v23->nHeightSeg, 0, 0, v37, 0, 0);
}