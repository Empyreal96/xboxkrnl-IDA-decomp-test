double __stdcall Length(_D3DVECTOR *v)
{
  float x; // ST00_4

  x = Length2(v);
  return fast_sqrt(x);
}