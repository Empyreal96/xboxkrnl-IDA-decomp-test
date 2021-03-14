void __thiscall SceneRenderer::advanceTime(SceneRenderer *this, float fElapsedTime, float fDt)
{
  SceneRenderer *v3; // ebx
  double v4; // st7
  double v5; // st7
  int v6; // edx
  bool v7; // zf
  bool v8; // sf
  double v9; // st7
  __int16 **v10; // ecx
  int v11; // eax
  _DWORD *v12; // esi
  _DWORD *v13; // edi
  __int16 *v14; // eax
  signed __int16 *v15; // esi
  _D3DVECTOR *v16; // ecx
  float *v17; // eax
  float *v18; // ecx
  double v19; // st5
  unsigned __int8 v20; // of
  int v21; // edi
  __int16 **v22; // esi
  int v23; // eax
  D3DVECTOR4 *v24; // eax
  _D3DMATRIX *v25; // [esp+4h] [ebp-38h]
  D3DVECTOR4 res; // [esp+14h] [ebp-28h]
  float ffrac; // [esp+24h] [ebp-18h]
  __int16 **v28; // [esp+28h] [ebp-14h]
  int pos_id; // [esp+2Ch] [ebp-10h]
  float fpos; // [esp+30h] [ebp-Ch]
  float ffrac_pos; // [esp+34h] [ebp-8h]
  int i; // [esp+38h] [ebp-4h]

  v3 = this;
  v4 = (fElapsedTime - 0.85000002) * 0.22222222;
  fpos = v4;
  v5 = v4 * 28.0;
  ffrac = v5;
  ffrac_pos = v5;
  pos_id = (signed int)ffrac_pos;
  v6 = 0;
  v7 = this->nPosAnims == 0;
  v8 = this->nPosAnims < 0;
  i = 0;
  v9 = ffrac_pos - (double)(signed int)ffrac_pos;
  if ( !v8 && !v7 )
  {
    v10 = this->pPosIdSeq;
    v28 = v3->pPosIdSeq;
    do
    {
      if ( fpos > 0.0 )
      {
        v14 = *v10;
        if ( fpos < 1.0 )
        {
          v15 = &v14[pos_id];
          v16 = v3->pPos;
          v17 = &v16[*v15].x;
          v18 = &v16[v15[1]].x;
          v3->pPosAnims[v6].x = (1.0 - v9) * *v17 + v9 * *v18;
          v3->pPosAnims[v6].y = (1.0 - v9) * v17[1] + v9 * v18[1];
          v19 = v9 * v18[2];
          v10 = v28;
          v3->pPosAnims[v6].z = (1.0 - v9) * v17[2] + v19;
          goto LABEL_9;
        }
        v11 = v14[29];
      }
      else
      {
        v11 = **v10;
      }
      v12 = (_DWORD *)&v3->pPos[v11].x;
      v13 = (_DWORD *)&v3->pPosAnims[v6].x;
      *v13 = *v12;
      ++v12;
      ++v13;
      *v13 = *v12;
      v13[1] = v12[1];
LABEL_9:
      ++i;
      ++v10;
      ++v6;
      v20 = __OFSUB__(i, v3->nPosAnims);
      v8 = i - v3->nPosAnims < 0;
      v28 = v10;
    }
    while ( v8 ^ v20 );
  }
  ffrac_pos = ffrac;
  pos_id = (signed int)ffrac;
  v21 = 0;
  v7 = v3->nRotAnims == 0;
  v8 = v3->nRotAnims < 0;
  i = 0;
  ffrac = ffrac - (double)(signed int)ffrac;
  if ( !v8 && !v7 )
  {
    v22 = v3->pQuatIdSeq;
    do
    {
      if ( fpos > 0.0 )
      {
        if ( fpos < 1.0 )
        {
          SlerpQuats(&v3->pQuats[(*v22)[pos_id]], &v3->pQuats[(*v22)[pos_id + 1]], ffrac, &res);
          v25 = &v3->pRotAnims[v21];
          v24 = &res;
          goto LABEL_18;
        }
        v25 = &v3->pRotAnims[v21];
        v23 = (*v22)[29];
      }
      else
      {
        v25 = &v3->pRotAnims[v21];
        v23 = **v22;
      }
      v24 = &v3->pQuats[v23];
LABEL_18:
      SetRotationFromLHQuat(v24, v25);
      ++i;
      ++v22;
      ++v21;
    }
    while ( i < v3->nRotAnims );
  }
  v3->bUseLoDetail = fElapsedTime >= 5.1999998;
}