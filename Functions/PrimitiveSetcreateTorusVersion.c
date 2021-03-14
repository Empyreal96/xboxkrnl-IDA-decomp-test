void __thiscall PrimitiveSet::createTorusVersion(PrimitiveSet *this, TorusVers *ptorus, char *pbase, char *pextra, unsigned __int16 *pi, int idx, int ndet_bias)
{
  TorusVers *v7; // edx
  char v8; // cl
  int v9; // edi
  int v10; // esi
  signed int v11; // esi
  float fDeltaTheta; // ST2C_4
  char *v13; // esi
  double v14; // st7
  ShaderTypes v15; // eax
  double v16; // st7
  char *v17; // ecx
  float v18; // edx
  double v19; // st7
  double v20; // st7
  char *v21; // eax
  float v22; // ecx
  double v23; // st7
  PrimitiveVersionRecord *v24; // ecx
  int v25; // ecx
  char *v26; // eax
  int v27; // ebx
  unsigned __int16 *v28; // edx
  int v29; // ebx
  float fV; // [esp+Ch] [ebp-4Ch]
  float fZ; // [esp+10h] [ebp-48h]
  float fDeltaPhi; // [esp+30h] [ebp-28h]
  PrimitiveSet *v33; // [esp+34h] [ebp-24h]
  float fRad; // [esp+38h] [ebp-20h]
  int nsides; // [esp+3Ch] [ebp-1Ch]
  int j; // [esp+40h] [ebp-18h]
  BaseStream *pbase_stream; // [esp+44h] [ebp-14h]
  float fTheta; // [esp+48h] [ebp-10h]
  float fPhi; // [esp+4Ch] [ebp-Ch]
  int i; // [esp+50h] [ebp-8h]
  float fCosPhi; // [esp+54h] [ebp-4h]
  TorusVers *ptorusa; // [esp+60h] [ebp+8h]

  v7 = ptorus;
  v33 = this;
  v8 = ndet_bias;
  v9 = ptorus->nSegs >> ndet_bias;
  v10 = ptorus->nSides;
  ndet_bias = ptorus->nSegs >> ndet_bias;
  v11 = v10 >> v8;
  i = 0;
  pbase_stream = (BaseStream *)pbase;
  nsides = v11;
  fDeltaPhi = 6.2831855 / (double)v11;
  if ( v11 > 0 )
  {
    v13 = pextra;
    while ( 1 )
    {
      fPhi = (double)i * fDeltaPhi;
      fCosPhi = cos(fPhi);
      *(float *)&ndet_bias = sin(fPhi);
      j = 0;
      fRad = fCosPhi * v7->fRatio + 1.0;
      fV = fPhi * 0.15915494;
      fZ = *(float *)&ndet_bias * v7->fRatio;
      if ( v9 > 0 )
        break;
LABEL_11:
      if ( ++i >= nsides )
      {
        v11 = nsides;
        goto LABEL_13;
      }
    }
    fTheta = 0.0;
    while ( 1 )
    {
      fDeltaTheta = 6.2831855 / (double)v9;
      fTheta = (double)SLODWORD(fTheta) * fDeltaTheta;
      *(float *)&pbase = cos(fTheta);
      *(float *)&pextra = sin(fTheta);
      v14 = *(float *)&pbase * fRad;
      pbase_stream->p.z = fZ;
      pbase_stream->p.x = v14;
      pbase_stream->p.y = *(float *)&pextra * fRad;
      v15 = v33->shaderType;
      if ( v15 == st_Phong )
        break;
      if ( v15 == 1 )
      {
        v16 = fTheta * 0.15915494;
        v17 = pbase;
        v18 = fCosPhi;
        *((float *)v13 + 1) = fV;
        *(float *)v13 = v16;
        v19 = *(float *)&pextra;
        *((_DWORD *)v13 + 3) = v17;
        *((float *)v13 + 2) = -v19;
        *((float *)v13 + 4) = 0.0;
        v20 = *(float *)&pbase;
        *((float *)v13 + 7) = v18;
        *((float *)v13 + 5) = -(v20 * *(float *)&ndet_bias);
        *((float *)v13 + 6) = -(*(float *)&pextra * *(float *)&ndet_bias);
        Cross((_D3DVECTOR *)(v13 + 8), (_D3DVECTOR *)(v13 + 20), (_D3DVECTOR *)(v13 + 32));
        v13 += 44;
LABEL_9:
        v7 = ptorus;
      }
      ++pbase_stream;
      LODWORD(fTheta) = (unsigned __int16)++j;
      if ( (unsigned __int16)j >= v9 )
        goto LABEL_11;
    }
    v21 = pbase;
    v22 = fCosPhi;
    *(float *)v13 = -*(float *)&pextra;
    *((_DWORD *)v13 + 1) = v21;
    *((float *)v13 + 2) = 0.0;
    v23 = *(float *)&pbase;
    *((float *)v13 + 5) = v22;
    *((float *)v13 + 3) = -(v23 * *(float *)&ndet_bias);
    *((float *)v13 + 4) = -(*(float *)&pextra * *(float *)&ndet_bias);
    Cross((_D3DVECTOR *)v13, (_D3DVECTOR *)v13 + 1, (_D3DVECTOR *)v13 + 2);
    v13 += 36;
    goto LABEL_9;
  }
LABEL_13:
  v24 = v33->aVersRecs;
  i = 0;
  v25 = LOWORD(v24[idx].dwVertexStart);
  pextra = (char *)v25;
  v26 = (char *)(v9 + v25);
  if ( v11 > 0 )
  {
    do
    {
      v27 = 0;
      ndet_bias = v25;
      pbase = v26;
      ptorusa = 0;
      if ( v9 + 1 > 0 )
      {
        do
        {
          v28 = pi;
          *pi = v25;
          ++v28;
          *v28 = (unsigned __int16)v26;
          pi = v28 + 1;
          if ( v27 >= v9 - 1 )
          {
            v25 = ndet_bias;
            v26 = pbase;
          }
          else
          {
            ++v25;
            ++v26;
          }
          ptorusa = (TorusVers *)((char *)ptorusa + 1);
          v27 = (unsigned __int16)ptorusa;
        }
        while ( (unsigned __int16)ptorusa < v9 + 1 );
      }
      v25 += v9;
      v29 = i + 1;
      if ( i + 1 >= v11 - 1 )
        v26 = pextra;
      else
        v26 += v9;
      ++i;
    }
    while ( v29 < v11 );
  }
}