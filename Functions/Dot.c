double __stdcall Dot(_D3DVECTOR *a, _D3DVECTOR *b)
{
  return a->z * b->z + a->y * b->y + a->x * b->x;
}