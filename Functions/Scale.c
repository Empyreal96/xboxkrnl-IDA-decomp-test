void __stdcall Scale(_D3DVECTOR *pres, float s)
{
  pres->x = s * pres->x;
  pres->y = s * pres->y;
  pres->z = s * pres->z;
}