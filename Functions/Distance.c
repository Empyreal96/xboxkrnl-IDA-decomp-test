double __stdcall Distance(_D3DVECTOR *lhs, _D3DVECTOR *rhs)
{
  float x; // ST04_4

  x = Distance2(lhs, rhs);
  return fast_sqrt(x);
}