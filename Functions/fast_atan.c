double __stdcall fast_atan(float x)
{
  float v1; // xmm3_4
  float v2; // xmm4_4
  float v3; // xmm5_4
  float v4; // xmm2_4
  double result; // st7
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( LODWORD(x) >= 0xBF800000 )
  {
    v6 = 1.0 / x;
    v7 = (float)((float)(v6 * v6)
               * (float)(1.0
                       / (float)((float)((float)(1.0
                                               / (float)((float)((float)(1.0
                                                                       / (float)((float)((float)(1.0
                                                                                               / (float)((float)((float)(1.0 / (float)((float)((float)(v6 * v6) * 2.7692308) + 11.0)) * (float)((float)(v6 * v6) * 25.0)) + 9.0))
                                                                                       * (float)((float)(v6 * v6) * 16.0))
                                                                               + 7.0))
                                                               * (float)((float)(v6 * v6) * 9.0))
                                                       + 5.0))
                                       * (float)((float)(v6 * v6) * 4.0))
                               + 3.0)))
       + 1.0;
    result = (float)(-1.5707964
                   - (float)((float)(1.0 / x)
                           * (float)((float)((float)(1.0 / v7) + (float)(1.0 / v7))
                                   - (float)((float)((float)(1.0 / v7) * (float)(1.0 / v7)) * v7))));
  }
  else if ( LODWORD(x) >= 0x3F800000 )
  {
    v8 = 1.0 / x;
    v9 = (float)((float)(v8 * v8)
               * (float)(1.0
                       / (float)((float)((float)(1.0
                                               / (float)((float)((float)(1.0
                                                                       / (float)((float)((float)(1.0
                                                                                               / (float)((float)((float)(1.0 / (float)((float)((float)(v8 * v8) * 2.7692308) + 11.0)) * (float)((float)(v8 * v8) * 25.0)) + 9.0))
                                                                                       * (float)((float)(v8 * v8) * 16.0))
                                                                               + 7.0))
                                                               * (float)((float)(v8 * v8) * 9.0))
                                                       + 5.0))
                                       * (float)((float)(v8 * v8) * 4.0))
                               + 3.0)))
       + 1.0;
    result = (float)(1.5707964
                   - (float)((float)(1.0 / x)
                           * (float)((float)((float)(1.0 / v9) + (float)(1.0 / v9))
                                   - (float)((float)((float)(1.0 / v9) * (float)(1.0 / v9)) * v9))));
  }
  else
  {
    v1 = (float)(x * x) * 16.0;
    v2 = (float)(x * x) * 9.0;
    v3 = (float)(x * x) * 4.0;
    v4 = 1.0
       / (float)((float)((float)(x * x)
                       * (float)(1.0
                               / (float)((float)((float)(1.0
                                                       / (float)((float)((float)(1.0
                                                                               / (float)((float)((float)(1.0 / (float)((float)((float)(x * x) * 2.2727273) + 9.0))
                                                                                               * v1)
                                                                                       + 7.0))
                                                                       * v2)
                                                               + 5.0))
                                               * v3)
                                       + 3.0)))
               + 1.0);
    result = (float)(x
                   * (float)((float)(v4 + v4)
                           - (float)((float)(v4 * v4)
                                   * (float)((float)((float)(x * x)
                                                   * (float)(1.0
                                                           / (float)((float)((float)(1.0
                                                                                   / (float)((float)((float)(1.0 / (float)((float)((float)(1.0 / (float)((float)((float)(x * x) * 2.2727273) + 9.0)) * v1) + 7.0)) * v2)
                                                                                           + 5.0))
                                                                           * v3)
                                                                   + 3.0)))
                                           + 1.0))));
  }
  return result;
}