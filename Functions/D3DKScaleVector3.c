void __stdcall D3DK::ScaleVector3(_D3DVECTOR *out, _D3DVECTOR *v1, float scale)
{
  out->x = scale * v1->x;
  out->y = scale * v1->y;
  out->z = scale * v1->z;
}