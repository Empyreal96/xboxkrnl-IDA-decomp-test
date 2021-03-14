void __stdcall QuickNormalize(_D3DVECTOR *p_vec)
{
  double v1; // st7
  float s; // ST04_4

  v1 = QuickLength(p_vec);
  if ( v1 >= 0.000001 )
  {
    s = 1.0 / v1;
    Scale(p_vec, s);
  }
}