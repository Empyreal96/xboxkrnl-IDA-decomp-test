void __stdcall Add(_D3DVECTOR *a, _D3DVECTOR *b, _D3DVECTOR *pres)
{
  pres->x = a->x + b->x;
  pres->y = a->y + b->y;
  pres->z = a->z + b->z;
}