void __thiscall PrimitiveSet::createSurfOfRevVersion(PrimitiveSet *this, SurfOfRevVers *psurf, char *pbase, char *pextra, unsigned __int16 *pi, int idx, int ndet_bias)
{
  SurfOfRevVers *v7; // ebx
  unsigned int v8; // edi
  char *v9; // eax
  unsigned int v10; // ecx
  int v11; // esi
  void *v12; // esp
  void *v13; // esp
  void *v14; // esp
  int v15; // eax
  _D3DVECTOR *v16; // ecx
  float *v17; // eax
  _D3DVECTOR *v18; // edi
  int v19; // esi
  double v20; // st7
  double v21; // st6
  _D3DVECTOR *v22; // ecx
  int v23; // eax
  double v24; // st7
  float v25; // eax
  int v26; // eax
  float *v27; // eax
  int v28; // ecx
  void *v29; // esp
  _D3DVECTOR *v30; // ecx
  unsigned int v31; // esi
  float v32; // edx
  float *v33; // esi
  float *v34; // esi
  bool v35; // zf
  signed int v36; // eax
  signed int v37; // ecx
  _D3DVECTOR *v38; // ebx
  char *v39; // esi
  _D3DVECTOR *v40; // eax
  PrimitiveSet *v41; // eax
  ShaderTypes v42; // eax
  int v43; // ecx
  int v44; // edx
  unsigned __int16 *v45; // esi
  int v46; // ebx
  _WORD *v47; // esi
  signed int v48; // [esp+4h] [ebp-D4h]
  int v49; // [esp+8h] [ebp-D0h]
  _D3DMATRIX rotMat; // [esp+14h] [ebp-C4h]
  D3DVECTOR4 quat; // [esp+54h] [ebp-84h]
  _D3DVECTOR tang; // [esp+64h] [ebp-74h]
  _D3DVECTOR *pVertNorms; // [esp+70h] [ebp-68h]
  _D3DVECTOR axisToPt; // [esp+74h] [ebp-64h]
  float fU; // [esp+80h] [ebp-58h]
  int v56; // [esp+84h] [ebp-54h]
  float fDeltaV; // [esp+88h] [ebp-50h]
  _D3DVECTOR vAxis; // [esp+8Ch] [ebp-4Ch]
  _D3DVECTOR pt; // [esp+98h] [ebp-40h]
  PrimitiveSet *v60; // [esp+A4h] [ebp-34h]
  _D3DVECTOR *pVerts; // [esp+A8h] [ebp-30h]
  float fV; // [esp+ACh] [ebp-2Ch]
  unsigned int *dwVertFlags; // [esp+B0h] [ebp-28h]
  _D3DVECTOR ptOnAxis; // [esp+B4h] [ebp-24h]
  float fDeltaTheta; // [esp+C0h] [ebp-18h]
  int nsegs; // [esp+C4h] [ebp-14h]
  unsigned int unique_vert_count; // [esp+C8h] [ebp-10h]
  unsigned int j; // [esp+CCh] [ebp-Ch]
  _D3DVECTOR *pres; // [esp+D0h] [ebp-8h]
  int i; // [esp+D4h] [ebp-4h]
  _D3DVECTOR *fTheta; // [esp+E0h] [ebp+8h]
  unsigned int fThetaa; // [esp+E0h] [ebp+8h]
  float fThetad; // [esp+E0h] [ebp+8h]
  _D3DVECTOR *fThetab; // [esp+E0h] [ebp+8h]
  unsigned int fThetac; // [esp+E0h] [ebp+8h]
  _D3DVECTOR *wStartStripRight; // [esp+E4h] [ebp+Ch]
  int wStartStripRighta; // [esp+E4h] [ebp+Ch]
  _D3DVECTOR *wStartStripLeft; // [esp+E8h] [ebp+10h]
  int wStartStripLefta; // [esp+E8h] [ebp+10h]
  _D3DVECTOR *ndet_biasa; // [esp+F4h] [ebp+1Ch]
  int ndet_biasb; // [esp+F4h] [ebp+1Ch]

  v7 = psurf;
  v8 = psurf->nPts;
  v60 = this;
  j = v8;
  if ( (signed int)v8 > 0 )
  {
    v9 = &psurf->pts[0].flags;
    v10 = v8;
    do
    {
      if ( !(*v9 & 1) )
        ++v8;
      v9 += 16;
      --v10;
    }
    while ( v10 );
    j = v8;
  }
  v11 = 12 * v8;
  nsegs = 12 * v8;
  v12 = alloca(12 * v8);
  unique_vert_count = (unsigned int)&v49;
  v13 = alloca(12 * v8);
  pVerts = (_D3DVECTOR *)&v49;
  v14 = alloca(4 * v8);
  vAxis.x = psurf->ax;
  vAxis.y = psurf->ay;
  vAxis.z = psurf->az;
  ptOnAxis.x = psurf->px;
  ptOnAxis.y = psurf->py;
  ptOnAxis.z = psurf->pz;
  v15 = psurf->nPts;
  v16 = (_D3DVECTOR *)&v49;
  dwVertFlags = (unsigned int *)&v49;
  if ( v15 > 0 )
  {
    v17 = (float *)unique_vert_count;
    v18 = pVerts;
    i = 1;
    fTheta = (_D3DVECTOR *)unique_vert_count;
    pres = (_D3DVECTOR *)&v49;
    v19 = (int)&v7->pts[0].y;
    while ( 1 )
    {
      v20 = *(float *)(v19 + 4);
      v21 = *(float *)v19;
      v18->x = *(float *)(v19 - 4);
      v18->y = v21;
      v18->z = v20;
      if ( *(_BYTE *)(v19 + 8) & 1 )
      {
        LODWORD(v16->x) = 2;
      }
      else
      {
        v16->x = 0.0;
        *v17 = 0.0;
        ++v18;
        v22 = (_D3DVECTOR *)((char *)v16 + 4);
        v17[1] = 0.0;
        pres = v22;
        v23 = (int)(v17 + 3);
        *(float *)(v23 - 4) = 0.0;
        fTheta = (_D3DVECTOR *)v23;
        v24 = *(float *)(v19 + 4);
        v25 = *(float *)(v19 - 4);
        v18->y = *(float *)v19;
        v18->x = v25;
        v18->z = v24;
        LODWORD(v22->x) = 1;
      }
      v26 = i;
      if ( i == v7->nPts )
        v26 = 0;
      v27 = &v7->pts[v26].x;
      pt.x = *v27 - *(float *)(v19 - 4);
      pt.y = v27[1] - *(float *)v19;
      pt.z = v27[2] - *(float *)(v19 + 4);
      axisToPt.x = *v27 - ptOnAxis.x;
      axisToPt.y = v27[1] - ptOnAxis.y;
      axisToPt.z = v27[2] - ptOnAxis.z;
      Cross(&vAxis, &axisToPt, &tang);
      Cross(&tang, &pt, fTheta);
      Normalize(fTheta);
      pres = (_D3DVECTOR *)((char *)pres + 4);
      ++fTheta;
      v28 = v7->nPts;
      ++v18;
      ++i;
      v19 += 16;
      if ( i - 1 >= v28 )
        break;
      v16 = pres;
      v17 = &fTheta->x;
    }
    v11 = nsegs;
    v8 = j;
  }
  v29 = alloca(v11);
  v30 = (_D3DVECTOR *)&v49;
  pVertNorms = (_D3DVECTOR *)&v49;
  if ( (signed int)v8 > 0 )
  {
    v31 = unique_vert_count;
    fThetaa = v8 - 1;
    LODWORD(v32) = unique_vert_count - (_DWORD)&v49;
    pres = (_D3DVECTOR *)&v49;
    i = (int)dwVertFlags;
    LODWORD(fDeltaTheta) = unique_vert_count - (_DWORD)&v49;
    nsegs = v8;
    while ( *(_DWORD *)i )
    {
      if ( *(_DWORD *)i == 1 )
      {
        v33 = (float *)((char *)&v30->x + LODWORD(v32));
LABEL_26:
        v30->x = *v33;
        v34 = v33 + 1;
        v30->y = *v34;
        v30->z = v34[1];
        v8 = j;
        goto LABEL_27;
      }
      if ( *(_DWORD *)i == 2 )
      {
        Add((_D3DVECTOR *)(v31 + 12 * (fThetaa % v8)), (_D3DVECTOR *)((char *)v30 + LODWORD(v32)), v30);
        Normalize(pres);
        v30 = pres;
      }
LABEL_27:
      i += 4;
      ++fThetaa;
      ++v30;
      v35 = nsegs-- == 1;
      pres = v30;
      if ( v35 )
        goto LABEL_28;
      v32 = fDeltaTheta;
      v31 = unique_vert_count;
    }
    v33 = (float *)(v31 + 12 * (fThetaa % v8));
    goto LABEL_26;
  }
LABEL_28:
  v36 = v7->nSegs >> ndet_bias;
  v37 = v7->nPts;
  nsegs = v36;
  i = 0;
  v38 = (_D3DVECTOR *)pbase;
  v56 = v36 + 1;
  fDeltaTheta = 6.2831855 / (double)v36;
  fDeltaV = 1.0 / ((double)v37 - 1.0);
  if ( v36 + 1 <= 0 )
    goto LABEL_43;
  v39 = pextra;
  do
  {
    fThetad = (double)i * fDeltaTheta;
    SetQuatFromAxis(&vAxis, fThetad, &quat);
    SetRotationFromRHQuat(&quat, &rotMat);
    unique_vert_count = 0;
    j = 0;
    fU = fThetad * 0.15915494;
    if ( v8 )
    {
      wStartStripRight = (_D3DVECTOR *)(v39 + 24);
      ndet_biasa = (_D3DVECTOR *)(v39 + 32);
      fThetab = (_D3DVECTOR *)(v39 + 8);
      v40 = (_D3DVECTOR *)((char *)pVerts - (char *)pVertNorms);
      wStartStripLeft = pVertNorms;
      for ( pres = (_D3DVECTOR *)((char *)pVerts - (char *)pVertNorms); ; v40 = pres )
      {
        v35 = dwVertFlags[j] == 0;
        fV = (double)unique_vert_count * fDeltaV;
        if ( !v35 )
          ++unique_vert_count;
        Sub((_D3DVECTOR *)((char *)v40 + (_DWORD)wStartStripLeft), &ptOnAxis, &pt);
        TransformVector(&pt, &rotMat, v38);
        v41 = v60;
        v38->x = ptOnAxis.x + v38->x;
        v38->y = ptOnAxis.y + v38->y;
        v38->z = ptOnAxis.z + v38->z;
        v42 = v41->shaderType;
        if ( v42 )
        {
          if ( v42 != 1 )
            goto LABEL_40;
          Cross(&vAxis, &pt, &tang);
          TransformVector(&tang, &rotMat, fThetab);
          Normalize(fThetab);
          TransformVector(wStartStripLeft, &rotMat, ndet_biasa);
          Cross(ndet_biasa, fThetab, (_D3DVECTOR *)(v39 + 20));
          v48 = 44;
          *(float *)v39 = fU * 10.0;
          *((float *)v39 + 1) = fV * 10.0;
        }
        else
        {
          Cross(&vAxis, &pt, &axisToPt);
          TransformVector(&axisToPt, &rotMat, (_D3DVECTOR *)v39);
          Normalize((_D3DVECTOR *)v39);
          TransformVector(wStartStripLeft, &rotMat, wStartStripRight);
          Cross(wStartStripRight, (_D3DVECTOR *)v39, (_D3DVECTOR *)v39 + 1);
          v48 = 36;
        }
        ndet_biasa = (_D3DVECTOR *)((char *)ndet_biasa + v48);
        fThetab = (_D3DVECTOR *)((char *)fThetab + v48);
        v39 += v48;
        wStartStripRight = (_D3DVECTOR *)((char *)wStartStripRight + v48);
LABEL_40:
        ++wStartStripLeft;
        ++v38;
        if ( ++j >= v8 )
          break;
      }
    }
    ++i;
  }
  while ( i < v56 );
  v36 = nsegs;
LABEL_43:
  v43 = LOWORD(v60->aVersRecs[idx].dwVertexStart);
  v44 = v8 + v43;
  if ( v36 > 0 )
  {
    v45 = pi;
    v46 = v8 + 1;
    ndet_biasb = v36;
    do
    {
      fThetac = 0;
      wStartStripRighta = v44;
      wStartStripLefta = v43;
      if ( v46 )
      {
        do
        {
          *v45 = v44;
          v47 = v45 + 1;
          *v47 = v43;
          v45 = v47 + 1;
          if ( fThetac >= v8 - 1 )
          {
            v44 = wStartStripRighta;
            LOWORD(v43) = wStartStripLefta;
          }
          else
          {
            ++v44;
            LOWORD(v43) = v43 + 1;
          }
          ++fThetac;
          v46 = v8 + 1;
        }
        while ( fThetac < v8 + 1 );
      }
      v43 = v44;
      v44 += v8;
      --ndet_biasb;
    }
    while ( ndet_biasb );
  }
}