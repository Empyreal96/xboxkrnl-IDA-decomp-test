void __thiscall PrimitiveSet::initConeInstance(PrimitiveSet *this, SurfOfRevInst *psurf, int idx)
{
  int v3; // ebx
  PrimitiveSet *v4; // esi
  _D3DMATRIX *v5; // ST0C_4
  float *v6; // eax
  int v7; // eax
  const void *v8; // esi
  void *v9; // edi
  PrimitiveSet *v10; // eax
  int v11; // ecx
  float v12; // edx
  double v13; // st7
  PrimitiveInstanceRecord *v14; // ecx
  int v15; // ecx
  __int16 v16; // dx
  int v17; // eax
  _D3DMATRIX mat; // [esp+1Ch] [ebp-5Ch]
  _D3DVECTOR tmp; // [esp+5Ch] [ebp-1Ch]
  _D3DVECTOR v; // [esp+68h] [ebp-10h]
  PrimitiveSet *v21; // [esp+74h] [ebp-4h]
  SurfOfRevInst *psurfa; // [esp+80h] [ebp+8h]

  v3 = idx;
  v4 = this;
  v5 = &this->aInstRecs[idx].matScale;
  v21 = this;
  SetScale(1.0, 1.0, 1.0, v5);
  v6 = &v4->aInstRecs[idx].vObjScale.x;
  *v6 = 1.0;
  v6[1] = 1.0;
  v6[2] = 1.0;
  v6[3] = 1.0;
  SetRotationFromLHQuat((D3DVECTOR4 *)(16 * psurf->idQuat), &v4->aInstRecs[idx].matOffset);
  v4->aInstRecs[v3].matOffset._41 = (double)psurf->tx * 0.004131 - 27.844984;
  v4->aInstRecs[v3].matOffset._42 = (double)psurf->ty * 0.0082520004 - 0.22872899;
  v4->aInstRecs[v3].matOffset._43 = (double)psurf->tz * 0.0044209999 + 0.49708599;
  SetInverse(&v4->aInstRecs[v3].matOffset, &v4->aInstRecs[v3].matInvOffset);
  v7 = (int)&v4->aInstRecs[idx];
  v8 = (const void *)(v7 + 8);
  v9 = (void *)(v7 + 216);
  v10 = v21;
  qmemcpy(v9, v8, 0x40u);
  v21->aInstRecs[v3].idxVersion = psurf->idVersion;
  v10->aInstRecs[v3].idxPosAnim = psurf->idPosAnim;
  v10->aInstRecs[v3].idxRotAnim = psurf->idRotAnim;
  v11 = (int)&v10->aInstRecs[idx];
  v.x = *(float *)(v11 + 56);
  v12 = *(float *)(v11 + 60);
  v13 = *(float *)(v11 + 64);
  v14 = v10->aInstRecs;
  v.z = v13;
  v15 = (int)&v14[idx];
  v.y = v12;
  v16 = *(_WORD *)(v15 + 4);
  psurfa = (SurfOfRevInst *)v15;
  if ( v16 >= 0 )
  {
    v17 = **(signed __int16 **)(4 * v16 - 2146385780);
    tmp = v;
    SetRotationFromLHQuat((D3DVECTOR4 *)(16 * v17), &mat);
    TransformVector(&tmp, &mat, &v);
    v13 = v.z;
    v10 = v21;
    v15 = (int)psurfa;
  }
  if ( *(_WORD *)(v15 + 2) >= 0 )
    v13 = v13 + *(float *)(12 * **(signed __int16 **)(4 * v10->aInstRecs[v3].idxPosAnim - 2146385660) + 8);
  *(_BYTE *)(v15 + 280) = v13 > 0.0;
}