double __stdcall Distance2(_D3DVECTOR *lhs, _D3DVECTOR *rhs)
{
  double v2; // st7
  double v3; // st6
  double v4; // st5

  v2 = lhs->x - rhs->x;
  v3 = lhs->y - rhs->y;
  v4 = lhs->z - rhs->z;
  return v4 * v4 + v3 * v3 + v2 * v2;
}