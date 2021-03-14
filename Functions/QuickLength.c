double __stdcall QuickLength(_D3DVECTOR *vec)
{
  _D3DVECTOR *v1; // eax
  long double v2; // st7
  float t; // ST04_4
  float v4; // eax
  float v5; // ST04_4
  float l; // [esp+0h] [ebp-8h]
  float h; // [esp+10h] [ebp+8h]

  v1 = vec;
  h = fabs(vec->x);
  v2 = fabs(v1->y);
  l = fabs(v1->z);
  if ( v2 > h )
  {
    t = v2;
    v2 = h;
    h = t;
  }
  if ( l > v2 )
  {
    v4 = l;
    l = v2;
    v2 = v4;
  }
  if ( v2 > h )
  {
    v5 = v2;
    v2 = h;
    h = v5;
  }
  return (l * 0.25 + v2 * 0.34375 + h) * 1.0433885;
}