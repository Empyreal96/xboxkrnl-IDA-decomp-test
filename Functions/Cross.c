void __stdcall Cross(_D3DVECTOR *a, _D3DVECTOR *b, _D3DVECTOR *pres)
{
  _D3DVECTOR *v3; // ecx
  _D3DVECTOR *v4; // eax

  v3 = b;
  v4 = a;
  pres->x = b->z * a->y - a->z * b->y;
  pres->y = v4->z * v3->x - v4->x * v3->z;
  pres->z = v4->x * v3->y - v3->x * v4->y;
}