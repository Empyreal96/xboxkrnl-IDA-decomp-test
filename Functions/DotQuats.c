double __stdcall DotQuats(D3DVECTOR4 *q0, D3DVECTOR4 *q1)
{
  return q0->w * q1->w + q0->z * q1->z + q0->y * q1->y + q0->x * q1->x;
}