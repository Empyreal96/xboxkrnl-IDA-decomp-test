double __stdcall fast_sin(float x)
{
  float v1; // xmm0_4
  unsigned int v2; // edx
  bool v3; // zf
  float v4; // xmm0_4

  v1 = COERCE_FLOAT(LODWORD(x) & m128const_am_inv_sign_mask[0]) * 0.63661975;
  v2 = ((signed int)v1 << 30) & 0x80000000;
  v3 = ((signed int)v1 & 1) == 0;
  v4 = v1 - (float)(signed int)v1;
  if ( !v3 )
    v4 = 1.0 - v4;
  return (float)((float)((float)((float)((float)((float)((float)((float)(v4 * v4) * -0.0046817539) + 0.079692625)
                                               * (float)(v4 * v4))
                                       + -0.64596409)
                               * (float)(v4 * v4))
                       + 1.5707964)
               * COERCE_FLOAT(LODWORD(v4) | v2 ^ LODWORD(x) & 0x80000000));
}