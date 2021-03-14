_D3DVECTOR *__fastcall SceneRenderer::decompressVecs(int a1, int a2, __int16 *p_vec_data, int nvecs)
{
  int v4; // esi
  _D3DVECTOR *result; // eax
  __int16 *v6; // edx
  float *v7; // ecx
  int nvecsa; // [esp+10h] [ebp+Ch]

  v4 = nvecs;
  result = (_D3DVECTOR *)MemAlloc(a2, a1, nvecs, 12 * nvecs);
  if ( nvecs > 0 )
  {
    v6 = p_vec_data;
    v7 = &result->z;
    do
    {
      nvecsa = *v6;
      v6 += 3;
      *(v7 - 2) = (double)nvecsa * 0.002755 - 0.15904599;
      *(v7 - 1) = (double)*(v6 - 2) * 0.002755 - 0.741611;
      *v7 = (double)*(v6 - 1) * 0.00244 + 2.1556239;
      v7 += 3;
      --v4;
    }
    while ( v4 );
  }
  return result;
}