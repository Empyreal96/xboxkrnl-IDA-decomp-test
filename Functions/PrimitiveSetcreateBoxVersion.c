void __thiscall PrimitiveSet::createBoxVersion(PrimitiveSet *this, char *pbase, char *pextra, unsigned __int16 *pi, int idx)
{
  unsigned __int16 *v5; // ebx
  float *v6; // eax
  double v7; // st4
  double v8; // st4
  double v9; // st4
  double v10; // st4
  double v11; // st4
  _D3DVECTOR *v12; // ecx
  _D3DVECTOR *v13; // edx
  _D3DVECTOR *v14; // esi
  BaseStream *v15; // edi
  ShaderTypes v16; // esi
  int v17; // esi
  float *v18; // edi
  float *v19; // edi
  float *v20; // edi
  __int16 v21; // dx
  _WORD *v22; // ebx
  signed int v23; // [esp-10h] [ebp-98h]
  float fUV[4][2]; // [esp+0h] [ebp-88h]
  PrimitiveSet *v25; // [esp+20h] [ebp-68h]
  BaseStream *pbase_stream; // [esp+24h] [ebp-64h]
  _D3DVECTOR *v27; // [esp+28h] [ebp-60h]
  int j; // [esp+2Ch] [ebp-5Ch]
  int i; // [esp+30h] [ebp-58h]
  _D3DVECTOR vPos[4]; // [esp+34h] [ebp-54h]
  _D3DVECTOR vS; // [esp+64h] [ebp-24h]
  _D3DVECTOR vT; // [esp+70h] [ebp-18h]
  _D3DVECTOR vN; // [esp+7Ch] [ebp-Ch]
  char *pbasea; // [esp+90h] [ebp+8h]
  char *pextraa; // [esp+94h] [ebp+Ch]
  unsigned __int16 *pia; // [esp+98h] [ebp+10h]

  fUV[0][0] = 0.0;
  i = 0;
  fUV[0][1] = 1.0;
  v5 = pi;
  pbase_stream = (BaseStream *)pbase;
  fUV[1][0] = 1.0;
  v6 = (float *)pextra;
  v25 = this;
  fUV[1][1] = 1.0;
  fUV[2][0] = 1.0;
  fUV[2][1] = 0.0;
  fUV[3][0] = 0.0;
  fUV[3][1] = 0.0;
  do
  {
    switch ( i )
    {
      case 0:
        vS.x = 0.0;
        vS.y = 1.0;
        vS.z = 0.0;
        vT.x = 0.0;
        vT.y = 0.0;
        vT.z = 1.0;
        vN.x = 1.0;
        vN.y = 0.0;
        vN.z = 0.0;
        vPos[0].x = 0.5;
        vPos[0].y = -0.5;
        vPos[0].z = 0.5;
        vPos[1].x = 0.5;
        vPos[1].y = 0.5;
        vPos[1].z = 0.5;
        vPos[2].x = 0.5;
        vPos[2].y = 0.5;
        vPos[2].z = -0.5;
        v10 = 0.5;
        goto LABEL_16;
      case 1:
        vS.x = -1.0;
        vS.y = 0.0;
        vS.z = 0.0;
        vT.x = 0.0;
        vT.y = 0.0;
        vT.z = 1.0;
        vN.x = 0.0;
        vN.y = 1.0;
        vN.z = 0.0;
        vPos[0].x = 0.5;
        vPos[0].y = 0.5;
        vPos[0].z = 0.5;
        vPos[1].x = -0.5;
        vPos[1].y = 0.5;
        vPos[1].z = 0.5;
        vPos[2].x = -0.5;
        vPos[2].y = 0.5;
        vPos[2].z = -0.5;
        v8 = 0.5;
LABEL_14:
        vPos[3].x = v8;
        v11 = 0.5;
LABEL_17:
        vPos[3].y = v11;
        v9 = -0.5;
        goto LABEL_18;
      case 2:
        vS.x = 0.0;
        vS.y = -1.0;
        vS.z = 0.0;
        vT.x = 0.0;
        vT.y = 0.0;
        vT.z = 1.0;
        vN.x = 0.0;
        vN.y = -1.0;
        vN.z = 0.0;
        vPos[0].x = -0.5;
        vPos[0].y = 0.5;
        vPos[0].z = 0.5;
        vPos[1].x = -0.5;
        vPos[1].y = -0.5;
        vPos[1].z = 0.5;
        vPos[2].x = -0.5;
        v7 = -0.5;
LABEL_9:
        vPos[2].y = v7;
        vPos[2].z = -0.5;
        v8 = -0.5;
        goto LABEL_14;
      case 3:
        vS.x = 1.0;
        vS.y = 0.0;
        vS.z = 0.0;
        vT.x = 0.0;
        vT.y = 0.0;
        vT.z = 1.0;
        vN.x = 0.0;
        vN.y = -1.0;
        vN.z = 0.0;
        vPos[0].x = -0.5;
        vPos[0].y = -0.5;
        vPos[0].z = 0.5;
        vPos[1].x = 0.5;
        vPos[1].y = -0.5;
        vPos[1].z = 0.5;
        vPos[2].x = 0.5;
        vPos[2].y = -0.5;
        vPos[2].z = -0.5;
        v10 = -0.5;
LABEL_16:
        vPos[3].x = v10;
        v11 = -0.5;
        goto LABEL_17;
      case 4:
        vS.x = 1.0;
        vS.y = 0.0;
        vS.z = 0.0;
        vT.x = 0.0;
        vT.y = 1.0;
        vT.z = 0.0;
        vN.x = 0.0;
        vN.y = 0.0;
        vN.z = 1.0;
        vPos[0].x = -0.5;
        vPos[0].y = 0.5;
        vPos[0].z = 0.5;
        vPos[1].x = 0.5;
        vPos[1].y = 0.5;
        vPos[1].z = 0.5;
        vPos[2].x = 0.5;
        vPos[2].y = -0.5;
        vPos[2].z = 0.5;
        vPos[3].x = -0.5;
        vPos[3].y = -0.5;
        v9 = 0.5;
LABEL_18:
        vPos[3].z = v9;
        break;
      case 5:
        vS.x = 1.0;
        vS.y = 0.0;
        vS.z = 0.0;
        vT.x = 0.0;
        vT.y = -1.0;
        vT.z = 0.0;
        vN.x = 0.0;
        vN.y = 0.0;
        vN.z = -1.0;
        vPos[0].x = -0.5;
        vPos[0].y = -0.5;
        vPos[0].z = -0.5;
        vPos[1].x = 0.5;
        vPos[1].y = -0.5;
        vPos[1].z = -0.5;
        vPos[2].x = 0.5;
        v7 = 0.5;
        goto LABEL_9;
    }
    j = 0;
    pextraa = (char *)(v6 + 6);
    pia = (unsigned __int16 *)(v6 + 3);
    pbasea = (char *)(v6 + 8);
    v12 = (_D3DVECTOR *)(v6 + 5);
    v13 = (_D3DVECTOR *)(v6 + 2);
    v27 = vPos;
    do
    {
      v14 = v27;
      v15 = pbase_stream;
      pbase_stream->p.x = v27->x;
      v14 = (_D3DVECTOR *)((char *)v14 + 4);
      v15 = (BaseStream *)((char *)v15 + 4);
      v15->p.x = v14->x;
      v15->p.y = v14->y;
      v16 = v25->shaderType;
      if ( v16 )
      {
        if ( v16 != 1 )
          goto LABEL_25;
        v17 = j;
        *v6 = fUV[j][0];
        v23 = 44;
        v6[1] = fUV[v17][1];
        *v13 = vS;
        *v12 = vT;
        v18 = (float *)pbasea;
      }
      else
      {
        *(_D3DVECTOR *)v6 = vS;
        *(float *)pia = vT.x;
        v19 = (float *)(pia + 2);
        *v19 = vT.y;
        v19[1] = vT.z;
        v18 = (float *)pextraa;
        v23 = 36;
      }
      *v18 = vN.x;
      v20 = v18 + 1;
      *v20 = vN.y;
      v20[1] = vN.z;
      pia = (unsigned __int16 *)((char *)pia + v23);
      pbasea += v23;
      v12 = (_D3DVECTOR *)((char *)v12 + v23);
      v13 = (_D3DVECTOR *)((char *)v13 + v23);
      v6 = (float *)((char *)v6 + v23);
      pextraa += v23;
LABEL_25:
      ++pbase_stream;
      ++j;
      ++v27;
    }
    while ( j < 4 );
    v21 = 4 * i;
    *v5 = 4 * i;
    v22 = v5 + 1;
    *v22 = v21 + 1;
    ++v22;
    *v22 = v21 + 2;
    ++v22;
    *v22 = v21;
    ++v22;
    *v22 = v21 + 2;
    ++v22;
    *v22 = v21 + 3;
    v5 = v22 + 1;
    ++i;
  }
  while ( i < 6 );
}