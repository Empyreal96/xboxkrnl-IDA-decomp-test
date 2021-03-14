double __stdcall fast_sqrt(float x)
{
  float v1; // xmm1_4

  if ( x != 0.0 )
  {
    v1 = 1.0 / fsqrt(x);
    x = (float)((float)(v1 * 1.5) - (float)((float)((float)((float)(x * v1) * v1) * v1) * 0.5)) * x;
  }
  return x;
}