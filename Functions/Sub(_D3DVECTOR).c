void __stdcall Sub(_D3DVECTOR *lhs, _D3DVECTOR *rhs, _D3DVECTOR *pres)
{
  pres->x = lhs->x - rhs->x;
  pres->y = lhs->y - rhs->y;
  pres->z = lhs->z - rhs->z;
}