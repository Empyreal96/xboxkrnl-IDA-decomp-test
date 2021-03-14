long double __stdcall D3DK::Exp(float e)
{
  double v1; // st7
  long double v4; // st6
  bool v5; // c0
  long double v6; // st6

  v1 = e * 1.442695040888963387;
  _ST6 = v1;
  __asm { frndint }
  v4 = v1 - _ST6;
  v5 = v4 < 0.0;
  v6 = __F2XM1__(fabs(v4)) + 1.0;
  if ( v5 )
    v6 = 1.0 / v6;
  return v6;
}