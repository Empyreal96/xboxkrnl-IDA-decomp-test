void __stdcall Normalize(_D3DVECTOR *pres)
{
  _D3DVECTOR *v1; // esi
  double v2; // st7

  v1 = pres;
  v2 = 1.0 / Length(pres);
  v1->x = v2 * v1->x;
  v1->y = v2 * v1->y;
  v1->z = v2 * v1->z;
}