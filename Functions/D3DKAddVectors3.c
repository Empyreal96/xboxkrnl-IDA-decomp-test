void __stdcall D3DK::AddVectors3(_D3DVECTOR *out, _D3DVECTOR *v1, _D3DVECTOR *v2)
{
  out->x = v1->x + v2->x;
  out->y = v1->y + v2->y;
  out->z = v1->z + v2->z;
}