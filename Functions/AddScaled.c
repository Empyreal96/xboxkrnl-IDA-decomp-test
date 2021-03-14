void __stdcall AddScaled(_D3DVECTOR *ptarget, _D3DVECTOR *src, float scale)
{
  ptarget->x = scale * src->x + ptarget->x;
  ptarget->y = scale * src->y + ptarget->y;
  ptarget->z = scale * src->z + ptarget->z;
}