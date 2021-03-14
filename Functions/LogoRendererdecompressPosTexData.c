float *__fastcall LogoRenderer::decompressPosTexData(int a1, int a2, __int16 *pdata, int ncount, float f_oo_pos_scale, float f_pos_delta, float f_oo_tex_scale, float f_tex_delta)
{
  int *v8; // edi
  __int16 *v9; // ecx
  float *v10; // esi
  unsigned int v11; // eax
  int ncounta; // [esp+14h] [ebp+Ch]

  v8 = MemAlloc(a2, a1, ncount, 20 * ncount);
  if ( 5 * ncount > 0 )
  {
    v9 = pdata + 2;
    v10 = (float *)(v8 + 2);
    v11 = (5 * ncount - 1) / 5u + 1;
    do
    {
      *(v10 - 2) = (double)*(v9 - 2) * f_oo_pos_scale + f_pos_delta;
      *(v10 - 1) = (double)*(v9 - 1) * f_oo_pos_scale + f_pos_delta;
      ncounta = *v9;
      v9 += 5;
      *v10 = (double)ncounta * f_oo_pos_scale + f_pos_delta;
      v10 += 5;
      --v11;
      *(v10 - 4) = (double)*(v9 - 4) * f_oo_tex_scale + f_tex_delta;
      *(v10 - 3) = (double)*(v9 - 3) * f_oo_tex_scale + f_tex_delta;
    }
    while ( v11 );
  }
  return (float *)v8;
}