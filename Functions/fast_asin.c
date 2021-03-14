double __stdcall fast_asin(float x)
{
  unsigned int v1; // eax
  float v2; // xmm0_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  signed int v5; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4

  if ( x < 0.0 )
  {
    v1 = LODWORD(x) & 0x7FFFFFFF;
    if ( LODWORD(x) & 0x7FFFFFFF )
    {
      if ( v1 >= 0xBF800000 )
        return -1.5707964;
      if ( v1 < 0xBF3504F3 )
        goto asculc;
asrett:
      v7 = 1.0 - (float)(x * x);
      v8 = 1.0 / fsqrt(v7);
      return fast_atan((float)((float)(v8 * 1.5) - (float)((float)((float)((float)(v7 * v8) * v8) * v8) * 0.5)) * x);
    }
    return 0.0;
  }
  if ( x == 0.0 )
    return 0.0;
  if ( LODWORD(x) >= 0x3F800000 )
    return 1.5707964;
  if ( LODWORD(x) >= 0x3F3504F3 )
    goto asrett;
asculc:
  v2 = 1.0;
  v3 = 1.0;
  v4 = 1.0;
  v5 = 48;
  do
  {
    v2 = v2 * t_as[v5];
    v4 = v4 * (float)(x * x);
    v3 = v3 + (float)(v2 * v4);
    --v5;
  }
  while ( (float)(v2 * v4) >= 0.000001 && v5 != 0 );
  return (float)(v3 * x);
}