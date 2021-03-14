void __thiscall PrimitiveSet::initTorusInstance(PrimitiveSet *this, TorusInst *ptorus, int idx)
{
  int v3; // ebx
  PrimitiveSet *v4; // esi
  _D3DMATRIX *v5; // ST0C_4
  double v6; // st7
  float z; // ST08_4
  double v8; // st7
  float v9; // ecx
  int v10; // eax
  int v11; // eax
  float v12; // ecx
  double v13; // st7
  PrimitiveInstanceRecord *v14; // eax
  int v15; // ecx
  __int16 v16; // ax
  int v17; // eax
  _D3DMATRIX mat; // [esp+1Ch] [ebp-5Ch]
  _D3DVECTOR tmp; // [esp+5Ch] [ebp-1Ch]
  _D3DVECTOR v; // [esp+68h] [ebp-10h]
  PrimitiveSet *v21; // [esp+74h] [ebp-4h]
  int idxa; // [esp+84h] [ebp+Ch]

  v3 = idx;
  v4 = this;
  v5 = &this->aInstRecs[idx].matScale;
  v6 = ptorus->fRad1;
  v21 = this;
  z = v6;
  SetScale(ptorus->fRad1, ptorus->fRad1, z, v5);
  v8 = ptorus->fRad1;
  v9 = ptorus->fRad1;
  v10 = (int)&v4->aInstRecs[idx].vObjScale;
  *(float *)(v10 + 4) = ptorus->fRad1;
  *(float *)v10 = v9;
  *(float *)(v10 + 8) = v8;
  *(float *)(v10 + 12) = 1.0;
  SetRotationFromLHQuat((D3DVECTOR4 *)(16 * ptorus->idQuat), &v4->aInstRecs[idx].matOffset);
  v4->aInstRecs[v3].matOffset._41 = (double)ptorus->tx * 0.004131 - 27.844984;
  v4->aInstRecs[v3].matOffset._42 = (double)ptorus->ty * 0.0082520004 - 0.22872899;
  v4->aInstRecs[v3].matOffset._43 = (double)ptorus->tz * 0.0044209999 + 0.49708599;
  SetInverse(&v4->aInstRecs[v3].matOffset, &v4->aInstRecs[v3].matInvOffset);
  MulMats(&v4->aInstRecs[v3].matScale, &v4->aInstRecs[v3].matOffset, &v4->aInstRecs[v3].matScaleOffset);
  v4->aInstRecs[v3].idxVersion = ptorus->idVersion;
  v4->aInstRecs[v3].idxPosAnim = ptorus->idPosAnim;
  v4->aInstRecs[v3].idxRotAnim = ptorus->idRotAnim;
  v11 = (int)&v4->aInstRecs[idx];
  v.x = *(float *)(v11 + 56);
  v12 = *(float *)(v11 + 60);
  v13 = *(float *)(v11 + 64);
  v14 = v4->aInstRecs;
  v.z = v13;
  v.y = v12;
  v15 = (int)&v14[idx];
  v16 = *(_WORD *)(v15 + 4);
  idxa = v15;
  if ( v16 >= 0 )
  {
    v17 = **(signed __int16 **)(4 * v16 - 2146385780);
    tmp = v;
    SetRotationFromLHQuat((D3DVECTOR4 *)(16 * v17), &mat);
    TransformVector(&tmp, &mat, &v);
    v13 = v.z;
    v15 = idxa;
    v4 = v21;
  }
  if ( *(_WORD *)(v15 + 2) >= 0 )
    v13 = v13 + *(float *)(12 * **(signed __int16 **)(4 * v4->aInstRecs[v3].idxPosAnim - 2146385660) + 8);
  *(_BYTE *)(v15 + 280) = v13 > 0.0;
}