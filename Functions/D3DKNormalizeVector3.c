void __userpurge D3DK::NormalizeVector3(int *a1@<edi>, _D3DVECTOR *v)
{
  _D3DVECTOR *v2; // esi
  float x; // ST04_4
  double v4; // st7
  float invmag; // [esp+10h] [ebp+8h]

  v2 = v;
  x = v->x * v->x + v->y * v->y + v->z * v->z;
  v4 = D3DK::JBInvSqrt(x);
  invmag = v4;
  if ( v4 <= 0.0 )
    D3DK::DXGRIP(a1, "Assertion failure: %s", "invmag > 0");
  v2->x = invmag * v2->x;
  v2->y = invmag * v2->y;
  v2->z = invmag * v2->z;
}