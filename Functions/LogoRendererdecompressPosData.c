float *__fastcall LogoRenderer::decompressPosData(int a1, int a2, __int16 *pdata, int ncount, float f_oo_scale, float f_delta)
{
  float *result; // eax
  int i; // ecx

  result = (float *)MemAlloc(a2, a1, ncount, 12 * ncount);
  for ( i = 0; i < 3 * ncount; ++i )
    result[i] = (double)pdata[i] * f_oo_scale + f_delta;
  return result;
}