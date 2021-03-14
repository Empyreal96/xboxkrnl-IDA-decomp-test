D3DVECTOR4 *__userpurge SceneRenderer::decompressQuats@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<esi>, __int16 *p_quat_data, unsigned int *p_sign_data, int nquats)
{
  int *v6; // eax
  int v7; // ebx
  __int16 *v8; // edi
  float *v9; // esi
  double v10; // st7
  float x; // ST00_4
  double v12; // st7
  D3DVECTOR4 *pquats; // [esp+10h] [ebp-4h]

  v6 = MemAlloc(a1, a2, a3, 16 * nquats);
  v7 = 0;
  pquats = (D3DVECTOR4 *)v6;
  if ( nquats > 0 )
  {
    v8 = p_quat_data;
    v9 = (float *)(v6 + 1);
    do
    {
      *(v9 - 1) = (double)*v8 * 0.000030534353;
      *v9 = (double)v8[1] * 0.000030534353;
      v10 = (double)v8[2] * 0.000030534353;
      v9[1] = v10;
      x = 1.0 - *(v9 - 1) * *(v9 - 1) - *v9 * *v9 - v10 * v10;
      v12 = fast_sqrt(x);
      v9[2] = v12;
      if ( !((1 << (v7 & 0x1F)) & p_sign_data[v7 >> 5]) )
        v9[2] = v12 * -1.0;
      ++v7;
      v9 += 4;
      v8 += 3;
    }
    while ( v7 < nquats );
  }
  return pquats;
}